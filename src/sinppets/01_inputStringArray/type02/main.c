#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMsg(char* preFix,char* msg){
	printf("%s - %s\n",preFix,msg);
}

int getTotalSize(){
	int size;
	printMsg("type","totalSize");
	scanf("%d",&size);
	printf("TotalSize %d \n",size);
	return size;
}

void getStringsFromUser(char **array, int size){
	for(int i=0; i < size; i++){
		char buf[100];

		printf("type Msg %d \n",i);
		
		scanf("%s", buf);

		int strSize = strlen(buf);
		array[i] = (char*)malloc(sizeof(char) * strSize + 1);
		strcpy(array[i],buf);
		printf("copy data %s  size %d\n",array[i],strSize);
		
	}
}

void printData(char **array, int size){
	for(int i=0; i < size; i++){
		printf("%d st msg - %s\n",i ,array[i]);
		free(array[i]);	
	}
}

int main(){
	//프로그램 시작
	printMsg("program","start");
	//배열 총 사이즈 입력받기
	int totalSize = getTotalSize();
	char **datas = (char**)malloc(sizeof(char*) * totalSize);
	
	//데이터 입력 받기
	getStringsFromUser(datas, totalSize);

	//입력 받은 데이터 화면 출력
	printData(datas, totalSize);
	free(datas);
    return 0;
}





