#include<stdio.h>

int function(int N, int M){
    int Q[10000];
    int front; int rear;
    int i; int j;

    for(i=0; i<N; i++){ //큐에 번호 차례대로 입력
        Q[i] = i+1;
    }

    front = 0; rear = N;//N+1번째 자리에 입력할 것임

    while(Q[front]!= 13){
        front++; //여기서부터 뒤로 보내기 가능
        for(i=0; i<M-1; i++){ //M-1번 삽입 반복
            Q[rear] = Q[front];
            front++;
            rear++;  //while문 빠져나오면 front가 다음 차단할 거 가르키고 있음
        }
    }
    return rear-front;
}

int main(){
    int N; int answer; int i;
    scanf("%d", &N);//지역 갯수 입력받음

    for(i=1; i<=10000; i++){
        if(function(N, i)==1){
            answer = i;
            break;
        }
    }
    printf("%d", answer);

    return 0;
}
