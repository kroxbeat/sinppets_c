#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int main(){
    int arraySize, n = 0, l = 0; 

	printf("typetotalSize\n");
 	scanf("%d",&arraySize);
	printf("TotalSize %d \n",arraySize);    

    char * names[arraySize];
    char buffer[30]; 

    while ( n < arraySize ) {
        scanf("%s", buffer);
        // 버퍼에 문자열을 입력받은 후, 그 길이 만큼 새 문자열을 위한 메모리를 할당한다.
        // 새로 할당된 메모리에 버퍼의 내용을 복사하고, 그 시작 위치를 배열에 추가한다.
        l = strlen(buffer);
        if (l > 0){
            char* newstrptr = (char*)malloc(sizeof(char) * (l + 1));
            strcpy(newstrptr, buffer);
            names[n] =  newstrptr;
            n++;
        } else {
            break;
        }
    }

    // 배열의 각 원소를 순회하면서, 해당 값의 메모리 번지에서 시작되는
    // 문자열을 출력한다. 출력한 후에는 해당 메모리를 해제하여 파괴한다.
    for(n = 0; n < arraySize; n++){
        printf("%02d: %s\n", n, names[n]);
        free(names[n]);
    }
    return 0;
}
