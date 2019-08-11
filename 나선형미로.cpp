#include<stdio.h>
int main(){
    int n;
    int sum = 0;
    int i; int j;
    int x; int y; int key;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int a[105][105];

    scanf("%d", &n);

    for ( i = 0; i < 105; i++) {
        for ( j = 0; j < 105; j++) {
            a[i][j] = 0;
            if(i==0 || i==n+2 || j==0 || j==n+2){
                a[i][j] = -1;
            }
        }
    }




    sum = n*(n+1)/2;

    x = 1; y =1; key = 0;

    for(i=0; i<sum; i++){

        a[y][x] = (i%9)+1;

        if(a[y+2*dy[key]][x+2*dx[key]] != 0){
            key = (key+1) % 4;
        }

        x = x+dx[key];
        y = y+dy[key];
    }

    for(i=1; i<= n; i++){
        for(j=1; j<=n; j++){
            if(a[i][j]!=0){
                printf("%d ", a[i][j]);
            }
            else{
                printf("  ");
            }
        }
        if(i<n){
            printf("\n");
        }
    }

    return 0;
}
