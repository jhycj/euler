#include<stdio.h>
int arr[7];
int n; // 사람수이자  배열의 크기    1<= n <= 7
int m; //아이스크림 수 {1, 2, 3, ... m} 1<=m<= 5
int answer;

void process(int level){
    int i;

    if(level>= n){
        answer++;
        for(i=0; i<n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    else{ //level<n
        for(i=1; i<=m; i++){
            arr[level] = i;
            process(level+1);
        }
    }
}



int main(){

    scanf("%d %d", &n, &m);
    process(0);
    printf("%d\n", answer);
}
