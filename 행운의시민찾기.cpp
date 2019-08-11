#include<stdio.h>


int N; int L;
int List[10];
int Q[5290000];

int main() {
	int i; int k=0; int x;
	int front; int rear; 

	scanf("%d %d", &N, &L);

	for (i = 0; i < L; i++) {
		scanf("%d", &List[i]);
	}

	for (i = 0; i < N; i++) {
		Q[i] = i+1; 
	}

	front = 0; rear = N; // ť���� 0���� n-1��° ���� �Է� �Ǿ�����. ť�� �ʱ�ȭ 

	while (rear>front) {
		x = k % L;
		k++;
		for (i = 0; i < List[x]-1; i++) { // x-1 �� �ڷ� ������ �� �ݺ�����. 
			Q[rear] = Q[front];
			rear++;
			front++;  //x��° �ִ� Q�� ���� 
		}
		front++;
	}

	printf("%d", Q[rear - 1]);

	return 0;
}