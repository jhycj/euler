#include<stdio.h>
#include<stdlib.h>

typedef char TElement;

typedef struct BinTrNode{

	TElement data;
	struct BinTrNode* left; 
	struct BinTrNode* right;
} TNode;

TNode * root;

void init_tree(){
	root = NULL; //공집합 
}

int is_empty_tree(){
	return root == NULL;
}

TNode* create_tree(TElement value, TNode * l, TNode* r){
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = value;
	n->left = l;
	n->right = r;
	return n;
}

void main(){
	TNode *b, *c, *d, *e, *f;

	init_tree(); //root를 Null로 만든다.

	d = create_tree('D', NULL, NULL);
	e = create_tree('E', NULL, NULL);
	b = create_tree('B', d, e);

}
