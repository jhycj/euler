#include<stdio.h>

int main(){

    long long N;  //콜라 병수
    long long K;
    long long q;
    long long r;
    long long tmp;
    long long extra;

    scanf("%lld", &N);
    scanf("%lld", &K);

    q = N / K;
    r = N % K;
    extra = N + q;

    while(q+r >= K){
        tmp = q+r;
        q = tmp / K;
        r = tmp % K;
        extra = extra + q;
    }
    printf("%lld", extra);
    return 0;
}
