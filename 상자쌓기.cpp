#include<stdio.h>

int main(){
    int N;
    int dynamic[22];
    int arr[22]; //정렬 후
    int a[22]; //입력 받은 데이터 저장
    int b[22]; //입력받은 데이터 저장
    int brr[22]; //정렬 후
    int i; int j; int k; int tmp; int answer;

    scanf("%d", &N); //상자 갯수 입력
    for(i=1; i<=N; i++){
        scanf("%d %d", &a[i], &b[i]);
    }

    for(i=1; i<=N; i++){
        arr[i] = a[i];
    }

    for(i=2; i<=N; i++){
        for(j=1; j<=N-i+1; j++){
            if(arr[j]<arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    } //arr 내림차순 정렬

    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            if(arr[i] == a[j]){
                brr[i] = b[j];
            }
        }
    }

    for(i=1; i<=N; i++){
        dynamic[i] = 1;
    } //dynamic 1로 초기화

    for(i=2; i<=N; i++){
        for(j=i-1; j>=1; j--){
            if(brr[j]>= brr[i]){
                if(dynamic[j]+1 > dynamic[i]){
                    dynamic[i] = dynamic[j] +1;
                }
            }
        }
    }

    answer= dynamic[1];

    for(i=2; i<=N; i++){
        if(answer <= dynamic[i]){
            answer = dynamic[i];
        }
    }

    printf("%d", answer);

    return 0;
}
