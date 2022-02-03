#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    struct node* next;
    char* data;    
}Node;

void printLinkedList(Node* head){
    int count = 0;
    while (head->next != NULL)
    {
        printf("data : %s ,count : %d \n",head->data, count++);
        head = head->next;
    }
        printf("data : %s ,count : %d \n",head->data, count++);
    
}

Node* findPreNodeByDataValue(Node* head,char* data){
    while (head->next != NULL )
    {
        if(strcmp((head->next)->data, data) == 0)
            return head;
        
        head = head->next;
    }
    if(strcmp((head->next)->data, data) == 0)
        return head;
    return NULL;    
}

int main(int argc, char const *argv[])
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = strdup("head");

    Node* q = (Node*)malloc(sizeof(Node));
    head->next = q;
    q->data = strdup("1st");
    q->next = NULL;

    Node* q2 = (Node*)malloc(sizeof(Node));
    q->next = q2;
    q2->data = strdup("2st");
    q2->next = NULL;

    printLinkedList(head);
    printf("\n");

    //1st 노드 앞에 0st 노드 추가
    //1st 값을 가지는 노드 찾기 . 없으면 NULL 반환
    Node* findNode = findPreNodeByDataValue(head, "1st");
    if(findNode != NULL){
        //q 재활용 가능
        q = (Node*)malloc(sizeof(Node));
        q->data = strdup("0st");

        q->next = findNode->next;
        findNode->next = q;
    }
    
    printLinkedList(head);
    return 0;
}
