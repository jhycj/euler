#include<stdio.h>
int n; //학생 수
int s; //처음 시작 번호
int K; //간격
int Q[10001]; int rear; int front;

int main(){
    int i; int j;

    scanf("%d", &n);
    scanf("%d", &s);
    scanf("%d", &K);

    for(i=s;i<=n;i++){
        Q[i-s+1]=i;
    }

    for(i=1;i<s;i++){
        Q[n-s+1+i] = i;
    }

    rear = n+1;
    front = 0;

    while(rear-front != 1){
        for(i=0;i<K-1;i++){
            front++;
            Q[rear]=Q[front];
            rear++;
        }
        front++;
    }
    printf("%d", Q[front]);


    return 0;
}
