#include<stdio.h>
char arr[752][752];
int count;
int Q[1125000];
void bfs(int sy, int sx){
    int x; int y;
    int ty; int tx;
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int rear; int front;
    int i;

    count = 1;
    rear = 0; front = 0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear!=front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;
        arr[y][x] = '*'; //visit 했음

        for(i=0; i<8; i++){
            ty = y+dy[i];
            tx = x+dx[i];
            if(arr[ty][tx] == '.'){
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                arr[ty][tx] = '*'; //visit 했음
                count++;
            }
        }
    }
}

int main(){
    int i; int j;
    int n; int m;
    int answer=0;
    scanf("%d %d", &m, &n);
    for(i=1; i<=n; i++){
        scanf("%s", &arr[i][1]);
    }

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }*/

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j]=='.'){
                bfs(i, j);
                if(answer<=count){
                    answer = count;
                }
            }
        }
    }


    printf("%d", answer);
    return 0;
}
