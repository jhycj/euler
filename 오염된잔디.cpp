#include<stdio.h>

int n; int m;
int arr[1002][1002];
int Q[2000000];
void bfs(int sy, int sx){

    int front; int rear;
    int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
    int dx[8]={1, 1, 0, -1, -1, -1, 0, 1};
    int i; int j;
    int y; int x; int ty; int tx;

    front=0; rear=0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;
        arr[y][x] = -1; //잔디 없음으로 바꿈
        for(i=0; i<8; i++){
            ty = y+dy[i];
            tx = x+dx[i];
            if(ty>=1 && ty<=n && tx>=1 && tx<=m && arr[ty][tx]>0){
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                arr[ty][tx] = -1;
            }
        }
    }
}
int main(){
    int i; int j;
    int count=0;
    scanf("%d %d",&n, &m);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j]>0){
                bfs(i, j);
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
