#include<stdio.h>
#define INF 3000

int n; int m;
int sy; int sx;
int ey; int ex;
int y; int x;
int odd_map[51][51];
int even_map[51][51];

int Q[20000];

void bfs(int sy, int sx){
    int i;
    int dy_odd[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dx_odd[8] ={1, 2, 2, 1, -1, -2, -2, -1};
    int dy_even[4]={-2, 0, 2, 0};
    int dx_even[4]= {0, 2, 0, -2};
    int ty; int tx;
    int front; int rear;

    front = 0; rear=0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;
    Q[rear] = 0; //(sy, sx)는 짝수판에서 왔다.
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        if(Q[front]== 0){ //탐색 출발 지점이 짝수판에서 왔다. =>홀수 map을 변형시켜야 함
            for(i=0; i<8; i++){
                ty = y+dy_odd[i];
                tx = x+dx_odd[i];

                if(ty>=1 && ty<=n && tx>=1 && tx<=m && odd_map[ty][tx]>even_map[y][x]+1){
                    odd_map[ty][tx] = even_map[y][x]+1;
                    Q[rear] = ty;
                    rear++;
                    Q[rear] = tx;
                    rear++;
                    Q[rear] = 1;
                    rear++;
                }
            }
            front++;
        }

        else if(Q[front] ==1){//탐색 출발 지점이 홀수판에서 왔다 => 짝수 map을 변형시켜야 함
            for(i=0; i<4; i++){
                ty = y+dy_even[i];
                tx = x+dx_even[i];

                if(ty>=1 && ty<=n && tx>=1 && tx<=m && even_map[ty][tx]>odd_map[y][x]+1){
                    even_map[ty][tx] = odd_map[y][x]+1;
                    Q[rear] = ty;
                    rear++;
                    Q[rear] = tx;
                    rear++;
                    Q[rear] = 0;
                    rear++;
                }
            }
            front++;
        }
    }
}


int main(){

    int i; int j;

    scanf("%d %d", &n, &m);
    scanf("%d %d", &sy, &sx);
    scanf("%d %d", &ey, &ex);

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            odd_map[i][j] = INF;
            even_map[i][j] = INF;

            if(i==sy && j==sx){
                even_map[i][j] = 0;
            }
        }
    }

    bfs(sy, sx);

    if(even_map[ey][ex]<odd_map[ey][ex]){
        printf("%d", even_map[ey][ex]);
    }

    else{
        printf("%d", odd_map[ey][ex]);
    }

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", odd_map[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", even_map[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}
