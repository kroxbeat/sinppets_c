#ifndef __RIBRARY_H__
#define __RIBRARY_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DELIMIT " "
#define ARTIST_BUCKET_SIZE 256
#define SONG_BUCKET_SIZE 10
#define BUF_SIZE 100

typedef struct artist Artist;
typedef struct snode SNode;
typedef struct song Song;

extern Artist** artist_bucket;
extern SNode** song_bucket;
extern int total_song_count;

struct artist
{   
    char* name;
    Artist* next;
    SNode* head;
    SNode* tail;
};

struct snode
{
    SNode* next;
    SNode* prev;
    Song* song;
};

struct song
{
    Artist* artist;
    char* title;
    char* path;
    int index;
};

void status();
void command_process();
int read_line(char buf[] , int limit);
int read_line_FromFile(FILE *fp,char buf[] , int limit);
void add();
Artist* findArtistPtrByName(char* name);
Song* registNewSong(char* songName);
Artist* makeNewArtist(char* artist);
void search();
Song* findSongByIndex(int musicIndex);
void play(int musicindex);
void init();

#endif