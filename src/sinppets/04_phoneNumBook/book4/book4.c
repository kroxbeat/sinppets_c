#include "book4.h"

int findName(char* name){
    for(int i=0; i < useIndex; i++){
        if( strcmp( names[i], name) == 0)
        return i;
    }

    return -1;
}

void status(){
    printf("Total Count is %d\n\n",useIndex);
    for(int i=0; i < useIndex; i++){
            if(names[i] != NULL)
            printf("%s - %s\n",names[i],numbers[i]);
        }    
}

void bookSize_reAlloc(){
    char** tmp1 = (char**)malloc(sizeof(char*) * (INIT_CAPACITY + bookSize));
    char** tmp2 = (char**)malloc(sizeof(char*) * (INIT_CAPACITY + bookSize));

    for(int i=0; i < bookSize; i++){
       tmp1[i] = names[i];
       tmp2[i] = numbers[i];
    }
    free(names);
    free(numbers);

    names = tmp1;
    numbers = tmp2;

    bookSize += INIT_CAPACITY;
}

void add(char* name , char* number){

    int index;
    
    if ((index = findName(name)) < 0)
    {
        if(useIndex == bookSize){
            bookSize_reAlloc();
        }

        //항상 이름순으로 정렬을 유지하기 위한 로직
        int n = useIndex - 1;
            //이름을 비교 하여 양수가 나올때 까지 index을 하나씩 뒤로 이동
        while(n >= 0 && strcmp(names[n],name) > 0){
            names[n+1] = names[n];
            numbers[n+1] = numbers[n];
            n--;
        }
        //반복을 마치면 n+1 index 에 값을 추가 하여 정렬 완성
        names[n+1] = strdup(name);
        numbers[n+1] = strdup(number);

        printf("%s user add Success!\n",name);
        useIndex++;
    }
    else
    {
        printf("%s user already used !  %s  , %s \n ", name ,names[index], numbers[index]);
    }
    
}

void del(char* name){

    int index;

    if ((index = findName(name)) > -1)
    {
        free(names[index]);
        free(numbers[index]);

        names[index] = names[useIndex-1];
        numbers[index] = numbers[useIndex-1];
        useIndex--;

        printf("%s user del Success!\n",name);
    }
    else
    {
        printf("%s user not exist ! \n",name);
    }
}

void save(char* fileName){
    
    FILE *fp = fopen(fileName, "w");
    if(fp == NULL)
        return;

    for (int i = 0; i < useIndex; i++)
    {
        fprintf(fp,"%s %s\n",names[i],numbers[i]);
    }
    fclose(fp);

    printf("%s save complete! \n",fileName);
}

void loadFile(char* fileName){
    
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL)
        return;

    int count = 0;
    //더 가져올것이 없을때 까지 반복
    char buf2[BUF_SIZE];
    char buf3[BUF_SIZE];
    while (fscanf(fp,"%s",buf2) != EOF)
    {   
        if(count == bookSize){
            bookSize_reAlloc();
        }
        fscanf(fp,"%s",buf3);
        names[count] = strdup(buf2);
        numbers[count] = strdup(buf3);

        count++;
    }
    useIndex = count;
    fclose(fp);

    printf("%s load complete! \n",fileName);
}

//버퍼 사이즈를 제한 ,입력을 한줄씩 읽어서 출력

int read_line(char buf[] , int limit){
    int size = 0;
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if(size < limit){
            buf[size++] = ch;
        }
    }
    buf[size] = '\0';
    return size;
}

//버퍼 사이즈를 제한 , IO스트림 을 인자로 받아서 사용 , 한줄 단위
int read_line_FromFile(FILE *fp,char buf[] , int limit){
    int size = 0;
    char ch;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
    {
        if(size < limit){
            buf[size++] = ch;
        }
    }
    buf[size] = '\0';
    return size;
}

void init_bookSize_malloc()
{
    names = (char**)malloc(sizeof(char*) * INIT_CAPACITY);
    numbers = (char**)malloc(sizeof(char*) * INIT_CAPACITY);
    persons = (Person**)malloc(sizeof(Person*) * INIT_CAPACITY);
}
