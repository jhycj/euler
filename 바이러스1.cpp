#include<stdio.h>

int arr[105][105];
int Q[10000];
int visit[105];

int main(){
    int i; int m; int n; //m은 행번호 n은 열번호
    int E;
    int V;
    int rear; int front;
    int v; //현재 탐색 꼭짓점

    scanf("%d\n", &V);
    scanf("%d\n", &E);

    for(i=0; i<E; i++){
        scanf("%d %d", &m, &n);
        arr[m][n] = arr[n][m] = 1;
    } //인접행렬 만들기

    rear = 1;
    Q[rear] = 1;
    rear++;
    front=0;  //큐의 초기화


    while(rear-front!=1){
        front ++;
        v = Q[front]; //꼭짓점 v를 방문하겠다.
        visit[v] = 1;
        for(i=1; i<=V; i++){
            if(arr[v][i]==1 && visit[i]==0){//인접해있고 아직 방문하지 않은 꼭짓점이다!
                Q[rear] = i;
                rear++;
                visit[i] = 1;
            }//꼭짓점 v랑 인접한 꼭짓점 Q에다가 입력.
        }
    }

    printf("%d", rear-2);

    return 0;
}
