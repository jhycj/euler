#include<stdio.h>
int arr[101][101];
int n; int m;

void bfs(int sy, int sx){
    int Q[20405];
    int front; int rear;
    int x; int y;
    int tx; int ty;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int i; int j;

    front = 0; rear =0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear!=front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        arr[y][x] = -1;  //방문 했음

        for(i=0; i<4; i++){

            ty = y + dy[i];
            tx = x + dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && arr[ty][tx] == 0){
                arr[ty][tx] = -1; //방문했음
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && arr[ty][tx] >0){
                arr[ty][tx] ++; //값 증가시키기
            }
        }
    }
}


int main(){
    int i; int j; int k;
    int answer=0; int sum = 0;
    scanf("%d %d", &n, &m); //세로길이, 가로길이

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    bfs(1,1);

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j]== -1 || arr[i][j] == 0){
                arr[i][j] = 0 ; //다시 바다로 돌리기
            }
            else if(arr[i][j] >=3){
                arr[i][j] = 0; //바다로 잠김
            }
            else if(arr[i][j] == 1 || arr[i][j] ==2){
                arr[i][j] = 1; //안잠긴 섬 원상복귀
            }
            sum = sum + arr[i][j];
        }
    }


    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }*/

    while(1){
        sum =0 ;
        answer++;
        bfs(1,1);

        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(arr[i][j]== -1 || arr[i][j] == 0){
                    arr[i][j] = 0 ; //다시 바다로 돌리기
                }
                else if(arr[i][j] >=3){
                    arr[i][j] = 0; //바다로 잠김
                }
                else if(arr[i][j] == 1 || arr[i][j] ==2){
                    arr[i][j] = 1; //안잠긴 섬 원상복귀
                }
                sum = sum + arr[i][j];
            }
        }

        if(sum==0){
            break;
        }
    }

    printf("%d\n", answer);

    return 0;
}
