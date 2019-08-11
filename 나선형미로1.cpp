#include<stdio.h>

int main(){

    int i; int j;
    int N; int sum=0;
    int a[110][110] = {0,};
    int x; int y;
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    int key = 0;
    scanf("%d", &N);

    for(i=1;i<=N;i++){
        sum = sum + i;
    }

    if(i==0||i==N+2||j==0||j==N+2){
        a[i][j] = -1;
    }

    x=1; y=1;

    for(i=0;i<sum;i++){
        a[y][x] = (i%9)+1;

        if(a[y+2*dy[key]][x+2*dx[key]]){
            key = (key + 1) % 4;
        }
        y = y+dy[key];
        x = x+dx[key];
    }





    return 0;
}
