#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 100
#define DELIMIT " "
#define INIT_CAPACITY 3

typedef struct
{
    char* name;
    char* phoneNumber;
    char* email;
    char* groupName;
}Person;

/* 
    개인정보 추가 - 전화번호, email, group 
    파일에 저장 , 읽어오기 가능
*/

char **names;
char **numbers;

Person **persons;
int bookSize = 0;
int useIndex = 0;


void init_bookSize_malloc();
int findName(char* name);
void status();
void bookSize_reAlloc();
void add(char* name , char* number);
void del(char* name);
void save(char* fileName);
void loadFile(char* fileName);
int read_line(char buf[] , int limit);
int read_line_FromFile(FILE *fp,char buf[] , int limit);