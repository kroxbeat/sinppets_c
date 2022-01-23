#include <stdio.h>
#include <string.h>

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
    for(int i=0; i < useIndex; i++){
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

        


    }
    return 0;
}
