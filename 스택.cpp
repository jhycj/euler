#include<stdio.h>
#define MAX_SIZE 10
int Q[MAX_SIZE];
int rear = 0;

int is_full(void){
	if (rear == MAX_SIZE){
		return 1;
	}
	else{
		return 0;
	}
}

int is_empty(void){
	if (rear == 0){
		return 1;
	}
	else{
		return 0; 
	}
}


void push(int value){
	int x; 
	x=is_full();
	if (x == 0){
		Q[rear] = value;
		rear++;
	}
}

void pop(void){
	int x;
	x = is_empty();
	if (x == 0){
		rear--;
	}
}

void stack(int x, int value){

	if (x == 1){
		push(value);
	}
	if (x == 2){
		pop();
	}
}

int main(){
	int N;//스택 크기 
	int input[100][2];
	int tmp;
	int i;
	int count=0;
	scanf("%d", &N);
	for (i = 0; i < 100; i++){
		scanf("%d", &tmp);
		if (tmp == 0){
			break;
		}
		else if (tmp == 1){
			input[count][0] = 1;
			scanf("%d", &input[count][1]);
		}
		else if (tmp == 2){
			input[count][0] = 2; 
		}
	}



}