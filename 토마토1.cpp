#include<stdio.h>
#define INF 1000000
int map[1002][1002];
int Q[2000007];
int n; int m;
int rear;

void bfs(void){
    int front;
    int y; int x;
    int ty; int tx;
    int dy[4]={0, 1, 0, -1};
    int dx[4]={1, 0, -1, 0};
    int i;
    front = 0;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<= n && tx>=1 && tx<=m &&map[ty][tx]>map[y][x]+1){
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                map[ty][tx] = map[y][x]+1;
            }
        }
    }
}

int main(){
    int i; int j;
    int max;
    rear=0;
    scanf("%d %d", &m, &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==1){
                Q[rear] = i;
                rear++;
                Q[rear] = j;
                rear++;
            }

            else if(map[i][j]==0){
                map[i][j] = INF;
            }
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(map[i][j]==1){
                map[i][j] = 0;//0에서부터 출발
            }
        }
    }

    bfs();

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d", map[i][j]);
        }
        printf("\n");
    }*/

    max = map[1][1];
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(max<map[i][j]){
                max = map[i][j];
            }
        }
    }

    if(max==INF){
        printf("-1");
    }

    else{
        printf("%d", max);
    }
    return 0;
}
