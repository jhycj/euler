#include<stdio.h>
#define INF 3000
int ey; int ex;
int n; int m;
int flood_map[53][53];
int beaver_map[53][53];
int Q[10000];
int rear;

void flood_bfs(void){

    int x; int y;
    int tx; int ty;
    int i;
    int dy[4]={0, 1, 0, -1};
    int dx[4]={1, 0, -1, 0};
    int front;

    front = 0;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<= n && tx>=1 && tx<=m && (ty!= ey || tx != ex) && flood_map[ty][tx]!=-1 &&
                flood_map[ty][tx]>flood_map[y][x]+1){
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                flood_map[ty][tx] = flood_map[y][x] + 1;
            }
        }
    }
}

void beaver_bfs(int sy, int sx){
    int front;
    int x; int y;
    int tx; int ty;
    int i;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    rear = 0 ;front = 0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    beaver_map[sy][sx] = 0;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && beaver_map[ty][tx]!= -1 && beaver_map[ty][tx]>beaver_map[y][x]+1
            &&flood_map[ty][tx]>beaver_map[y][x]+1){
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                beaver_map[ty][tx] = beaver_map[y][x]+1;
            }
        }
    }
}


int main(){

    char tmp[52];
    int i; int j;
    int sy; int sx;

    rear=0;

    scanf("%d %d", &n, &m);

    for(i=1; i<=n; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=m; j++){
            if(tmp[j]=='.'){
                flood_map[i][j] = INF;
                beaver_map[i][j] = INF;
            }
            else if(tmp[j]=='*'){
                flood_map[i][j] = 0; //홍수 시작 점
                beaver_map[i][j] = 0;
            }
            else if(tmp[j]=='X'){
                flood_map[i][j] = -1; //바위는 절대 못지나감
                beaver_map[i][j] = -1;
            }
            else if(tmp[j]=='D'){
                flood_map[i][j] = INF; //비버의 굴은 못지나감
                beaver_map[i][j] = INF;
                ey = i;
                ex = j;
            }
            else{
                flood_map[i][j] = INF;
                beaver_map[i][j] = INF;
                sy = i;
                sx = j;
            }
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(flood_map[i][j]==0){
                Q[rear] = i;
                rear++;
                Q[rear] = j;
                rear++;
            }
        }
    }

    flood_bfs();
    beaver_bfs(sy, sx);

    /*printf("\n");

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", beaver_map[i][j]);
        }
        printf("\n");
    }*/


    if(beaver_map[ey][ex]== INF){
        beaver_map[ey][ex] = -1;
    }


    printf("%d", beaver_map[ey][ex]);
    /*printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", beaver_map[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}
