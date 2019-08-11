#include<stdio.h>

int n;
int m;
int Q[20005];
int map[102][102];
int dynamic[102][102];

void bfs(int sy, int sx){
    int i;
    int y; int x;
    int ty; int tx;
    int rear;
    int front;
    int dy[3] = {-1, 0, 1};
    int dx[3] ={1, 1, 1};

    rear = 0;
    front= 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<3; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<= n && tx>=1 && tx<= m){


                if(map[ty][tx]+dynamic[y][x] >dynamic[ty][tx]){
                    dynamic[ty][tx] = map[ty][tx] + dynamic[y][x];
                    Q[rear]= ty;
                    rear++;
                    Q[rear] = tx;
                    rear++;
                }
            }
        }
    }
}

int main(){
    int i; int j;

    scanf("%d", &n);
    scanf("%d", &m);

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &map[i][j]);
        }
    }
    dynamic[1][1] = map[1][1];

    bfs(1,1);

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", dynamic[i][j]);
        }
        printf("\n");
    }*/
    printf("%d", dynamic[n][m]);
    return 0;
}
