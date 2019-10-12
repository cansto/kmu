#include <stdio.h>
#include <malloc.h>
typedef struct Node{
	int value;
	Node* next;
}Node;
Node* AllocNewNode(int value){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}
void DisplayList(Node** head){
	Node* curr = NULL;
	printf("List = ");
	if(*head == NULL)
		printf("Empty");
	else{
		for(curr = *head ; curr != NULL ; curr=curr->next){
			printf("%d ", curr->value);	
		}
	}
	printf("\n\n");
}
void AddList(Node** head){
	int value = 0;
	printf("등록원소) ");
	scanf("%d", &value);
	Node* new_node = AllocNewNode(value);
	if(*head == NULL)
		*head = new_node;
	else{
		Node* curr = *head;
		while(1){
			if(curr->next == NULL){
				curr->next = new_node;
				break;
			}
			curr = curr->next;
		}
	}
	DisplayList(head);
}
void RemoveList(Node** head){
	int delValue;
	printf("원소삭제) ");
	scanf("%d", &delValue);
	Node* curr = NULL;
	Node* prev = NULL;
	for(curr = *head ; curr!= NULL ; curr=curr->next){
		if(curr->value == delValue){
			if(curr == *head)
				*head = curr->next;
			else
				prev->next = curr->next;
			free(curr);
			break;
		}
		prev = curr;//이전 노드 기억
	}
	DisplayList(head);
}
void FindList(Node** head){
	int findValue;
	printf("원소검색) ");
	scanf("%d", &findValue);
	Node* curr = NULL;
	for(curr = *head ; curr != NULL ; curr=curr->next){
		if(curr->value == findValue){
			printf("존재함\n");
			break;
		}
	}
	if(curr == NULL)
		printf("존재하지 않음\n");
	printf("\n");
}
void GetSize(Node** head){
	int listSize = 0;
	printf("원소 개수\n");
	Node* curr = NULL;
	for(curr = *head ; curr != NULL ; curr=curr->next){
		listSize++;	
	}
	if(listSize>0)
		printf("%d개 있음\n\n", listSize);
	else
		printf("존재하지 않음\n\n");
}
void FreeList(Node** head){
	Node* curr = NULL;
	for(curr = *head ; curr != NULL ; curr=curr->next){
		free(curr);
	}
}
void PrintMenu(){
	printf("메뉴)\n");
	printf("1. 원소 등록 \n");
	printf("2. 원소 삭제 \n");
	printf("3. 원소 내역 \n");
	printf("4. 원소 검색 \n");
	printf("5. 원소 개수 \n");
	printf("6. 종료 \n");
	printf("입력) ");
}
int main(){
	Node* head = NULL;
	int input = 0, loop = 1;

	while(loop){
		PrintMenu();
		scanf("%d", &input);
		switch(input){
			case 1: AddList(&head); break;
			case 2: RemoveList(&head); break;
			case 3: DisplayList(&head); break;
			case 4: FindList(&head); break;
			case 5: GetSize(&head); break;
			case 6: loop = 0; break;
			default: printf("Wrong input..\n");
		}
	}
	FreeList(&head);
	return 0;
}
