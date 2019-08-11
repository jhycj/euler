#include<stdio.h>
#define INF 50

int Q[1000];
int map[8][8];

void bfs(int sy, int sx){

    int dy[8]={-3, -2, 2, 3, 3, 2, -2, -3};
    int dx[8]={2, 3, 3, 2, -2, -3, -3, -2};
    int i; int j;
    int front; int rear;
    int ty; int tx; int y; int x;

    for(i=1; i<=7; i++){
        for(j=1; j<=7; j++){
            map[i][j] = INF;
        }
    }

    rear =0; front = 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    map[sy][sx] = 0;

    while(rear>front){
        y=Q[front];
        front++;
        x=Q[front];
        front++;
        for(i=0; i<8;i++){
            ty = y+dy[i];
            tx = x+dx[i];
            if(ty>=1 && ty<=7 && tx>=1 && tx<=7 && map[ty][tx]>map[y][x]+1){
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
    int arr[100][2]; //좌표  입력할 배열
    int i; int j; int k; int N; int answer=0;

    scanf("%d", &N);

    for(i=1; i<=N; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }


    for(i=1; i<=N-1; i++){
        bfs(arr[i][0], arr[i][1]);
        answer = answer+ map[arr[i+1][0]][arr[i+1][1]];
    }


    printf("%d", answer );


    return 0;
}
