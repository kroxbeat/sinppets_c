#include "book4.h"

char **names;
char **numbers;

Person **persons;
int bookSize = INIT_CAPACITY-1;
int useIndex = 0;

int main(int argc, char const *argv[])
{
    init_bookSize_malloc();

    char command_line[BUF_SIZE];
    char *command, *arg1, *arg2;

    while(1){
        printf("> ");
        if(read_line(command_line,BUF_SIZE-1) <= 0)
            continue;
        //command_line DELIMIT 기준으로 나누기
        command = strtok(command_line,DELIMIT);
        //두번째부터를 NULL 을 인자로 넣어줌
        arg1 = strtok(NULL,DELIMIT);
        arg2 = strtok(NULL,DELIMIT);
        
        if( strcmp(command , "add") == 0 ){
            //필수 인자값이 null 일때
            if(arg1 == NULL){
                printf("To add user : add name\n");
                continue;
            }
            add(arg1); //add kang
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