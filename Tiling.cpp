#include<stdio.h>

int N;
unsigned long long dynamic[251];

void get_dynamic_index(int n){

    dynamic[n] = (dynamic[n-1] + 2*(dynamic[n-2])) %1000000000;
}

int main(){
    int i;
    scanf("%llu", &N);

    dynamic[1] = 1;
    dynamic[2] = 3;

    for(i=3; i<=N; i++){
        get_dynamic_index(i);
    }

    printf("%llu", dynamic[N]);

    return 0;
}
