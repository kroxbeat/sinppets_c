#include "ribrary.h"

Artist* artist_bucket[26];
SNode* song_bucket[10];
int total_song_count = 0;

//새로운 노래 추가
void add(){
    char buf[BUF_SIZE];
    printf("  Artist: ");
    char* artist = strdup(read_line(buf,BUF_SIZE-1));
    
    printf("  Title: ");
    char* title = strdup(read_line(buf,BUF_SIZE-1));
    
    

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