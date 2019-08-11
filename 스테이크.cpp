#include<stdio.h>

int main(){

    int N; // 사람 명수
    int K; //  1분에 K면
    int q;
    int r;
    int x;

    scanf("%d", &N);
    scanf("%d", &K);

    q = N / K;
    r = N % K;

    if(r==0){
        x = 2*q;
    }
    else{
        x = (2*q) + 2;
    }
    printf("%d", x);
    return 0;
}
