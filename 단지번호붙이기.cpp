#include<stdio.h>
int N;
char arr[27][27];
int count;

int bfs(int sy, int sx){
    int Q[1250];
    int front; int rear;
    int x; int y; int tx; int ty; int i;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    count = 1; //count 1로 초기화
    front = 0; rear =0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(front!= rear){
        //시작 좌표 설정
        y = Q[front];
        front++;
        x = Q[front];
        front++;
        arr[y][x] = '0'; //visit 했음
        for(i=0; i<4; i++){
            ty = y + dy[i];
            tx = x + dx[i];
            if(ty>=1 && ty<=N && tx>=1 && tx<= N && arr[ty][tx]=='1'){
                count++;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                arr[ty][tx] ='0'; //visit 했음
            }
        }
    }
}

int main(){
     //행, 열 갯수
    int i; int j; int k=0; int number=0;
    int answer[630]; int tmp;

    scanf("%d\n", &N);

    for(i=1; i<=N; i++){
        scanf("%s", &arr[i][1]);
    }

    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            if(arr[i][j] == '1'){ //집 발견하고 bfs 돌리자마자 정리할 거 정리하기
                bfs(i, j);
                number++;
                answer[k] = count;
                k++;
            }
        }
    }

    for(i=2; i<=number; i++){
        for(j=0; j<=number-i; j++){
            if(answer[j+1]<answer[j]){
                tmp = answer[j+1];
                answer[j+1] = answer[j];
                answer[j] = tmp;
            }
        }
    }

    printf("%d\n", number);

    for(i=0; i<number; i++){
        printf("%d\n",answer[i]);
    }

    return 0;
}
