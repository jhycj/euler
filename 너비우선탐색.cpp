#include<stdio.h>
int main(){

    int V; //정점
    int v; // 현재 꼭짓점
    int N; //시작

    int Q[25];
    int visit[25] = {0,};
    int i; int j;
    int rear = 0;
    int front = 0;

    int a[21][21]; //인접행렬

    scanf("%d %d", &V, &N);

    for(i=1; i<=V; i++){
        for(j=1; j<=V; j++){
            scanf("%d", &a[i][j]);
        }
    }

    /*for(i=1; i<=V; i++){
        for(j=1; j<=V; j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
    }*/

    //큐의 초기화
    Q[rear] = N;
    rear++;
    visit[N] = 1;

    while(rear!= front){
        v = Q[front];
        front++;

        for(i=1; i<=V; i++){
            if(visit[i]==0 && a[v][i]==1){
                Q[rear] = i;
                rear++;
                visit[i] = 1;
            }
        }
    }

    for(i=0; i<V; i++){
        printf("%d ", Q[i]);
    }




    return 0;
}
