#include<stdio.h>

int main(){
    int x; int y;
    int i; int j; int k;
    int N; int M;
    int count = 0;
    char a[102][102];
    int b[102][102] ;
    int dy[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
    int dx[8] = {0, +1, +1, +1, 0, -1, -1, -1};

    scanf("%d %d", &N, &M);

    for(i=0; i<=102; i++){
        for(j=0; j<=102; j++){
            b[i][j] = 0;
        }
    }

    for (i=1; i<=N; i++){
            scanf("%s", &a[i][1]);
    }

    if(i==0 || i==N+1 || j==0 || j==M+1){
        a[i][j] = 'a';
    }


    for(i=1; i<=N; i++){
        for(j=1; j<=M; j++){

            if(a[i][j] == '.'){
                for(k=0; k<8; k++){
                    x = i + dx[k];
                    y = j + dy[k];
                    if(a[x][y]=='*'){
                        count = count + 1;
                    }
                }
                b[i][j] = count;
                count = 0;
            }
        }
    }


    for(i=1; i<=N; i++){
        for(j=1; j<=M; j++){
            if(a[i][j]=='*'){
                printf("*");
            }
            else{
                printf("%d", b[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
