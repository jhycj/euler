#include<stdio.h>

int main(){

    int N; int i;
    int max;
    int index;
    int arr[20000];
    int count[20000];

    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    count[0] = 1;

    for(i=0; i<N-1; i++){
        if(arr[i] == arr[i+1]){
            count[i+1] = count[i] + 1;
        }
        else{
            count[i+1] = 1;
        }
    }

    max = count[0];
    index = 0;

    for(i=0; i<N; i++){
        if(max < count[i]){
            max = count[i];
            index = i;
        }
    }

    printf("%d", arr[index]);

    return 0;
}
