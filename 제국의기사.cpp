#include<stdio.h>
#define INF 23000

int m;
int n;
int Q[45000];
char arr[152][152];
int map[152][152];

void bfs(int sy, int sx){
    int front; int rear;
    int dy[8]={-2, -1, 1, 2, 2, 1, -1, -2};
    int dx[8]={1, 2, 2, 1, -1, -2, -2, -1};
    int i; int ty; int tx; int y; int x;

    rear = 0; front = 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    map[sy][sx] = 0;

    while(rear>front){
        y= Q[front];
        front++;
        x = Q[front];
        front++;
        for(i=0; i<8; i++){
            ty = y+dy[i];
            tx = x+dx[i];
            if(ty>=1 && ty<=n && tx>=1 && tx<=m && map[ty][tx]!= -1 && map[ty][tx]>map[y][x]+1){
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
    char tmp[152];
    int i; int j;
    int ey; int ex; int sy; int sx;

    scanf("%d %d", &m, &n);

    for(i=1; i<=n; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=m; j++){
            arr[i][j] = tmp[j];
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j]=='*'){
                map[i][j] = -1;
            }
            else if(arr[i][j]=='.'){
                map[i][j] = INF;
            }
            else if(arr[i][j] == 'K'){
                map[i][j] = 0;
                sy = i;
                sx = j;
            }
            else if(arr[i][j]=='H'){
                map[i][j] = INF;
                ey = i;
                ex = j;
            }
        }
    }

    bfs(sy, sx);


    printf("%d", map[ey][ex]);
    return 0;
}
