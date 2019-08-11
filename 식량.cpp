#include<stdio.h>

int main(){
    int i; int j;
    int sum = 0;
    int N;//공급 일수
    int Q; //퀴즈 갯수
    int H[50001]; // 식량 담는 배열
    int S[50001]; // 퀴즈 시작일
    int E[50001]; // 퀴즈 끝일
    int A[50001]; // 퀴즈 정답
    scanf("%d", &N);

    scanf("%d", &Q);

    for(i=1; i<=N; i++){
        scanf("%d", &H[i]);
    }

    for (i=1; i<=Q; i++){
        scanf("%d", &S[i]);
        scanf("%d", &E[i]);
    }
    for(i=1; i<=Q; i++){
        for(j=S[i]; j<=E[i]; j++){
            sum = sum + H[j];
        }
        A[i] = sum;
        sum = 0;
    }

    for(i=1; i<=Q; i++){
        printf("%d\n",A[i]);
    }

    return 0;
}
