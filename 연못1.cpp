#include<stdio.h>
#define INF 1000
int max;
int min;
int sy;
int sx;
int ey;
int ex;
int n;
int m;
int map[32][32];
int dy[8];
int dx[8];
int Q[2000];

void init_dy(void){
    int rear = 0;

    dy[rear] = max;
    rear++;
    dy[rear] = min;
    rear++;
    dy[rear] = (-1)*min;
    rear++;
    dy[rear] = (-1)*max;
    rear++;
    dy[rear] = (-1)*max;
    rear++;
    dy[rear] = (-1)*min;
    rear++;
    dy[rear] = min;
    rear++;
    dy[rear] = max;
    rear++;
}
void init_dx(void){
    int rear = 0;
    dx[rear] = min;
    rear++;
    dx[rear] = max;
    rear++;
    dx[rear] = max;
    rear++;
    dx[rear] = min;
    rear++;
    dx[rear] = (-1)*min;
    rear++;
    dx[rear] = (-1)*max;
    rear++;
    dx[rear] = (-1)*max;
    rear++;
    dx[rear] = (-1)*min;
    rear++;
}

void bfs(int sy, int sx){
    int front;
    int rear;
    int ty;
    int tx;
    int y;
    int x;
    int i;

    rear=0; front=0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<8; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && map[ty][tx]!=-1 && map[ty][tx]>map[y][x]+1){
                map[ty][tx] = map[y][x]+1;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}

void find_max(int num1, int num2){
    if(num1>num2){
        min = num2;
        max = num1;
    }
    else{
        min = num1;
        max = num2;
    }
}

int main(){
    int M1;
    int M2;
    int i; int j;

    scanf("%d %d %d %d", &n, &m, &M1, &M2);

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==0){ //지날수 없음
                map[i][j] = -1;
            }
            else if(map[i][j]==1){ //연잎이라 지날 수 있음
                map[i][j] = INF;
            }
            else if(map[i][j]==2){
                map[i][j] = -1;
            }
            else if(map[i][j]==3){ //출발지점
                map[i][j] = 0;
                sy = i;
                sx = j;
            }
            else{
                map[i][j] = INF;
                ey = i;
                ex = j;
            }
        }
    }

    find_max(M1, M2);
    init_dx();
    init_dy();

    bfs(sy, sx);

    if(map[ey][ex]!=INF){
        printf("%d", map[ey][ex]);
    }


    /*printf("\n");
    for(i=1; i<=n;i++){
        for(j=1; j<=m; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }*/


    return 0;
}
