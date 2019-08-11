#include<stdio.h>
#define INF 987654321
int n; int m;
int map1[1001][1001];
int map2[1001][1001];
int sy; int sx;
int ey; int ex;
int tree[1000000][3];
int tree_count;
int Q[3000000];

void bfs1(int sy, int sx){
    int front;
    int rear;
    int y; int x;
    int ty; int tx;
    int i;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    rear = 0; front = 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++ ;

    while(rear>front){
        y= Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<= n&& tx>=1 && tx<=m && map1[ty][tx]> map1[y][x]+1){
                map1[ty][tx] = map1[y][x]+1 ;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}

void bfs2(int sy, int sx){
    int front;
    int rear;
    int y; int x;
    int ty; int tx;
    int i;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    rear = 0; front = 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++ ;

    while(rear>front){
        y= Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<= n&& tx>=1 && tx<=m && map2[ty][tx]> map2[y][x]+1){
                map2[ty][tx] = map2[y][x]+1 ;
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
    int min;
    scanf("%d %d", &m, &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &map1[i][j]);
            if(map1[i][j]==0){ //이동가능
                map1[i][j] = INF;
            }
            else if(map1[i][j]==1){
                map1[i][j] = -1; //이동 불가능
            }
            else if(map1[i][j]==2){ //시작점
                map1[i][j] = 0;
                sy = i;
                sx = j;
            }
            else if(map1[i][j]==3){ //도착점
                map1[i][j] = INF;
                ey = i;
                ex = j;
            }
            else if(map1[i][j] ==4){ //나무 위치
                tree[tree_count][0]= i;
                tree[tree_count][1] = j;
                tree_count++;
                map1[i][j] = INF;
            }
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            map2[i][j] = map1[i][j];
        }
    }

    map2[sy][sx] = INF;
    map2[ey][ex] = 0 ;

    bfs1(sy,sx);
    bfs2(ey,ex);

    for(i=0; i<tree_count; i++){
        tree[i][2]= map1[tree[i][0]][tree[i][1]] + map2[tree[i][0]][tree[i][1]];
    }

    min = tree[0][2];

    for(i=1; i<tree_count; i++){
        if(min>tree[i][2]){
            min = tree[i][2];
        }
    }

    printf("%d", min);

    return 0;
}
