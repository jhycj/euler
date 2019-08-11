#include<stdio.h>

int N;

int find_sum(int n){

    if(n==1){
        return 1;
    }

    else{
        return find_sum(n-1) + n;
    }
}



int main(){
    scanf("%d", &N);

    printf("%d",find_sum(N));
    return 0;
}
