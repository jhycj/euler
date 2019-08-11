#include<stdio.h>
#define INF 5000
int ey;
int ex;
int map[52][52];
int n; int m;
int Q[100000];
int rear;

void bfs(int sy, int sx){
    int x; int y;
    int tx; int ty;
    int i;
    int dy[4]={0, 1, 0, -1};
    int dx[4]={1, 0, -1, 0};
    int front;

    rear = 0; front = 0 ;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;
    map[sy][sx] = 0;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && map[ty][tx]!=-1 && map[ty][tx]<=map[y][x]+1){
                map[ty][tx] = -1;
            }

            else if(ty>=1 && ty<=n && tx>=1 && tx<=m && map[ty][tx]!=-1 && map[ty][tx]>map[y][x]+1){
                map[ty][tx] = map[y][x] +1 ;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }




        }
    }
}

void bfs_flood(void){
    int x; int y;
    int tx; int ty;
    int i;
    int dy[4]={0, 1, 0, -1};
    int dx[4]={1, 0, -1, 0};
    int front;

    front = 0;

    while(rear>front){
        y=Q[front];
        front++;
        x=Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<= n && tx>=1 && tx<= m && map[ty][tx] != -1 && map[ty][tx]>map[y][x]+1){
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
    char tmp[52];
    int i; int j;
    int count = 0;
    int sy; int sx;

    rear=0;

    scanf("%d %d", &n, &m);

    for(i=1; i<=n; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=m; j++){
            if(tmp[j]=='.'){
                map[i][j] = INF;
            }
            else if(tmp[j]=='*'){
                map[i][j] = 0; //홍수 시작 점
            }
            else if(tmp[j]=='X'){
                map[i][j] = -1; //바위는 절대 못지나감
            }
            else if(tmp[j]=='D'){
                map[i][j] = INF; //비버의 굴은 못지나감
                ey = i;
                ex = j;
            }
            else{
                map[i][j] = INF;
                sy = i;
                sx = j;
            }
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(map[i][j] == 0){
                Q[rear]=i;
                rear++;
                Q[rear]=j;
                rear++;
            }
        }
    }

    bfs_flood();
    printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    bfs(sy, sx);
    printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    printf("%d", map[ey][ex]);
    return 0;
}
