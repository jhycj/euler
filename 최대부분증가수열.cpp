#include<stdio.h>



int main(){
    int a[1005];
    int dy[1005]={0,};
    int N; //입력받는 데이터 갯수
    int i; int j; int max;
    scanf("%d", &N);

    a[0] = 0;

    for(i=1; i<=N; i++){
        scanf("%d", &a[i]);
    } //배열 초기화


    for(i=1; i<=N;i++){
        for(j=0; j<i; j++){
            if(a[i]>a[j] && dy[j]+1>dy[i]){
                dy[i] = dy[j] + 1;
            }
        }
    }

    max = dy[0];
    for(i=0;i<N;i++){
        if(max<dy[i+1]){
            max = dy[i+1];
        }
    }
    printf("%d", max);


    return 0;
}
