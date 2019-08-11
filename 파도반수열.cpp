#include<stdio.h>

int n;
unsigned long long int dynamic[101];  //100개 이하 정수

int main(){
    int i;
    scanf("%d", &n);

    dynamic[1] = 1;
    dynamic[2]= 1;
    dynamic[3] = 1;
    dynamic[4] = 2;
    dynamic[5] = 2;

    for(i=6; i<=100; i++){
        dynamic[i] = dynamic[i-1] + dynamic[i-5];
    }

    printf("%llu",dynamic[n]);
    return 0;
}
