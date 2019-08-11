#include<stdio.h>
#define INF 99999999999

int N; //색종이 장수
int arr[2][105];
int dynamic[105];
int max;

void LIS(void){
    int i;
    int j;
    dynamic[0] = 0;
    arr[1][0] = INF;
    max = 0;

    for(i=1; i<= N; i++){
        for(j=0; j<=i-1; j++){
            if(arr[1][j]>= arr[1][i] && dynamic[i]<= dynamic[j]+1){
                dynamic[i] = dynamic[j] +1;
            }
        }
        if(max<=dynamic[i]){
            max = dynamic[i];
        }
    }
}

int main(){
    int temp1; int temp2;
    int tmp1; int tmp2;
    int i; int j;
    scanf("%d", &N);

    for(i=1; i<=N; i++){//1에서부터 시작하는 것
        scanf("%d %d", &tmp1, &tmp2); //temp1, temp2
        if(tmp1>=tmp2){
            arr[0][i] = tmp1;
            arr[1][i] = tmp2;
        }
        else{
            arr[0][i] = tmp2;
            arr[1][i]= tmp1;
        }
    }
    /*printf("\n");
    for(i=1; i<=N; i++){
        printf("%d ", arr[0][i]);
    }
    printf("\n");
    for(i=1; i<=N; i++){
        printf("%d ", arr[1][i]);
    }
    printf("\n");*/

    for(i=1; i<=N; i++){
        for(j=1; j<=N-i; j++){
            if(arr[0][j] <= arr[0][j+1]){//내름차순 정렬
                temp1 = arr[0][j];
                temp2 = arr[1][j];

                arr[0][j] = arr[0][j+1];
                arr[0][j+1] = temp1;

                arr[1][j] = arr[1][j+1];
                arr[1][j+1]= temp2;
            }
        }
    }

    /*for(i=1; i<=N; i++){
        printf("%d ", arr[0][i]);
    }
    printf("\n");
    for(i=1; i<=N; i++){
        printf("%d ", arr[1][i]);
    }

    printf("\n");*/
    LIS();

    printf("%d", max);


    return 0;
}
