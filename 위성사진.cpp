#include<stdio.h>

int Q[160000];
char arr[1002][82];
int count_size;
int n; int m;

void bfs(int sy, int sx){

    int rear; int front;
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    int x; int y;
    int tx; int ty;
    int i; int j;


    count_size = 1; //count_size 초기화
    rear = 0; front = 0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(front<rear){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        arr[y][x] = '.';
        for(i=0; i<4; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(ty>=1 && ty<=n && tx>=1 && tx<=m && arr[ty][tx]=='*'){
                arr[ty][tx] = '.';
                count_size++;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}

int main(){

    int i; int j; int answer=0;

    scanf("%d %d", &m, &n);
    for(i=1; i<=n; i++){
        scanf("%s", &arr[i][1]);
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j] == '*'){
                bfs(i, j);
            }
            if(count_size>answer){
                answer = count_size;
            }
        }
    }

    printf("%d", answer);

}
