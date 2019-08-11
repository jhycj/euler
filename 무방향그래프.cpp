#include<stdio.h>

int main(){

    int i; int j;
    int V;
    int E;
    int from; int to;
    int a[105][105] = {0,}; //인접행렬

    scanf("%d", &V);
    scanf("%d", &E);
    for(i=0; i<E; i++){
        scanf("%d %d", &from, &to);
        a[from][to] = a[to][from] = 1;
    }

    //for(i=1; i<=V; i++){
    //    a[i][i] = 0;
    //}

    for(i=1; i<=V; i++){
        for(j=1; j<=V; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    return 0;
}
