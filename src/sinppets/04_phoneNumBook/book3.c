#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
    //명령어 한줄에 입력하여 strtok()으로 자르기
    CAPACITY 크기 를 동적으로 변화 시키기 
*/

#define BUF_SIZE 100
#define DELIMIT " "
#define INIT_CAPACITY 3


char **names;
char **numbers;
int bookSize = 0;
int useIndex = 0;


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

void init_bookSize_malloc()
{
    names = (char**)malloc(sizeof(char*) * INIT_CAPACITY);
    numbers = (char**)malloc(sizeof(char*) * INIT_CAPACITY);
}

int main(int argc, char const *argv[])
{
    init_bookSize_malloc();

    char command_line[BUF_SIZE];
    char *command, *arg1, *arg2;

    while(1){
        printf("> ");
        if(read_line(command_line,99) <= 0)
            continue;
        //command_line DELIMIT 기준으로 나누기
        command = strtok(command_line,DELIMIT);
        //두번째부터를 NULL 을 인자로 넣어줌
        arg1 = strtok(NULL,DELIMIT);
        arg2 = strtok(NULL,DELIMIT);
        
        if( strcmp(command , "add") == 0 ){
            //필수 인자값이 null 일때
            if(arg1 == NULL || arg2 == NULL){
                printf("To add user : add name 12345\n");
                continue;
            }
            add(arg1,arg2); //add kang 4474-7714
        }    
        else if( strcmp(command , "status") == 0 )
            status(); //status
        else if( strcmp(command , "del") == 0 ){
            if (arg1 == NULL)
            {
                printf("To del user : del name\n");
            }
            del(arg1); // del kang
        }
        else if( strcmp(command , "save") == 0 ){
            if (arg1 == NULL)
            {
                printf("To save : save path\n");
            }
            save(arg1); // save ./phoneBook.txt
        }
        else if( strcmp(command , "load") == 0 ){
            if (arg1 == NULL)
            {
                printf("To load file : load path\n");
            }
            loadFile(arg1); // load ./phoneBook.txt
        }
        else if( strcmp(command , "exit") == 0 )
            break;
        else
            printf("No command !!\n");
    }
    return 0;
}
