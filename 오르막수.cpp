#include<stdio.h>

int N; //N은 1 이상 100 이하의 자연수
unsigned long long dynamic[11][101];

void initialize_dynamic(void){
    int i;
    for(i=1; i<=10; i++){
        dynamic[i][1] = 1;
    }
}

void get_dynamic_index(int n){
    int i;
    int j;

    for(i=1; i<=10; i++){
        for(j=1; j<=i; j++){
            dynamic[i][n] = (dynamic[i][n] + dynamic[j][n-1])%1000000000;
        }
    }
}




int main(){
    int i;
    int answer = 0;
    scanf("%d", &N);
    initialize_dynamic();
    for(i=2; i<=N; i++){
        get_dynamic_index(i);
    }

    for(i=1; i<=10; i++){
        answer= (answer+dynamic[i][N])%1000000000;
    }

    printf("%d", answer);
    return 0;
}
