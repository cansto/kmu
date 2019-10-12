#include <stdio.h>
#include <malloc.h>
typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

void PrintListData(const char* str, ListNode* node){
	printf("%s%d\n", str, node->data);
}
ListNode* GetNewNode(element data){
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}
void Assign(ListNode** node1, ListNode** node2){
	*node1 = *node2;
}
int main(){
	ListNode *list1 = (ListNode*)malloc(sizeof(ListNode));
	list1->data = 100;
	PrintListData("list1->data = ", list1);

	ListNode *list2 = GetNewNode(1);
	PrintListData("list2->data = ", list2);

	ListNode *p = NULL;
	//p = list2;//list2에 할당된 ListNode* 타입 주소를 p에 할당
	Assign(&p, &list2);
	p->data = 10;
	PrintListData("list2->data = ", list2);

	free(list1);
	free(list2);
	return 0;

}
