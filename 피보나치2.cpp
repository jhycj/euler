#include<stdio.h>
int N;

int fibo(int N){
    if(N==0){
        return 0;
    }

    else if(N==1){
        return 1;
    }

    else{
        return fibo(N-1) + fibo(N-2);
    }




}


int main(){

    scanf("%d", &N);
    printf("%d", fibo(N));
    return 0;
}
