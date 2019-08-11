#include<stdio.h>
int N; //정사각형 한 변의 길이
int stone[201][201];
int dynamic[201][201];
int answer[201];

void get_input(void){
    int i; int j;
    char tmp[202];

    scanf("%d", &N);
    //printf("%d\n", '1'-49);



    for(i=1; i<=N; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=N; j++){
            if(tmp[j]=='0'){
                stone[i][j] = 0;
            }
            else{
                stone[i][j] = 1;
            }
        }
    }

    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            printf("%d ", stone[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int i, j, k;
    int l;
    int y; int x;
    get_input(); //입력받는 함수

    dy[3] = {0, -1, -1};
    dx[3] = {-1, -1, 0};


    for(k=2; k<=N; k++){
        for(i=k; i<=N; i++){
            for(j=k; j<=N; j++){
                y = i;
                x = k;
                for(l=0; l)
            }
        }

    }



    return 0;
}
