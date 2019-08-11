#include<stdio.h>

int main(){
    int answer; int i;
    int tmp; int x1 = 0; int x2 = 1; int x3;
    int N;
    scanf("%d", &N);
    x3 = x1+ x2;
    if(N==0){
        answer = 0;
    }

    else if(N==1){
        answer = 1;
    }

    else{
        for(i=0; i<N-2; i++){ //N-1번 반복하기
            tmp = x1;
            x1 = x2;
            x2 = x3;
            x3 = x1+x2;
        }
        answer = x3;
    }
    printf("%d", answer);
    return 0;
}
