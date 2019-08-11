#include<stdio.h> //재귀함수 이용하기

int sum(int x){
    int answer;
    if(x==1){
        return 1;
    }
    else if(x==2){
        return 3;
    }

    else{
        answer = sum(x-1) + x;
        return answer;
    }
}


int main(){

    int N; int answer;
    scanf("%d", &N);

    answer = sum(N);
    printf("%d", answer);
    return 0;
}
