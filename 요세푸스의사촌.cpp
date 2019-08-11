#include<stdio.h>
int prime[100000];
int Q[12300000];
int is_prime(int num1){
    int i;

    if(num1==2){
        return 1;
    }

    else if(num1==3){
        return 1;
    }
    else{
        for(i=2;i<=num1/2;i++){
            if(num1%i==0){
                return 0;
            }
        }
        return 1;
    }
}

int nth_prime(int num2){
    int rear=1; int i;
    for(i=2; i<10000;i++){
        if(is_prime(i)==1){
            prime[rear] = i;
            rear++;
        }
    }

    return prime[num2];
}

int main(){
    int N; int K;
    int i; int j;
    int rear; int front;
    scanf("%d", &N);

    for(i=1;i<=N;i++){
        Q[i]=i;
    }

    for(i=1; i<10; i++){
        printf("%d ",nth_prime(i) );
    }


    rear = N+1;
    front = 0;
    K=1;
    while(rear-front !=1){

        for(i=0; i< nth_prime(K)-1; i++){ //nth_prime[K-1]번 반복
            front++;
            Q[rear] = Q[front];
            rear++;
        }
        front++;
        K++;
        for(i=1; i<rear; i++){
            printf("%d ", Q[i]);
        }
        printf("\n");
    }

    printf("%d", Q[rear-1]);



    return 0;
}
