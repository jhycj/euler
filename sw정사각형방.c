#include<stdio.h>
#include<stdlib.h>


int num_test_case;
int N;
int room[1001][1001];
int answer[1001][1001]; 
int *Q;

int bfs(int sy, int sx){
	int i, j; 
	int ty, tx;
	int rear; int front;
	int dy[4] = { 0, 1, 0, -1 }; 
	int dx[4] = { 1, 0, -1, 0 };
	int count;
	int y; int x;

	count = 1;
	rear = 0; front = 0; 

	Q[rear] = sy;
	rear++;
	Q[rear] = sx;
	rear++;

	while (rear > front){
		y = Q[front];
		front++;
		x = Q[front];
		front++;

		for (i = 0; i < 4; i++){
			ty = y + dy[i];
			tx = x + dx[i];

			if (ty >= 1 && ty <= N && tx >= 1 && tx <= N && room[ty][tx] == room[y][x] + 1){
				Q[rear] = ty; 
				rear++;
				Q[rear] = tx;
				rear++;
				count++;
			}
		}
	}
	return count;
}





int main(){
	int i, j, k;
	int answer1;
	int answer2;

	scanf("%d", &num_test_case);

	for (k = 1; k <= num_test_case; k++){
		answer1 = 1001;
		answer2 = 0;

		scanf("%d", &N); // 1<= N<= 1000
		Q = (int*)malloc(sizeof(int)* N * N * 2);

		for (i = 1; i <= N; i++){
			for (j = 1; j <= N; j++){
				scanf("%d", &room[i][j]);
			}
		}

		for (i = 1; i <= N; i++){
			for (j = 1; j <= N; j++){
				answer[i][j] = bfs(i, j);
				if (answer2 < answer[i][j]){
					answer2 = answer[i][j];
					answer1 = room[i][j];
				}
				else if (answer2 == answer[i][j]){
					if (answer1 > room[i][j]){
						answer2 = answer[i][j];
						answer1 = room[i][j];
					}
				}
			}
		}

		printf("#%d %d %d\n",k,answer1, answer2);
		

	}

	
	
	return 0;

}