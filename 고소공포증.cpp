#include<stdio.h>
int n; //세로
int m; //가로
int arr[210][210]; //목장 높이 입력 받는 행렬
int key;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1,-1};

int x; int y;

int main(){
    int i; int j; int k;
    int count=0;
    int tmp;
    int answer=0;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &arr[i][j]);
        }

    }

    for(i=2; i<=n-1; i++){
        for(j=2; j<=m-1; j++){
            key = 0;
            count = 0;
            tmp = arr[i][j];
            for(k=0; k<8; k++){
                y = i + dy[k];
                x = j + dx[k];
                if(tmp <= arr[y][x]){
                    count++;
                }
            }
            if(count==8){
                answer ++;
            }
        }
    }

    printf("%d", answer);


}
