#define INF 900000
#include<stdio.h>

int n;
int m;
int sy;
int sx;
int ey;
int ex;
int map[305][305];
int dynamic[305][305];
int visit[305][305];
int Q[180005];
// 269
void bfs(int sy, int sx){
    int rear=0;
    int front=0;
    int ty; int tx;
    int y; int x;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int i;

    Q[rear++] = sy;
    Q[rear++] = sx;


    while(front<rear){
        y = Q[front++];
        x = Q[front++];

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(visit[ty][tx]!= -1 && map[ty][tx]!= -1 && ty>=1 && ty<= n && tx>=1 && tx<= m &&
                dynamic[ty][tx]> dynamic[y][x]+map[ty][tx]){

                dynamic[ty][tx] = dynamic[y][x] + map[ty][tx];
                Q[rear++] = ty;
                Q[rear++] = tx;
                visit[y][x] = -1;
            }
        }
    }
}

int main(){

    int i; int j;
    char tmp[302];
    scanf("%d %d", &n, &m);

    for(i=1; i<=n; i++){
        scanf("%s", &tmp[0]);
        for(j=0; j<m; j++){
            if(tmp[j]=='Y'){ //시작점
                sy = i;
                sx = j+1;
                map[i][j+1] = 1;
                dynamic[i][j+1] = 0;
            }
            else if(tmp[j] == 'T'){//도착지점
                ey = i;
                ex = j+1;
                map[i][j+1] = 1;
                dynamic[i][j+1] = INF;
            }
            else if (tmp[j] == 'S'){//철벽
                map[i][j+1] = -1;
                dynamic[i][j+1] = INF;
            }
            else if(tmp[j] == 'B'){//벽돌벽
                map[i][j+1] = 2;
                dynamic[i][j+1] = INF;
            }
            else if(tmp[j] == 'R'){//강
                map[i][j+1] = -1;
                dynamic[i][j+1] = INF;
            }
            else if(tmp[j] == 'E'){
                map[i][j+1]= 1;
                dynamic[i][j+1] = INF;
            }
        }
    }

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            dynamic[i][j] = INF;
        }
    }
    dynamic[sy][sx] = 0;*/

    bfs(sy, sx);

    if(dynamic[ey][ex]==INF){
        printf("-1");
    }
    else{
        printf("%d", dynamic[ey][ex]);
    }
    printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", dynamic[i][j]);
        }
        printf("\n");

    }

    return 0;
}
