#include <stdio.h>
#include <malloc.h>
#include <queue>
using namespace std;

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;
typedef struct Tree{
	Node* root;
	Node* tail;
	int size;
	int count;
	int summ;
}Tree;

Tree* g_tree;

void InitTree(Node* root, Node* tail, int size){
	g_tree = (Tree*)malloc(sizeof(Tree));
	g_tree->root = root;
	g_tree->tail = tail;
	g_tree->size = size;
	g_tree->count = 0;
	g_tree->summ = 0;
}
Node* AllocNewNode(int data, Node* left, Node* right){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = left;
	new_node->right = right;
	return new_node;
}
Node* make_tree(){
	Node* node4 = AllocNewNode(4, NULL, NULL);
	Node* node2 = AllocNewNode(2, node4, NULL);
	Node* node7 = AllocNewNode(7, NULL, NULL);
	Node* node6 = AllocNewNode(6, NULL, NULL);
	Node* node5 = AllocNewNode(5, node7, NULL);
	Node* node3 = AllocNewNode(3, node5, node6);
	Node* root = AllocNewNode(1, node2, node3);
	InitTree(root, node6, 7);//전위순회 기준 node6을 tail지정//사용은 x
	return root;
}

void level_order(Node* node){
	printf("[Level order] ");
	queue<Node*> q;
	
	if(node == NULL) return;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();//큐의 front값을 삭제, 리턴값 없음
		printf("%d ", node->data);
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
	printf("\n");
}
void pre_order(Node* node){
	if(g_tree->count==0)
		printf("[Pre order] ");
	if(node != NULL){
		g_tree->count++;
		printf("%d ",node->data);
		if(node->left)
			pre_order(node->left);
		if(node->right)
			pre_order(node->right);
	}
	if(g_tree->count==g_tree->size){
		printf("\n");
		g_tree->count = 0;
	}
}
void find_leafnodes(Node* node){
	if(g_tree->count == 0)
		printf("[Leaf nodes] ");
	if(node != NULL){
		g_tree->count++;
		if(node->left==NULL && node->right==NULL)
			printf("%d ",node->data);
		if(node->left)
			find_leafnodes(node->left);
		if(node->right)
			find_leafnodes(node->right);
	}	
	if(g_tree->count == g_tree->size){
		printf("\n");
		g_tree->count = 0;
	}
}
void sum(Node* node){
	if(g_tree->count == 0)
		printf("[Sum] ");
	if(node != NULL){
		g_tree->count++;
		g_tree->summ = g_tree->summ+node->data;
		if(g_tree->count == g_tree->size)
			printf("%d\n", g_tree->summ);
		sum(node->left);
		sum(node->right);
	}
}

int main(void){
	Node *root = make_tree();
	level_order(root);
	pre_order(root);
	find_leafnodes(root);
	sum(root);
	return 0;
}
