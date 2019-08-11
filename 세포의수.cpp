#include<stdio.h>
int l; int m; int n;
int Q[375000];
int arr[51][51][51];

void bfs(int sz, int sy, int sx, int num){
    int rear;
    int front;
    int i;
    int dy[6]={0, 1, 0, -1, 0, 0};
    int dx[6]={1, 0, -1, 0, 0, 0};
    int dz[6]={0, 0, 0, 0, -1, 1};
    int ty; int tx; int tz;
    int y; int x; int z;

    rear =0; front=0;
    Q[rear] = sz;
    rear++;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        z=Q[front];
        front++;
        y=Q[front];
        front++;
        x=Q[front];
        front++;

        arr[z][y][x] = 0; //visit 했음;

        for(i=0; i<6; i++){
            tz = z+dz[i];
            ty = y+dy[i];
            tx = x+dx[i];

            if(tz>=1 && tz<=l && ty>=1 && ty<=n && tx>=1 && tx<=m && arr[tz][ty][tx]==num){
                Q[rear] = tz;
                rear++;
                Q[rear] = ty;
                rear++;
                Q[rear]=tx;
                rear++;
                arr[tz][ty][tx] = 0; //방문했음
            }
        }
    }
}

int main(){
    int answer = 0;
    int i; int j; int k;

    scanf("%d %d %d", &m, &n, &l); //가로 세로 높이 입력

    for(i=1; i<=l; i++){
        for(j=1; j<=n; j++){
            for(k=1; k<=m; k++){
                scanf("%d", &arr[i][j][k]);
            }
        }
    }


    /*for(i=1; i<=l; i++){
        for(j=1; j<=m; j++){
            for(k=1; k<=n;k++){
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n \n");
    }*/

    for(i=1; i<=l; i++){
        for(j=1; j<=n; j++){
            for(k=1; k<=m; k++){
                if(arr[i][j][k]!=0){
                    bfs(i,j,k,arr[i][j][k]);
                    answer++;
                }
            }
        }
    }


    printf("%d", answer);
    return 0;
}
