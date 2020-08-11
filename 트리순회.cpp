#include<stdio.h>
#include<stdlib.h>

typedef struct BinTreeNode{
	int data;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}TNode;

int N;
TNode* arr[1001];
int Q[1001];

void create_Node(int num){
	TNode *newNode;
	newNode = (TNode*)malloc(sizeof(TNode));
	arr[num] = newNode;
	newNode->left = NULL;
	newNode->right = NULL;
}

void create_Tree(int num, int left_num, int right_num){

	arr[num]->data = num; //num에 해당하는 노드의 주소에 가서 data에 num
	arr[num]->left = arr[left_num];
	arr[num]->right = arr[right_num];
}

void preorder(TNode* n){
	if (n != NULL){
		printf("%d ",n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

void inorder(TNode* n){
	if (n != NULL){
		inorder(n->left);
		printf("%d ", n->data);
		inorder(n->right);
	}
}

void postorder(TNode * n){
	if (n != NULL){
		postorder(n->left);
		postorder(n->right);
		printf("%d ", n->data);
	}
}

void levelorder(TNode *n){
	int rear;
	int front; 
	int x;
	rear = 0;
	front = 0;
	Q[rear] = arr[1]->data;
	rear++;

	while (rear > front){
		x = Q[front];
		printf("%d ", x);
		front++;
		if (arr[x]->left != NULL){
			Q[rear] = arr[x]->left->data;
			rear++;
		}
		if (arr[x]->right != NULL){
			Q[rear] = arr[x]->right->data;
			rear++;
		}
	}
}

int main(){
	
	int i; int a; int b; int c;
	arr[0] = NULL; 
	scanf("%d", &N); 
	for (i = 1; i <= N; i++){
		create_Node(i);
	}

	for (i = 1; i <= N; i++){
		scanf("%d %d %d", &a, &b, &c);
		create_Tree(a, b, c);// a를 b와 c에 연결 
	}
	preorder(arr[1]);
	printf("\n");
	inorder(arr[1]);
	printf("\n");
	postorder(arr[1]);
	printf("\n");
	levelorder(arr[1]);

}