#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
    //파일 저장 , 파일 불러오기 , 이름차순 정렬
*/

#define BUF_SIZE 100
#define CAPACITY 100

char *names[CAPACITY];
char *numbers[CAPACITY];
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

void add(){
    char buf1[CAPACITY] , buf2[CAPACITY];
    
    //name
    scanf("%s", buf1);
    //phone number
    scanf("%s", buf2);
    int index;
    
    if ((index = findName(buf1)) < 0)
    {
        //항상 이름순으로 정렬을 유지하기 위한 로직
        int n = useIndex - 1;
            //이름을 비교 하여 양수가 나올때 까지 index을 하나씩 뒤로 이동
        while(n >= 0 && strcmp(names[n],buf1) > 0){
            names[n+1] = names[n];
            numbers[n+1] = numbers[n];
            n--;
        }
        //반복을 마치면 n+1 index 에 값을 추가 하여 정렬 완성
        names[n+1] = strdup(buf1);
        numbers[n+1] = strdup(buf2);

        printf("%s user add Success!\n",buf1);
        useIndex++;
    }
    else
    {
        printf("%s user already used !  %s  , %s \n ", buf1 ,names[index], numbers[index]);
    }
    
}

void del(){
    char buf1[CAPACITY];

    //name
    scanf("%s", buf1);
    int index;

    if ((index = findName(buf1)) > -1)
    {
        free(names[index]);
        free(numbers[index]);

        names[index] = names[useIndex-1];
        numbers[index] = numbers[useIndex-1];
        useIndex--;

        printf("%s user del Success!\n",buf1);
    }
    else
    {
        printf("%s user not exist ! \n",buf1);
    }
}

void save(){
    char buf1[CAPACITY];
    
    //save FileName
    scanf("%s", buf1);
    FILE *fp = fopen(buf1, "w");
    if(fp == NULL)
        return;

    for (int i = 0; i < useIndex; i++)
    {
        fprintf(fp,"%s %s\n",names[i],numbers[i]);
    }
    fclose(fp);

    printf("%s save complete! \n",buf1);
}

void loadFile(){
    char buf1[CAPACITY];
    
    //load FileName
    scanf("%s", buf1);
    FILE *fp = fopen(buf1, "r");
    if(fp == NULL)
        return;

    int count = 0;
    //더 가져올것이 없을때 까지 반복
    char buf2[CAPACITY];
    char buf3[CAPACITY];
    while (fscanf(fp,"%s",buf2) != EOF)
    {   
        fscanf(fp,"%s",buf3);
        names[count] = strdup(buf2);
        numbers[count] = strdup(buf3);

        count++;
    }
    useIndex = count;
    fclose(fp);

    printf("%s load complete! \n",buf1);
}

int main(int argc, char const *argv[])
{
    char command[BUF_SIZE];
    while(1){
        printf("> ");
        scanf("%s", command);

        if( strcmp(command , "add") == 0 )
            add(); //add kang 4474-7714
        else if( strcmp(command , "status") == 0 )
            status(); //status
        else if( strcmp(command , "del") == 0 )
            del(); // del kang
        else if( strcmp(command , "save") == 0 )
            save(); // save ./phoneBook.txt
        else if( strcmp(command , "load") == 0 )
            loadFile(); // load ./phoneBook.txt
        else if( strcmp(command , "exit") == 0 )
            break;
        else
            printf("No command !!\n");
    }
    return 0;
}
