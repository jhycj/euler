#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data; //������ �ʵ� 
	NODE* link; //��ũ�ʵ� 

}NODE;
NODE *top = NULL;

int is_empty(void){
	if (top == NULL){
		return 0; 
	}
	else{
		return 1; 
	}
}

void init_stack(void){ //������ �ʱ�ȭ 
	top = NULL; 
}

void push(int e){
	NODE* p = (NODE*)malloc(sizeof(NODE)); 
	p->link = top; 
	p->data = e;
	top = p; 
}

int pop(void){
	int e;

	is_empty();
	if (is_empty == 0){
		printf("���� �����");
	}

	else{
		NODE* p = (NODE*)malloc(sizeof(NODE*));
		p = top;

		top = p->link;
		e = p->data;
		free(p);
		return e;
	}
}

int size(void){
	NODE* p;
	int count;


	for (p = top; p != NULL; p = p->link){
		count++;
	}
	return count; 
}

int main(){
	


	return 0;

}

