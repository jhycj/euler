#include<stdio.h>
#define INF 1100000
int X;
int Y;
int N; //¿õµ¢ÀÌ°¹¼ö 
int map[1001][1001];
int sy; int sx;
int ey; int ex;
int Q[2005000]; 

void bfs(int sy, int sx){
	int rear;
	int front;
	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { 1, 0, -1, 0 };
	int i;
	int y; int x;
	int ty; int tx; 

	rear = 0; front = 0;
	Q[rear] = sy;
	rear++;
	Q[rear] = sx;
	rear++;

	map[sy][sx] = 0; 

	while (rear > front){
		y = Q[front];
		front++;
		x = Q[front]; 
		front++;
		for (i = 0; i < 4; i++){
			ty = y + dy[i];
			tx = x + dx[i];

			if (ty >= 0 && ty <= 1000 && tx >= 0 && tx <= 1000 && map[ty][tx]!= -1 && map[ty][tx]>map[y][x] + 1){
				map[ty][tx] = map[y][x] + 1; 
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
	int temp_x;
	int temp_y;

	for (i = 0; i <= 1000; i++){
		for (j = 0; j <= 1000; j++){
			map[i][j] = INF;
		}
	}
	scanf("%d %d %d", &X, &Y, &N); 
	sy = 500;
	sx = 500;
	ey = 500 - Y;
	ex = 500 + X; 
	
	for (i = 0; i < N; i++){
		scanf("%d %d", &temp_x, &temp_y);
		map[500 - temp_y][500 + temp_x] = -1; //¿õµ¢ÀÌ¶ó ¸øÁö³ª°¨ 
	}

	map[sy][sx] = 0;
	
	bfs(sy, sx);
	printf("%d\n", map[ey][ex]);
	return 0;
}