#include<stdio.h>

int main(){
    int i;
    int N;
    int x;
    
    x=1;
    scanf("%d", &N);

    for(i=0; i<N; i++){
        x = x*2;
        x = x % 100;
    }

    printf("%d", x);
    return 0;
}
