#include<stdio.h>
#define INF 3000
int sx; int sy;
int ex; int ey;
int n; int m;
int map[52][52]; 
int Q[10000];

void bfs(int sy, int sx){
	int rear; int front;
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

			if (ty >= 1 && ty <= n && tx >= 1 && tx <= m && map[ty][tx] != -1 && map[ty][tx]> map[y][x] + 1){
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
	char tmp[53]; 

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++){
		scanf("%s", &tmp[1]);
		for (j = 1; j <= m; j++){
			if (tmp[j] == '.'){
				map[i][j] = INF;
			}
			else if (tmp[j] == '+' || tmp[j] =='@'){
				map[i][j] = -1; 
			}
			else if (tmp[j] == '1'){
				map[i][j] = 0;
				sy = i;
				sx = j; 
			}
			else if (tmp[j] == '2'){
				map[i][j] = INF; 
				ey = i;
				ex = j; 
			}
		}
	}

	bfs(sy, sx);

	/*for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/

	if (map[ey][ex] != INF){
		printf("%d", map[ey][ex] - 1);
	}

	else{
		printf("-1");
	}

	return 0;
}
