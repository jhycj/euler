#include<stdio.h>
char arr[102][102];
int Q[20810];

void bfs(int sy, int sx){
    int i;
    int x; int y;//탐색중인 좌표
    int tx; int ty;//탐색하면서 움직이는 좌표
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int rear; int front;

    rear = 0; front = 0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(front!=rear){
        y = Q[front];
        front++;
        x = Q[front];
        front++;
        arr[y][x] = '.'; //visit 함
        for(i=0; i<8;i++){
            ty = y+dy[i];
            tx = x+dx[i];
            if(ty>=1 && ty<=100 && tx>=1 && tx<=100 && arr[ty][tx] =='W'){
                arr[ty][tx] = '.'; //visit 함
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}

int main(){
    int answer=0;
    int n; int m;
    int i; int j;

    scanf("%d %d", &n, &m);

    for(i=1; i<=n;i++){
        scanf("%s", &arr[i][1]);
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j]=='W'){
                bfs(i, j);
                answer++;
            }
        }
    }
    printf("%d", answer);
    return 0;
}
