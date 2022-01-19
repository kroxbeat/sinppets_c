#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFileByLineToArray(char list[][512])
{
    FILE *pFile = NULL;
    pFile = fopen("../sample.conf", "r");

    if (pFile != NULL)
    {
        int count = 0;
        char buf[512];
        char* pStr;

        while (1)
        {
            //\n을 만나거나 size 만큼 읽어와서 , buf 에 넣어줌
            // 사실 buf 대신 list[count] 를 직접 넣어도 무방할 때가 있다
            pStr = fgets(buf,sizeof(buf),pFile);
            //파일에서 더이상 읽어올것이 없는지 확인
            if(feof(pFile))
            {
                printf("End File ");
                fclose(pFile);
                break;
            }
            //둘다 가능하지만 memcpy 를 추천 받음
            //strcpy(list[count],pStr);
            memcpy(list[count],pStr,strlen(pStr));
            count++;
        }
        
    }
    
}


int main()
{   
    int size = 10;
    char list[size][512];

    readFileByLineToArray(list);

    for (int i = 0; i < size; i++)
    {
        printf("Num %2d : Msg : %s\n",i,list[i]);
    }
    
    
    return 0;
}