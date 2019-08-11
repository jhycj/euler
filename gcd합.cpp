#include<stdio.h>

int Euclid(int x, int y){
    int r;
    while(y!=0){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main(){

    int i; int j;
    int N;
    int arr[100];
    long long sum = 0;

    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    for(i=0; i<N-1; i++){
        for(j=i+1; j<N; j++){
            sum = sum + Euclid(arr[i], arr[j]);
        }
    }

    printf("%lld\n", sum);
    return 0;
}
