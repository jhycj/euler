#include<stdio.h>
#define INF 300000
int n;
int m;
int l;
int map[31][31][31];
int sz; int sy; int sx;
int ez; int ey; int ex;
int Q[100000];


void bfs(int sz, int sy, int sx){
    int front;
    int rear; int i;
    int z; int y; int x;
    int tz; int ty; int tx;
    int dz[6] = {0, 0, 0, 0, 1, -1};
    int dy[6] = {0, 1, 0, -1, 0, 0};
    int dx[6] = {1, 0, -1, 0, 0, 0};

    rear = 0; front = 0 ;

    Q[rear] = sz;
    rear++;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        z = Q[front];
        front++;
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<6; i++){
            tz = z +dz[i];
            ty = y +dy[i];
            tx = x +dx[i];

            if(tz>=1 && tz<=l && ty>=1 && ty<=n && tx>=1 && tx<=m && map[tz][ty][tx]>map[z][y][x]+1){
                map[tz][ty][tx] = map[z][y][x]+1;
                Q[rear] = tz;
                rear++;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}

int main(){
    int i; int j; int k;
    char tmp[32];

    scanf("%d %d %d", &l, &n, &m);

    for(k=1; k<=l; k++){
        for(i=1; i<=n; i++){
            scanf("%s", &tmp[1]);
            for(j=1; j<=m; j++){
                if(tmp[j] == '#'){
                    map[k][i][j] = -1;
                }
                else if(tmp[j] == '.'){
                    map[k][i][j] = INF;
                }
                else if(tmp[j] == 'S'){
                    map[k][i][j] = 0;
                    sz = k;
                    sy = i;
                    sx = j;
                }
                else if(tmp[j] == 'E'){
                    map[k][i][j] = INF;
                    ez = k;
                    ey = i;
                    ex = j;
                }
            }
        }
    }

    bfs(sz, sy, sx);
    if(map[ez][ey][ex]==INF){
        printf("-1");
    }
    else{
        printf("%d\n", map[ez][ey][ex]);

    }
    return 0;
}
