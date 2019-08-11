#include<stdio.h>
int n; int m;
int Q[20000];
int arr[101][101];

void bfs(int sy, int sx){
    int rear; int front;
    int dy[4] ={0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int i;
    int ty; int tx; int x; int y;

    rear =0; front=0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        arr[y][x] = -1; //외부공기 및 방문했음

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<= n && tx>=1 && tx<=m && arr[ty][tx]==0){
                arr[ty][tx] = -1; //외부공기 및 방문했음
                Q[rear]=ty;
                rear++;
                Q[rear]=tx;
                rear++;
            }
            else if(ty>=1 && ty<=n && tx>=1 && tx<=m && arr[ty][tx] == 1){
                arr[ty][tx] = 0; //치즈 사라짐
            }
        }
    }
}


int main(){
    int i; int j;
    int answer=0; int sum=0;
    scanf("%d %d", &n, &m);

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &arr[i][j]);
        }
    } //치즈 입력받음

    while(1){
        bfs(1,1); //외부공기인지 치즈인지 -1, 0, 1,로 표시해줌
        answer++;
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(arr[i][j] == -1){//외부공기 확실함
                    arr[i][j] = 0; //다시 0으로 바꿔주기
                }

                sum = sum+arr[i][j];
            }
        }

        if(sum==0){
            break;
        }
    }

    printf("%d", answer);
    return 0;
}
