#include<stdio.h>

int main(){
    int i; int j; int x;
    int count = 0;
    int S;
    int N;
    int arr[10001] ={0,};
    int b[100];
    int r[100];
    int q[100];

    scanf("%d", &S); // 슬롯 개수
    scanf("%d", &N); // 꽃 종류 수

    for(i=0; i<N; i++){
        scanf("%d", &r[i]); // 시작점
        scanf("%d", &b[i]); // 간격
    }

    for(i=0; i<N; i++){
        q[i] = (S-r[i]) / b[i];
    }

    for(i=0; i<N; i++){
        for(j=0; j<q[i]; j++){
            x = (b[i]*j) + r[i];
            arr[x] = arr[x] + 1;
        }
    }

    for(i=1; i<S+1; i++){
        if(arr[i] == 0){
            count = count + 1;
        }
    }

    printf("%d", count);
    return 0;
}
