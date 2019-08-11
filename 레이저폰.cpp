#include<stdio.h>
#define INF 987654321
int m; int n;
int map1[101][101];
int map2[101][101];
int map3[101][101];
int sy; int sx;
int ey; int ex;
int Q[400000];

void bfs(int sy, int sx){
    int front;
    int rear;
    int i;
    int dy[4] ={0, 1, 0, -1};
    int dx[4] ={1, 0, -1, 0};
    int y; int x;
    int ty; int tx;
    rear = 0; front = 0;

    Q[rear]= sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && map1[ty][tx] != -1 && map3[ty][tx] ){
                map2[ty][tx] = i;
                if(map2[y][x]!= map2[ty][tx]){
                    if(map3[ty][tx] > map3[y][x]+1){
                        map3[ty][tx] = map3[y][x]+1;
                        Q[rear] = ty;
                        rear++;
                        Q[rear] = tx;
                        rear++;
                    }
                }
                else if(map2[y][x] == map2[ty][tx]){
                    if(map3[ty][tx]>map3[y][x]){
                        map3[ty][tx] = map3[y][x];
                        Q[rear] = ty;
                        rear++;
                        Q[rear] = tx;
                        rear++;
                    }
                }
            }
        }
    }
}


int main(){
    char tmp[102];
    int index[4];
    int rear=0;
    int i; int j;

    scanf("%d %d", &m, &n);
    for(i=1; i<=n; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=m; j++){
            if(tmp[j] == '.'){
                map1[i][j] = INF;
            }
            else if(tmp[j] == '*'){
                map1[i][j] = -1;
            }
            else if(tmp[j] == 'C'){
                map1[i][j] == INF;
                index[rear] = i;
                rear++;
                index[rear] = j;
                rear++;
            }
        }
    }

    sy = index[0];
    sx = index[1];
    ey = index[2];
    ex = index[3];

    map1[sy][sx] = 0;
    map1[ey][ex] = INF;

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            map3[i][j] = INF;
        }
    }
    map2[sy][sx] = 4;
    map3[sy][sx] = 0;
    bfs(sy, sx);
    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map3[i][j]);
        }
        printf("\n");
    }

    printf("\n");*/
    printf("%d", map3[ey][ex]-1);
    return 0;
}
