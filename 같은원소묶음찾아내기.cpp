#include<stdio.h>
int Q[5005];

int main(){
    int n; //행의 갯수
    int answer=1;
    char arr[55][55];
    int b[55][55]={0,};//visit 역할
    int i; int j;
    int sx; int sy;
    int tx; int ty; //움직이는 x, y들
    int x; int y; //현재 탐색중인 x, y들
    int rear; int front;
    int dx[4] ={1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    scanf("%d", &n);
    scanf("%d %d", &sx, &sy);

    for(i=1; i<=n; i++){
        scanf("%s", &arr[i][1]);
    }


    front = 0; rear = 0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(front!=rear){
        y= Q[front];
        front++;
        x= Q[front];
        front++;

        b[y][x] = 1; //방문한 좌표는 1로 바꿈

        for(i=0; i<4; i++){
            ty = y + dy[i];
            tx = x + dx[i];
            if(ty>=1 && ty<=n && tx>=1 && tx<=n && b[ty][tx]==0 &&arr[ty][tx] == arr[sy][sx]){
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                b[ty][tx] = 1; //방문한 좌표는 1로 바꿈!
                answer++;
            }
        }
    }

    printf("%d", answer);


    return 0;
}
