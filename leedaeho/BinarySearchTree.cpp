#include <iostream>
#include<malloc.h>

typedef struct TreeNode {
		int data;
		struct TreeNode *left;
		struct TreeNode *right;
} TreeNode;
void pre_order(TreeNode **node) {
		TreeNode *p = *node;
		printf("%d ", p->data);
		if (p->left != NULL)
			pre_order(&p->left);
		if (p->right != NULL)
			pre_order(&p->right);
}
void insert_node(TreeNode **root, int value){
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		TreeNode *p = *root;

		if (*root == NULL) {
			*root = temp;
			temp->data = value;
			temp->left = NULL;
			temp->right = NULL;
		} else if (*root != NULL) {
			if (value < p->data) 
				insert_node(&p->left, value);
			else 
				insert_node(&p->right, value);
		}
}
int main() {
		TreeNode *root = NULL;
		int i = 0;
		int value = 0;
		while (true) {
			if (i >= 10)
				break;
			scanf("%d", &value);
			insert_node(&root, value);
			i++;
		}
		pre_order(&root);
		printf("\n");
}
