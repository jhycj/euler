#include<stdio.h>

int n;//세로길이
int m;//가로길이
int sy; //시작점 y좌표
int sx; //시작점 x좌표
char tmp[102];
int arr[102][105];

int main(){
    scanf("%d %d %d %d", &n, &m, &sy, &sx);

    for(i=1; i<=n; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=m; j++){
            if(tmp[j]=='#'){
                a[i][j] = 1;
            }
        }
    }




    return 0;
}
