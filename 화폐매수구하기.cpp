#include<stdio.h>

int main(){
    int count = 0;
    int M; // 입력받는 돈
    int m; // 계산 중간에 나오는 돈
    int i; int j;
    int arr[8]={5000, 1000, 500, 100, 50, 10, 5, 1};
    int b[8];

    scanf("%d", &M);

    m = M;

    for(i=0; i<8; i++){

        if(m / arr[i] !=0){
            count = count + (m / arr[i]);
            m = m % arr[i];
        }
    }

    printf("%d", count); 

}
