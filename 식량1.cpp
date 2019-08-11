#include<stdio.h>

int main(){

    int i; int j;

    int N;//공급 일수
    int Q; //퀴즈 갯수
    int H[50001]; // 식량 담는 배열
    int sum[50001]; //식량 누적 배열
    int S[50001]; // 퀴즈 시작일
    int E[50001]; // 퀴즈 끝일
    int A[50001]; // 퀴즈 정답
    scanf("%d", &N);

    scanf("%d", &Q);

    for(i=1; i<=N; i++){
        scanf("%d", &H[i]);
    }

    sum[0] = 0;
    for(i=1; i<=N; i++){
        sum[i] = sum[i-1] + H[i];
    }

    for (i=1; i<=Q; i++){
        scanf("%d", &S[i]);
        scanf("%d", &E[i]);
    }

    for(i=1; i<=Q; i++){
        A[i] = sum[E[i]] - sum[S[i]-1];
        printf("%d\n", A[i]);
    }
    return 0;
}
