#include<stdio.h>

int main(){
    int i; int j;
    int N; int count = 0;
    int arr[101] = {0,};

    scanf("%d", &N);

    for(i=1; i<= N; i++){
        for(j=1; j<= N/i; j++){

            if(arr[i*j]==0){
                arr[i*j] = 1;
            }
            else{
                arr[i*j] = 0;
            }
        }
    }

    for(i=1; i<=N; i++){
        if(arr[i]==1){
            count ++;
        }
    }

    printf("%d", count);

    return 0;
}
