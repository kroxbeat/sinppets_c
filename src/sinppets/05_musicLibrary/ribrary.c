#include "ribrary.h"

Artist* artist_bucket[256];
SNode* song_bucket[10];
int total_song_count = 0;


//새로운 노래 추가
void add(){
    char buf[BUF_SIZE];
    char buf2[BUF_SIZE];
    printf("  Artist: ");
    read_line(buf,BUF_SIZE-1);
    char* artist = strdup(buf);
    
    printf("  Title: ");
    read_line(buf,BUF_SIZE-1);
    char* title = strdup(buf2);
    
    int artist_bucket_index = artist[0];
    int song_bucket_index = ++total_song_count % 10;

    //아티스트 추가
    if(artist_bucket[artist_bucket_index] == NULL){
        //첫 추가 이면 헤드 생성
        //여기구현중 artist_bucket[artist_bucket_index] = (Artist*)malloc(sizeof(Artist*));
    }

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