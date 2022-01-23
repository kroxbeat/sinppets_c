#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 100
#define CAPACITY 100

char *names[CAPACITY];
char *numbers[CAPACITY];
int useIndex = 0;
int delCount = 0;

int findName(char* name){
    for(int i=0; i < useIndex; i++){
        if( strcmp( names[i], name) == 0)
        return i;
    }

    return -1;
}

void status(){
    printf("Total Count is %d\n\n",useIndex - delCount);
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
        names[useIndex] = strdup(buf1);
        numbers[useIndex] = strdup(buf2);

        printf("%s user add Success!\n",buf1);
        useIndex += 1;
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

        names[index] = NULL;
        numbers[index] = NULL;
        printf("%s user del Success!\n",buf1);
        delCount++;
    }
    else
    {
        printf("%s user not exist ! \n",buf1);
    }
}

int main(int argc, char const *argv[])
{
    char command[BUF_SIZE];
    while(1){
        printf("> ");
        scanf("%s", command);

        if( strcmp(command , "add") == 0 )
            add();
        else if( strcmp(command , "status") == 0 )
            status();
        else if( strcmp(command , "del") == 0 )
            del();
        else if( strcmp(command , "exit") == 0 )
            break;
        else
            printf("No command !!\n");
    }
    return 0;
}
