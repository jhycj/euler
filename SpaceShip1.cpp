#include<stdio.h>
int V;
int Q[105];
int group[105];
int count;
int a[105][105];

void bfs(int s){
    int i;
    int rear;
    int front;
    int v; //탐색중인 vertex
    rear = 0; front = 0;
    Q[rear] = s;
    rear++;

    while(front!= rear){
        v = Q[front];
        group[v] = count;
        front++;
        for(i=1; i<= V; i++){
            if(a[v][i] == 1 && group[i]==0){
                Q[rear] = i;
                rear++;
                group[i] = count;
            }
        }
    }

}

int main(){
    int from; int to;
    int i; int j;

    scanf("%d", &V);
    while(1){
        scanf("%d %d", &from, &to);

        if(from==0 && to==0){
            break;
        }

        a[from][to] = a[to][from] = 1;
    }

    for(i=1; i<= V; i++){
        if(group[i]==0){
            count++;
            bfs(i);
        }
    }


    printf("%d\n", count);
    for(i=1; i<=count; i++){
        for(j=1; j<=V; j++){
            if(group[j]==i){
                printf("%d ",j);
            }
        }
        printf("\n");
    }

    return 0;
}
