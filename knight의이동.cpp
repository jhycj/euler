#include<stdio.h>
#define INF 65

int Q[130];
int arr[9][9];

void bfs(int sy, int sx){
    int i;
    int rear; int front;
    int ty; int tx;
    int y; int x;
    int dy[8]={-2, -1, 1, 2, 2, 1, -1, -2};
    int dx[8]={1, 2, 2, 1, -1, -2, -2, -1};

    rear=0; front=0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    arr[sy][sx] = 0; //시작지점 최소 이동횟수

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<8; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=8 && tx>=1 &&tx<=8 && arr[ty][tx]>arr[y][x]+1){
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                arr[ty][tx] = arr[y][x] + 1;
            }
        }
    }
}

int main(){

    char tmp[2][3];
    int i; int j;
    int sy; int sx; //시작지점
    int ey; int ex; //끝지점

    for(i=1; i<=8; i++){
        for(j=1; j<=8; j++){
            arr[i][j] = INF; //arr 초기화
        }
    }

    for(i=0; i<2; i++){
        scanf("%s", &tmp[i][0]);
    }

    sy = tmp[0][0] - 'a' +1 ;
    sx = tmp[0][1] - '1' +1;

    ey = tmp[1][0] - 'a' +1;
    ex = tmp[1][1] - '1' +1;

    /*for(i=1; i<=8; i++){
        for(j=1; j<=8; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }*/

    bfs(sy, sx);
    printf("%d", arr[ey][ex]); 


    return 0;
}
