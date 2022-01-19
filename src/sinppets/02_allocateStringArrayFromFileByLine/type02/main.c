#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFileByLineToArray(char** list)
{
    FILE *pFile = NULL;
    pFile = fopen("../sample.conf", "r");

    if (pFile != NULL)
    {
        int count = 0;
        while (1)
        {
            fgets(*(list + count),512,pFile);
            //파일에서 더이상 읽어올것이 없는지 확인
            if(feof(pFile))
            {
                printf("End File ");
                fclose(pFile);
                break;
            }
            count++;
        }
        
    }
    
}


int main()
{   
    int size = 10;
    char** list = (char**)malloc(sizeof(char*) * size);
    for(int i=0; i < size; i++)
    {
        *(list + i) = (char*)malloc(sizeof(char) * 512);
    }

    readFileByLineToArray(list);

    for (int i = 0; i < size; i++)
    {
        printf("Num %2d : Msg : %s\n",i,*(list + i));
        free(*(list + i));
    }
    free(list);
    
    return 0;
}