#include<stdio.h>

int main(){

    int i; int j;
    int k; int l;
    int N; int M; int p;
    int max;
    int arr[100][100];
    int sum[100][100];

    scanf("%d", &N);
    scanf("%d", &M);

    p = N-M+1;


    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(i=0; i<p; i++){
        for(j=0; j<p; j++){
            sum[i][j] = 0;
        }
    }

    for(i=0; i<p; i++){
        for(j=0; j<p; j++){
            for(k=i; k<i+M; k++){
                for(l=j; l<j+M; l++){
                    sum[i][j] = sum[i][j] + arr[k][l];
                }
            }
        }
    }

    max = sum[0][0];

    for(i=0; i<p; i++){
        for(j=0; j<p; j++){
            if( max < sum[i][j]){
                max = sum[i][j];
            }
        }
    }

    printf("%d", max);

    return 0;
}
