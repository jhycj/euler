#include<stdio.h>
int count;
int n; int m;
int sx; int sy;
int ex; int ey;
int map[62][62];
int cost[62][62];
int Q[7200];
void bfs(int sy, int sx){
    int rear;
    int front;
    int i;
    int k;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int y; int x; 
    int ty; int tx;
    count = -1 ;
    rear = 0; front = 0;
    k=0;

    Q[rear] = sy;
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

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && map[ty][tx] ==1 && cost[ty][tx]>cost[y][x]+1){

                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                cost[ty][tx] = count+1;

            }
        }
    }


}

int main(){
    scanf("%d %d", &m, &n);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &map[i][j]);
        }
    }




    return 0;
}
