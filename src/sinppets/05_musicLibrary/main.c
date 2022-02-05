#include "ribrary.h"

void command_process(){
    while (1)
    {
        char buf[BUF_SIZE];
        printf(">");
        //입력 한줄 읽기
        read_line(buf,BUF_SIZE-1);
        //첫번째 단락
        char* cmd1 = strtok(buf,DELIMIT);
        if (cmd1 == NULL)   
        continue;       

        if(strcmp(cmd1,"add") == 0){
            add();
        }else if(strcmp(cmd1,"status") == 0){
            status();
        }
    }
}
int main(int argc, char const *argv[])
{
    command_process();
    return 0;
}
/* 
    음악 재생 (fake) 프로그램
    
    artist bucket 256개
    단방향 연결 리스트 구성

    song bucket 10개 ( index % )
    모든 song dms SNode 하위 구성으로 양방향 연결 리스트 구성



    >status
    1: 아이유 - 마음을드려요 , /Users//Users/junghyunkang/music/마음을드려요.mp3
    .
    .

    >add
        Artist: 가수 입력
        Title: 노래제목 입력

    >search
        Artist: 가수 입력
        Title: 노래제목 입력
    //status 의 filter  

*/
