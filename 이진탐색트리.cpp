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

//탐색함수 만들기 

TNode* search(TNode* n, int key){ // 루트노드 n부터 시작해서 key값을 찾으려고 한다.

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

//삽입함수만들기

int insert(TNode*r, TNode*n){ // r을 루트로 하는 이진탐색 트리에 노드 n을 삽입하는 함수 


}