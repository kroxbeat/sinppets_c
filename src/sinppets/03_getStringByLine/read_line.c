#include <stdio.h>
#include <string.h>

#define BUF_SIZE 100

//버퍼 사이즈를 제한 ,입력을 한줄씩 읽어서 출력

int lead_line(char buf[] , int limit){
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

int main(int argc, char const *argv[])
{
    char buf[BUF_SIZE];
    char * exitStr = "exit()";
    while (1)
    {
        printf("$ ");
        int len = lead_line(buf,BUF_SIZE);
        printf("%s:%d\n",buf,len);
        
        if(!strcmp(buf,exitStr))
            break;
    }
    
    return 0;
}
