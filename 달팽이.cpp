#include<stdio.h>

int main(){

    long long A; //낮
    long long B; //밤
    long long V; //나무높이
    long long h; //현재 높이
    long long day;

    scanf("%lld", &A);
    scanf("%lld", &B);
    scanf("%lld", &V);

    h = 0;
    day = 0;

    while(h<V){
        day++;
        h = h+A;
        h = h-B;
    }

    printf("%lld", day);
    return 0;
}
