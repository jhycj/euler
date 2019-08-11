#include<stdio.h>
int main(){
    int count;
    int V;
    int v;
    int E;
    int Q[105]={0,};
    int visit[105]={0,};
    int a[105][105] = {0,};
    int i; int j;
    int m; int n;
    int rear = 0;
    int front = 0;

    scanf("%d", &V);
    scanf("%d", &E);

    for(i=0; i<E; i++){
        scanf("%d %d", &m, &n);
        a[m][n] = a[n][m]= 1;

    } //인접행렬

    /*for(i=1; i<=V;i++){
        for(j=1; j<=V; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    */
    v=1;
    Q[rear] = v;
    rear++;
    visit[v] =1;

    while(rear >= front){

        v = Q[front];
        front++;

        for(i=1; i<=V; i++){
            if(a[v][i]==1 && visit[i] == 0){
                Q[rear] = i;
                rear++;
                visit[i] = 1;
            }
        }

    }


    count = 0;
    for(i=0;i<V;i++){
        if(Q[i]!=0){
            count++;
        }
    }
    printf("%d", count-1);

}
