#include<stdio.h>
#define INF 10000
int n; int m;
int map[101][101];
int sy; int sx;
int Q[20000];

void bfs(int sy, int sx){
    int rear;
    int front;
    int i;
    int y;
    int x;
    int ty;
    int tx;
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    rear = 0; front= 0;
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
    int M_X;
    int M_Y;
    int i; int j;
    char tmp[102];
    int answer; 
    scanf("%d %d %d %d", &m, &n, &M_X, &M_Y);
    sy = n - (M_Y-1);
    sx = M_X;

    for (i=1; i<=n; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=m; j++){
            if(tmp[j]== '*'){
                map[i][j] = -1;
            }
            if(tmp[j]== '.'){
                map[i][j] =INF;
            }
        }
    }

    map[sy][sx] = 0;

    bfs(sy, sx);

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }*/
    answer = map[1][1];

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(answer <= map[i][j]){
                answer= map[i][j];
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
