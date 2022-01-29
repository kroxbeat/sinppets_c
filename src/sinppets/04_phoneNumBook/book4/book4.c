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
            if(persons[i] != NULL)
            printf("%s - %s %s %s\n",persons[i]->name,persons[i]->phoneNumber,persons[i]->email,persons[i]->groupName);
        }    
}

void bookSize_reAlloc(){
    printf("bokkSize_reAlloc called %d\n");
    Person** tmp1 = (Person**)malloc(sizeof(Person*) * (INIT_CAPACITY + bookSize));

    printf("bokkSize_reAlloc 1 %d\n");
    for(int i=0; i < bookSize; i++){
       tmp1[i] = persons[i];
    }
    printf("bokkSize_reAlloc 5 %d\n");
    free(persons);        

    persons = tmp1;

    bookSize += INIT_CAPACITY;
    printf("bokkSize_reAlloc done !! size is %d\n",bookSize);
}

void add(char* name){

    int index;
    
    if ((index = findName(name)) < 0)
    {
             printf("use index %d == bookSize %d\n", useIndex,bookSize);
        if(useIndex == bookSize){

            bookSize_reAlloc();
        }

        //항상 이름순으로 정렬을 유지하기 위한 로직
        int n = useIndex - 1;
            //이름을 비교 하여 양수가 나올때 까지 index을 하나씩 뒤로 이동
        while(n >= 0 && strcmp(persons[n]->name,name) > 0){
            persons[n+1] = persons[n];
            n--;
        }
        //반복을 마치면 n+1 index 에 값을 추가 하여 정렬 완성
        persons[n+1] = (Person*)malloc(sizeof(Person));
        persons[n+1]->name = strdup(name);
        
        //추가입력 시작
        char buf[BUF_SIZE];
        //phoneNumber
        printf("input phoneNumber\n>");
        if(read_line(buf,BUF_SIZE-1) > 0)
        persons[n+1]->phoneNumber = strdup(buf);
        //email
        printf("input email\n>");
        if(read_line(buf,BUF_SIZE-1) > 0)
        persons[n+1]->email = strdup(buf);
        //group
        printf("input group\n>");
        if(read_line(buf,BUF_SIZE-1) > 0)
        persons[n+1]->groupName = strdup(buf);

        printf("%s user add Success!\n",name);
        printf("%s - %s %s %s\n",persons[n+1]->name,persons[n+1]->phoneNumber,persons[n+1]->email,persons[n+1]->groupName);
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
