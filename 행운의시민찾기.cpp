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

	front = 0; rear = N; // 큐에서 0부터 n-1번째 까지 입력 되어있음. 큐의 초기화 

	while (rear>front) {
		x = k % L;
		k++;
		for (i = 0; i < List[x]-1; i++) { // x-1 번 뒤로 보내는 걸 반복하자. 
			Q[rear] = Q[front];
			rear++;
			front++;  //x번째 있는 Q값 죽임 
		}
		front++;
	}

	printf("%d", Q[rear - 1]);

	return 0;
}