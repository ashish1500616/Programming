#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int data) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void Inorder(struct Node *t) {
	if (t) {
		Inorder(t->left);
		printf("%d  ", t->data);
		Inorder(t->right);
	}
}

int main() {
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printf("Data in Inorder Traversal\n");
	Inorder(root);
	printf("\n");
	return 0;
}
