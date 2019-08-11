#include<stdio.h>
#define INF 3000

int n;
int m;
int sy;
int sx;
int ey;
int ex;
int odd_map[51][51];
int even_map[51][51];

int Q[8000];
int rear;
int front;

void odd(int rear, int y, int x);
void even(int rear, int y, int x);

void bfs(int sy, int sx){
    int y; int x;
    int ty; int tx;

    rear = 0 ;
    front = 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;
        if(front%4 == 2){odd(rear, y, x);}
        else if(front%4 == 0){even(rear, y, x);}
    }
}

void odd(int rear, int y, int x){
    int i;
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dx[8] ={1, 2, 2, 1, -1, -2, -2, -1};
    int ty; int tx;

    for(i=0; i<8; i++){
        ty = y+dy[i];
        tx = x+dx[i];

        if(ty>=1 && ty<=n && tx>=1 && tx<=m && odd_map[ty][tx]>even_map[y][x]+1){
            map[ty][tx] = map[y][x]+1;
            Q[rear] = ty;
            rear++;
            Q[rear] = tx;
            rear++;
        }
    }
}

void even(int rear, int y, int x){
    int i;
    int dy[4]={-2, 0, 2, 0};
    int dx[4]= {0, 2, 0, -2};
    int ty; int tx;

    for(i=0; i<4; i++){
        ty = y+dy[i];
        tx = x+dx[i];

        if(ty>=1 && ty<=n && tx>=1 && tx<=m && map[ty][tx]>map[y][x]+1){
            map[ty][tx] = map[y][x]+1;
            Q[rear] = ty;
            rear++;
            Q[rear] = tx;
            rear++;
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
            map[i][j] = INF;
            if(i==sy && j==sx){
                map[i][j] = 0;
            }
        }
    }

    bfs(sy,sx);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }



    return 0;
}
