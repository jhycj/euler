
#include<stdio.h>

int main(){

    int i;
    int N;
    int odd = 0 ;
    int even = 0;
    int arr[10000];

    scanf("%d\n", &N);

    for(i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }

    for(i=0; i<N; i++){

        if(arr[i] % 2 == 0){
            even = even + arr[i];
        }
        else{
            odd = odd + arr[i];
        }
    }
    printf("%d %d", even, odd);

    return 0;
}
