#include<stdio.h>
int arr[102][102];
int Q[20000];
int n; int m;

void bfs(int sy, int sx){ //시작지점 입력 받음
    int i;
    int dy[4]={0, 1, 0, -1};
    int dx[4] ={1, 0, -1, 0};
    int ty; int tx; int y; int x;
    int rear; int front;

    rear=0; front=0;

    Q[rear] = sy; rear++;
    Q[rear] = sx; rear++;

    while(front<rear){
        y = Q[front];
        front++;
        x = Q[front];
        front++;
        arr[y][x]= -1;
        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];
            if(ty>=1 && ty<=n && tx>=1 && tx<=m && arr[ty][tx]==0){
                arr[ty][tx] = -1;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }

            if(ty>=1 && ty<= n && tx>=1 && tx<=m && arr[ty][tx]>0){//왜 0 보다 큰지 그냥 1로 하면 안되는지
                arr[ty][tx] ++;
            }
        }
    }
}

int main(){
    int i; int j;
    int sum;
    int answer=0;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &arr[i][j]);
        }//치즈 입력받음.
    }


    while(1){
        bfs(1,1);
        sum = 0; 
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(arr[i][j]>=3){
                    arr[i][j] = 0; //바깥 공기로 바꿔주기
                }
                else if(arr[i][j]==1 || arr[i][j]==2){
                    arr[i][j] = 1; //치즈로 냅두기
                }
                else if(arr[i][j]==-1){
                    arr[i][j] = 0; //바깥공기로 바꿔주기.
                }
                sum=sum+arr[i][j];
            }
        }

        answer++;
        /*for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                printf("%d ", arr[i][j]);
            }//치즈 입력받음.
            printf("\n");
        }*/

        if(sum==0){
            break;
        }
    }

    printf("%d", answer);

    return 0;
}
