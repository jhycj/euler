#include<stdio.h>

int main(){

    int N; int M; int K;
    int i; int j;
    int rear; int front;

    int Q[500]; //대기 번호
    int a[500]; //죽는 사람 번호

    scanf("%d", &N); //사람 수
    scanf("%d", &M); // 처음 죽는 번호
    scanf("%d", &K); // 간격

    for(i=0; i<N-M+1; i++){
        Q[i] = i+M;
    }

    for(i=0; i<M-1; i++){
        Q[i+]
    }



    return 0;
}
