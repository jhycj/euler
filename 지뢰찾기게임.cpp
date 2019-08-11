#include<stdio.h>

int main(){
    int m; //격자 행 크기
    int bomb; //지뢰의 갯수
    int p; //지뢰 x좌표
    int q; //지뢰 y좌표
    int arr[105][105] = {0,};
    int answer[9]={0,};
    int i; int j; int k;
    int dx[8] ={0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int x; int y; int count=0;

    scanf("%d", &m); //격자 갯수 입력 받음
    scanf("%d", &bomb); // 지뢰갯수 입력 받음

    for(i=0; i<bomb; i++){
        scanf("%d %d", &p, &q);
        arr[q][p] = 1;  //지뢰 있는 칸에는 1을 입력 받음
    }


    for(i=1; i<= m; i++){
        for(j=1; j<=m; j++){

            if(arr[i][j] == 0){ //지뢰 아닌 칸이네!
                for(k=0; k<8; k++){ //8방향 탐색 시작

                    x = j + dx[k];
                    y = i + dy[k];

                    if(arr[y][x]==1){ //지뢰 발견!
                        count++;
                    }
                }
                answer[count]= answer[count] + 1;
                count = 0;
            }
        }
    }

    for(i=8; i>=1; i--){
        if(answer[i] !=0){
            printf("%d %d", i, answer[i]);
            printf("\n");
        }
    }



    return 0;
}
