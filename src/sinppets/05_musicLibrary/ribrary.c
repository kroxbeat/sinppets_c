#include "ribrary.h"

Artist* artist_bucket[ARTIST_BUCKET_SIZE];
SNode* song_bucket[SONG_BUCKET_SIZE];
int total_song_count = 0;

void status(){
    //모든 노래 데이터 화면출력
    for (int i = 0; i < SONG_BUCKET_SIZE; i++){
        SNode* curr = song_bucket[i];
        if(curr == NULL)
        continue;

        printf("song_bucket index[%d]\n",i);
        while (curr->next != NULL){
            curr = curr->next;
            printf("%d , %s , %s \n",curr->song->index, curr->song->artist->name, curr->song->title);
        }
    }
    
}

//새로운 노래 추가
/*
    1. 가수 이름으로 Artist 노드 존재 확인
    2. - 1번에서 찾은 Artist 노드 하위 SNode 리스트 에서 노래제목으로 찾기 - 없으면 song_bucket 에 노래객체 생성 후 SNode에 노래객체 링크해서 Artist 에 연결 후 마무리
    3. - 1번에서 NULL Artist 노드 - 완전 새로운 가수 , 노래
*/
void add(){
    char buf[BUF_SIZE];
    char buf2[BUF_SIZE];
    printf("  Artist: ");
    read_line(buf,BUF_SIZE-1);
    char* artist = strdup(buf);
    
    printf("  Title: ");
    read_line(buf2,BUF_SIZE-1);
    char* title = strdup(buf2);
    
    //1. 가수 이름으로 된 Artist 노드 존재 확인
    Artist* ptrArtist = findArtistPtrByName(artist);
    // 찾으면 하위에 등록된 노래 인지 확인 후 등록 또는 리턴
    if(ptrArtist != NULL){
        SNode* curr = ptrArtist->head;
            if(curr != NULL){
            //가수의 노래가 존재하면 순회하며 똑같은 제목이 있는지 검사    
                while (curr != NULL){
                    //같은 노래 찾으면 리턴 ( 중복 검사에서 걸림 )
                    if(strcmp(curr->song->title ,title) == 0){
                        printf("이미 등록된 노래 입니다.\n");
                        return;
                    }
                    if(curr->next == NULL)
                        break;
                    curr = curr->next;
                }
            //노래 등록 , 아티스트 연결
            Song* newSong = registNewSong(title);
            newSong->artist = ptrArtist;
            curr->next = (SNode*)malloc(sizeof(SNode));
            curr->next->song = newSong;

            }else{
            //노래가 한곡도 없으니 SNode 리스트 head 를 만들어야 함
            ptrArtist->head = (SNode*)malloc(sizeof(SNode));
            //노래 등록
            Song* newSong = registNewSong(title);
            newSong->artist = ptrArtist;
            ptrArtist->head->song = newSong;
            }
        
    }else{
    //가수가 없을때 새 가수 만들기
    //printf("no singer %s \n",artist);
        ptrArtist = makeNewArtist(artist);
        //노래가 한곡도 없으니 SNode 리스트 head 를 만들어야 함
        ptrArtist->head = (SNode*)malloc(sizeof(SNode));
        //노래 등록
        Song* newSong = registNewSong(title);
        newSong->artist = ptrArtist;
        ptrArtist->head->song = newSong;
        //printf("newSong added %s  %s\n",newSong->artist->name , newSong->title);     
    }
    //printf("added %s \n",title);
}

//새로운 노래를 등록
Song* registNewSong(char* songName){
    int currIndex = ++total_song_count % SONG_BUCKET_SIZE;
    SNode* head = song_bucket[currIndex];
    if(head == NULL){
        song_bucket[currIndex] = (SNode*)malloc(sizeof(SNode));
        //printf("헤드가 없어서 새로 만듬 \n");
    }
    SNode* curr = song_bucket[currIndex];
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = (SNode*)malloc(sizeof(SNode));
    Song* newSong = (Song*)malloc(sizeof(Song));
    newSong->index = total_song_count;
    newSong->title = songName;
    curr->next->song = newSong;
    //printf("newSong added1  %s , %d\n" , newSong->title , newSong->index);
    return newSong;
}

//새로운 Artist 객체 만들어서 리턴
Artist* makeNewArtist(char* artist){
    Artist* newArtist = (Artist*)malloc(sizeof(Artist));
    newArtist->name = artist;
    int artist_bucket_index = artist[0];
    Artist* curr = artist_bucket[artist_bucket_index];
    if(curr == NULL){
        artist_bucket[artist_bucket_index] = newArtist;
        return artist_bucket[artist_bucket_index];
    }else{
        while (curr->next != NULL){
            curr = curr->next;
        }
        return curr;
    }
}

//이름으로 artist_bucket 에서 Artist 노드 찾고 없으면 NULL 리턴
Artist* findArtistPtrByName(char* artist){
    int artist_bucket_index = artist[0];
    Artist* curr = artist_bucket[artist_bucket_index];
    if(curr == NULL){
        return NULL;
    }else{
        while (curr->next != NULL)
        {
            if( strcmp(curr->name, artist) == 0 )
                return curr;
            curr = curr->next;    
        }
        //마지막 노드
        if( strcmp(curr->name, artist) == 0)
            return curr;
        else
            return NULL;
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