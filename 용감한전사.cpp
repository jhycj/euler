#include<stdio.h>

int main(){

    long long x;
    long long y;
    long long diff;

    scanf("%lld", &x);
    scanf("%lld", &y);

    if(x>y){
        diff = x-y;
    }

    if(y>x){
        diff = y-x;
    }
    if(y==x){

        diff = 0;
    }

    printf("%lld", diff);
    return 0;
}
