#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	int data; 
	TNode* left;
	TNode* right;


}TNode;

void create_tree(int key, TNode* l, TNode* r){

	TNode* NewNode=(TNode*)malloc(sizeof(TNode));
	NewNode->data = key;
	NewNode->left = l;
	NewNode->right = r;
}

//Ž���Լ� ����� 

TNode* search(TNode* n, int key){ // ��Ʈ��� n���� �����ؼ� key���� ã������ �Ѵ�.

	while (n != NULL){
		if (key == n->data){
			return n;
		}
		else if (key > n->data){
			n = n->right;
		}
		else if (key < n->data){
			n = n->left;
		}
	}
	return NULL;
}

//�����Լ������

int insert(TNode*r, TNode*n){ // r�� ��Ʈ�� �ϴ� ����Ž�� Ʈ���� ��� n�� �����ϴ� �Լ� 


}