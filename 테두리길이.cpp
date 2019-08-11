#include<stdio.h>
int n; int m;
char arr[27][27];
int count;
int Q[620] ;

void bfs(int sy, int sx){

    int x; int y; int tx; int ty;
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1,-1};
    int i; int front; int rear;
    rear = 0; front = 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;
    arr[sy][sx] = '*';
    while(front!=rear){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        //arr[y][x] = '*'; //방문했음

        for(i=0; i<8; i++){
            ty = y + dy[i];
            tx = x + dx[i];  //4방향 탐색 ;

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && arr[ty][tx] == 'X'){
                arr[ty][tx] = '*'; //방문 했음
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}

void four(int y, int x){
    int i;  int ty; int tx;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    count = 0;
    for(i=0; i<4; i++){
        ty = y+dy[i];
        tx = x+dx[i];

        if(arr[ty][tx] !='*'){
            count++;
        }
    }
}

int main(){
    int i; int j;
    int sy; int sx;
    int sum = 0;

    scanf("%d %d %d %d", &n, &m, &sy, &sx);
    for(i=1; i<=n; i++){
        scanf("%s", &arr[i][1]);
    }


    bfs(sy, sx) ;

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }*/

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j]=='*'){
                four(i,j);
                sum = sum+count;
            }
        }
    }
    printf("%d", sum);

    return 0;
}
