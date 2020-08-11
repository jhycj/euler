#include<stdio.h>
#define INF 200000
int N; int K; //N은 출발점,  K는 도착점 
int Q[100000];
int time[100001]; 
int dx[3] = { 1, -1, 0 };

void modify_dx(int x);

void bfs(int sx){
	int front; 
	int rear; 
	int x; int tx;
	int i; 
	
	rear = 0; front = 0;

	Q[rear] = sx; 
	rear++;
	time[sx] = 0;

	while (rear>front){
		x = Q[front];
		front++;
		modify_dx(x); //dx = {1, -1, x} 로 바뀜 
	

		for (i = 0; i < 3; i++){
			tx = x + dx[i];
			if (tx >= 0 && tx <= 100000 && time[tx] > time[x]+1){
				Q[rear] = tx; 
				rear++;
				time[tx] = time[x] + 1; 
			}
		}
	}
}

void modify_dx(int x){
	dx[2] = x; 
}

int main(){
	int x;
	int i; 
	scanf("%d %d", &N, &K);
	
	for (i = 0; i <= 100000; i++){
		time[i] = INF;
	}
	time[N] = 0; 

	bfs(N);
	
	printf("%d", time[K]);
	
	return 0;
}