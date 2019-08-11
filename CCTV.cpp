
#include<stdio.h>


int N; int M; 
int arr[52][52]; int answer; 

void bfs(int sy, int sx) {
	int rear; int front;
	int k; 
	int Q[5002];
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 }; 
	int y; int x; int ty; int tx; 

	rear = 0; front = 0; 
	Q[rear] = sy; 
	rear++;
	Q[rear] = sx; 
	rear++;

	while (front != rear) {
		y = Q[front];
		front++;
		x = Q[front]; 
		front++; 

		arr[y][x] = 0; //visit 했음

		for (k = 0; k < 4; k++) {
			ty = y + dy[k];
			tx = x + dx[k]; 

			if (ty >= 1 && ty <= N && tx >= 1 && tx <= M && arr[ty][tx] == 1) {
				arr[ty][tx] = 0; //visit 했음 
				Q[rear] = ty;
				rear++;
				Q[rear] = tx;
				rear++; 
			}
		}
	}	
}

int main(){
	int i; int j;

	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (arr[i][j] == 1) {
				bfs(i, j); 
				answer++; 
			}
		}
	}

	printf("%d", answer); 

	
	return 0;
}







