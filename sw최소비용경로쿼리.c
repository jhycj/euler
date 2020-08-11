#define INF 99999
#include<stdio.h>

int T; //Test case 개수 
int H, W, q; //H는 행개수, W는 열개수, q는 질문개수 
unsigned long arr[10001][4];
unsigned long dynamic[10001][4];
unsigned long question[100000][4];
int check[10001][4];
int Q[60000];

void initialize_dynamic(void){
	int i; int j;
	for (i = 1; i <= H; i++){
		for (j = 1; j <= W; j++){
			dynamic[i][j] = INF;
		}
	}

}

void bfs(int sy, int sx, int ey, int ex){
	int rear; 
	int front;
	int i; int j;
	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { 1, 0, -1, 0 };
	int ty, tx; 
	int y, x;

	initialize_dynamic();
	dynamic[sy][sx] = arr[sy][sx]; //다이나믹 초기화 
	
	front = 0;
	rear = 0;
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

			if (ty >= 1 && ty <= H && tx >= 1 && tx <= W  &&
				dynamic[ty][tx]> dynamic[y][x]+arr[ty][tx]){

				dynamic[ty][tx] = dynamic[y][x] + arr[ty][tx];
				Q[rear] = ty;
				rear++;
				Q[rear] = tx; 
				rear++;
			}
		}
	}

}




int main(){
	int k;  int i; int j;
	unsigned long long answer;
	int sy, sx;
	int ey, ex;
	
	scanf("%d", &T);

	for (k = 1; k <= T; k++){
		
		scanf("%d %d %d", &H, &W, &q);
		for (i = 1; i <= H; i++){
			for (j = 1; j <= W; j++){
				scanf("%ld", &arr[i][j]);
			}
		}
		for (i = 0; i < q; i++){
			for (j = 0; j < 4; j++){
				scanf("%d", &question[i][j]);
			}
		}
	
		answer = 0;
		for (i = 0; i < q; i++){
			
			sy = question[i][0];
			sx = question[i][1];
			ey = question[i][2];
			ex = question[i][3];

			bfs(sy, sx, ey, ex); 
			
			answer = answer + dynamic[ey][ex];
						
		}
		printf("#%d %lld\n", k, answer);
	}

	return 0;
}