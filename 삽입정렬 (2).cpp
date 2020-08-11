#include<stdio.h>
int N;
int arr[100];

void insert_sort(int N, int* arr){

    int i;
    int front=1;
    int key;
    int tmp;

    while(front<N){
        key = arr[front]; //front =1 ;  key = arr[1] ;

        for(i=front-1; i>=0; i--){
            if(key<arr[i]){ //arr[i] == arr[front-1]
                tmp = arr[i]; // key == arr[front];
                arr[i] = key;
                arr[i+1] = tmp;
            }
        }
        for(i=0; i<N; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        front++;
    }
}


int main(){
    int i;
    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    for(i=0; i<N; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    insert_sort(N,arr);

    return 0;
}
