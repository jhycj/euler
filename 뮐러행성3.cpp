#include<stdio.h>
int V ; //꼭짓점 갯수 입력
int E ; //edge 갯수 입력
int arr[10001][10001];
int Q[10000]; int rear;
int visit[10001];

void bfs(int v){
    int front;
    int i; int j;
    int vertex;

    front = 0; rear = 0;
    Q[rear] = v;
    rear++;

    while(rear!=front){
        vertex = Q[front];
        front++;
        visit[vertex] = 1;

        for(i=1; i<=V; i++){
            if(arr[vertex][i] ==1 && visit[i] ==0){
                Q[rear] = i;
                rear++;
                visit[i] = 1;
            }
        }
    }
}

int main(){

    int i; int j; int n; int m;
    int tmp;
    scanf("%d %d", &V, &E);
    for(i=0; i<E; i++){
        scanf("%d %d", &n, &m);
        arr[n][m] = 1;
        arr[m][n] = 1;
    }
    bfs(1);

    for(i=2; i<rear; i++){
        for(j=1; j<=rear-i; j++){
            if(Q[j]>Q[j+1]){
                tmp = Q[j+1];
                Q[j+1] = Q[j];
                Q[j] = tmp;
            }
        }
    }
    for(i=1; i<rear; i++){
        printf("%d\n", Q[i]);
    }
    return 0;
}
