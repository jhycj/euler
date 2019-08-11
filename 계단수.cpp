#include<stdio.h>

int N;
unsigned long long dynamic[12][102];

void initialize_dynamic(void){
    int i;
    for(i=2; i<=10; i++){
        dynamic[i][1] = 1;
    }
}

void get_dynamic_index(int n){
    int i;
    for(i=1; i<=10; i++){
        dynamic[i][n] = (dynamic[i-1][n-1] + dynamic[i+1][n-1]) %1000000000;
    }
}
int main(){
    int i; int j;
    unsigned long long answer=0;
    scanf("%d", &N);
    initialize_dynamic();

    for(i=2; i<=N; i++){
        get_dynamic_index(i);
    }

    for(i=1; i<=10; i++){
        answer = (answer+dynamic[i][N])%1000000000;
    }

    printf("%llu", answer);

    return 0;
}
