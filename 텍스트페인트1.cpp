#include<stdio.h>

int main(){
    int i; int j;
    int m; int n; //행이 n, 열이 ㅡ
    int sx; int sy;
    int x; int y; //현재 탐색중인 x, y 좌표
    int tx; int ty; //4방향 움직이는 x, y좌표
    int arr[105][105]={0,};
    char tmp[20]; //행마다 입력 받으면 넣을 공간
    int Q[20005];
    int rear; int front;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int answer = 0;

    scanf("%d %d %d %d", &n, &m, &sy, &sx);
    for(i=1; i<=n; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=m; j++){
            if(tmp[j]=='#'){
                arr[i][j] = 1;
            }
        }
    }

    rear = 0; front=0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++; //큐의 초기화

    arr[sy][sx] = 2;
    answer++;

    while(front!=rear){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y + dy[i];
            tx = x + dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && arr[ty][tx] == 0){
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                arr[ty][tx] = 2;
                answer++; //물감 칠함 or 방문했음..
            }
        }
    }

    printf("%d", answer);

}
