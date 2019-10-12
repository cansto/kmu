#include <stdio.h>
#include <malloc.h>
//insert(list, pos, item)
//insert_last(list, item)
//insert_first(list, item)
//delete(list, pos)
//clear(list)
//get_entry(list, pos)
//get_length(list)
//is_empty(list)
//is_full(list)
//print_list(list)
typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}
/*
ListNode* insert_first(ListNode *head, int value){
//삽입
}

ListNode*  insert(ListNode *head, ListNode *pre, element value){

}

ListNode* delete_first(ListNode *head){

}
void print_list(ListNode *head){

}
*/

ListNode* AllocNewNode(element data){
	ListNode* new_node = (ListNode*)malloc(sizeof(listNode));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}


int main(int argc, char* argv[]){
	ListNode *head = NULL;
	
	head = AllocNewNode(data);
	insert(

	return 0;
}
