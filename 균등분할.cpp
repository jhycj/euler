#include<stdio.h>
int arr[101][101];
int Q[20007];


int get_input(void){
    int N;
    int i;
    int j;
    int k;
    int tmp1; int tmp2;

    //arr[][]의 초기화

    for(i=0; i<=101; i++){
        for(j=0; j<=101; j++){
            arr[i][j] = 0;
        }
    }

    scanf("%d", &N);
    for(j=0; j<N-1; j++){
        for(k=0; k<N; k++){
            scanf("%d %d", &tmp1, &tmp2);
            arr[tmp1][tmp2] = j+1; //1부터 N-1까지의 수를 차례대로 대입함.
        }
    }

    return N;
}

int bfs(int N, int sy, int sx){

    int rear=0;
    int front=0;
    int i;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int y;
    int x;
    int ty;
    int tx;
    int num; // 돌아가면서 체크할 값
    int count=1; //일단 bfs를 돌렸다는 거는 arr[sy][sx] == num에 해당하는 원소를 찾았다는 것임

    num = arr[sy][sx];

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){

        y = Q[front];
        front++;
        x = Q[front];
        front++;
        arr[y][x] = -1;

        for(i=0; i<4; i++){

            ty = y + dy[i];
            tx = x + dx[i];

            if(ty>=1 && ty<= N && tx>=1 && tx<=N && arr[ty][tx] == num && arr[ty][tx]!= -1){

                count++;
                arr[ty][tx] = -1;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }

    if(count==N){
        return 1;
    }

    else{
        return 0;
    }
}


int main(){
    int i; int j; int N;
    int k; int check;

    for(k=0; k<3; k++){
        N = get_input(); //N*N size 배열이 들어오면 N을 return 받는다.
        //N에 대하여 bfs를 N번 실행한다.
        check = 0;
        for(i=1; i<=N; i++){
            for(j=1; j<=N; j++){

                if(arr[i][j] != -1){
                    check = check + bfs(N, i, j);
                }
            }
        }

        if(check == N){
            printf("good\n");
        }
        else{
            printf("wrong\n");
        }

    }





    /*for(i=0; i<100; i++){
        for(j=0; j<100; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }*/


    return 0;
}
