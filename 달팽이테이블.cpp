#include<stdio.h>

int main(){

    int i; int j;
    int x; int y;
    int key;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int N; int p;
    int arr[20][20];

    scanf("%d", &N); // 행렬 사이즈
    scanf("%d", &p); // 초기 입력값


    for(i=0; i<N+2; i++){
        for(j=0; j<N+2; j++){
            if(i==0 || i==N+1 || j==0 || j==N+1){
                arr[i][j] = -1;
            }
            else{
                arr[i][j] = 0;
            }
        }
    } //보초 세우고 나머지 부분은 0으로 초기화

    x=1;
    y=1;
    key =0;

    for(i=1; i<= N*N; i++){

        arr[y][x] = p + (i-1);

        if(arr[y+dy[key]][x+dx[key]] != 0){
            key = (key+1) % 4;
        }

        x = x + dx[key];
        y = y + dy[key];

    }

    for (i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
