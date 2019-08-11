#include<stdio.h>
int Q[10000];
int a[10000];

int main(){
    int i; int j;
    int rear; int front=0 ;
    int N; //사람수
    int M; // 처음 값
    int K; // 간격



    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &K);

    for(i=M; i<=N; i++){
        Q[i-M] = i;
    }

    for(i=0; i<=M-2;i++){
        Q[N-M+1+i] = i+1;
    }

    // 큐의 초기화
    rear = N;

    //for(i=0; i<N; i++){
    //    printf("%d", Q[i]);
    //}
    for(i=0; i<N-1; i++){
        a[i] = Q[front];
        front ++;
        for(j=0; j<K-1; j++){
            Q[rear] = Q[front];
            front++;
            rear++ ;
        }
    }

    for(i=0; i<N-1; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d", Q[rear-1]);

    return 0;
}
