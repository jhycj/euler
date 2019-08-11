#include<stdio.h>
#define INF m*n+1;

char map[52][52];
int n; int m;
int arr[52][52];
int Q[5000];

void init(void){
    int i;
    int j;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(map[i][j]=='W'){
                arr[i][j] = -1;
            }
            else{
                arr[i][j] = INF; //여긴 땅이다
            }
        }
    }//arr초기화;
}

int bfs(int sy, int sx){
    int ty; int tx; int x; int y;
    int i;
    int max=0;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int rear; int front;
    int count=0;

    front = 0; rear = 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    arr[sy][sx] = 0;

    while(rear>front){
        count++;

        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && arr[ty][tx]>=0 && arr[ty][tx]>arr[y][x]+1){
                arr[ty][tx] = arr[y][x] +1;  //visit 했음
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;

                if(max<arr[ty][tx]){
                    max = arr[ty][tx];
                }
            }
        }
    }
    return max;
}

int main(){
    int max;
    char tmp[52];
    int answer=0;
    int i; int j;

    scanf("%d %d", &n, &m);

    for(i=1; i<=n; i++){
        scanf("%s", &map[i][1]);
    } //입력 잘 받아짐

    init();

    for(i=1; i<=n;i++){
        for(j=1; j<=m; j++){
            if(arr[i][j]>0){
                init();
                max = bfs(i,j);
                if(answer<max){
                    answer = max;
                }
            }
        }
    }


    printf("%d", answer );

    return 0;
}
