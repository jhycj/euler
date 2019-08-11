#include<stdio.h>
#define INF m*n;

int m; int n;
int map[101][101];
int Q[20000];

void bfs(int sy, int sx){
    int i; int ty; int tx; int y; int x;
    int dy[4]={0, 1, 0, -1};
    int dx[4]={1, 0, -1, 0};
    int front; int rear;

    front =0; rear=0;

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

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && map[ty][tx]> map[y][x]+1){
                map[ty][tx] = map[y][x]+1;
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
    char tmp[102]; int sy; int sx; int ey; int ex;

    scanf("%d %d", &n, &m); //세로 가로

    for(i=1; i<=n; i++){
        scanf("%s", &tmp[1]);

        for(j=1; j<=m; j++){
            if(tmp[j]=='*'){
                map[i][j] = -1;
            }
            else if(tmp[j]=='.'){
                map[i][j] = INF;
            }
            else if(tmp[j]=='C'){
                map[i][j] = INF;
                sy = i;
                sx = j;
            }
            else if(tmp[j]=='B'){
                map[i][j] = INF;
                ey = i;
                ex = j;
            }
        }
    }

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }*/
    bfs(sy, sx);

    printf("%d", map[ey][ex]);

    return 0;
}
