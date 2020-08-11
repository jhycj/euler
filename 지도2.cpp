#include<stdio.h>
#define INF 3000
int map[51][51];
int dynamic[51][51]; 
int visit[51][51];
int path[3][51][51]; 
int sx; int sy;
int ex; int ey;
int n; 
int Q[5000];
int min_y;
int min_x;
int how;
int answerQ[5000];


void get_min(void){
	int i; int j;
	int min; 
	min = INF;
	min_y = 0;
	min_x = 0; 

	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			if (visit[i][j]==0 && map[i][j]>0 &&  min > dynamic[i][j]){
				min = dynamic[i][j];
				min_y = i;
				min_x = j;
			}
		}
	}
}


void bfs(int sy, int sx){

	int i;
	int ty; int tx;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int x; int y;
	int front; int rear; 

	rear = 0; front = 0;
	Q[rear] = sy;
	rear++;
	Q[rear] = sx;
	rear++;
	dynamic[sy][sx] = map[sy][sx];

	path[2][sy][sx] = 1; 

	while (how==0){
		y = Q[front];
		front++;
		x = Q[front]; 
		front++;

		visit[y][x] = 1; //방문함 
		
		for (i = 0; i < 4; i++){
			ty = y + dy[i];
			tx = x + dx[i];

			if (ty >= 1 && ty <= n && tx >= 1 && tx <= n && map[ty][tx]>0){
				if (visit[ty][tx] == 0 && dynamic[ty][tx] >dynamic[y][x] + map[ty][tx]){
					dynamic[ty][tx] = dynamic[y][x] + map[ty][tx];
					path[0][ty][tx] = y;
					path[1][ty][tx] = x;
					path[2][ty][tx] = path[2][y][x] + 1;
				}
			}
		}

		get_min(); 

		if (min_y == 0 && min_x == 0){
			how = 1;
		}
		else{
			Q[rear] = min_y;
			rear++;
			Q[rear] = min_x;
			rear++;
		}
	}
}
void get_answer(void){
	int rear = 0 ; 
	int front = 0;
	int i; 
	int N = path[2][ey][ex];
	int y; int x; 
	printf("%d\n", N);

	answerQ[rear] = ey;
	rear++;
	answerQ[rear] = ex;
	rear++;

	for(i=1; i<=N-1; i++){
		y = answerQ[front]; 
		front++;
		x = answerQ[front];
		front++; 
		
		answerQ[rear] = path[0][y][x];
		rear++;
		answerQ[rear] = path[1][y][x];
		rear++;
	}
	for (i = 1; i <= rear-1; i=i+2){
		printf("%d %d", answerQ[rear - i], answerQ[rear-i-1]);
		printf("\n");
	}
}

int main(){
	int i; int j;
	int path_rear;

	path_rear = 0;

	scanf("%d", &n); //지도의 행 입력 받기 
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			scanf("%d", &map[i][j]);
			if (map[i][j] > 0){//이동 가능한 점 
				dynamic[i][j] = INF;
			}
			else if (map[i][j] = 0){ //이동 불가능한 점
				map[i][j] = -1; 
				visit[i][j] = 1; 
			}
		}
	}

	scanf("%d %d", &sx, &sy);
	scanf("%d %d", &ex, &ey);

	bfs(sy, sx);

	if (dynamic[ey][ex] == INF){
		printf("-1");
	}
	else{
		get_answer();
	}
	return 0;
}