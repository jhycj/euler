#include<stdio.h>

int prime[100000];
int rear;

int is_prime(int num){ //소수이면 1을 리턴, 아니면 0을  리턴
    int i;
    if(num==2){
        return 1;
    }
    else if(num==3){
        return 1;
    }
    else{
        for(i=2; i<=num/2; i++){
            if(num%i==0){
                return 0;
            }
        }
        return 1;
    }
}

int main(){
    int i;
    rear=1;

    for(i=2;i<100000;i++){
        if(is_prime(i)==1){
            prime[rear]=i;
            rear++;
        }
    }
    for(i=1; i<10000; i++){
        printf("%d ", prime[i]);

    }
    return 0;
}
