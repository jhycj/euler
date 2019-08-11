#include<stdio.h>


int a[105][105]={0,}; // matrix
int group[105]={0,}; //
int V; // number of vertices
int count;
int Q[105]; // queue

void bfs(int s){
    //s means start vertex index
    int rear = 0;
    int front = 0;
    int v; int i;

    Q[rear] = s; //큐 초기화
    rear++;

    while(front!= rear){
        v = Q[front]; // queue pop
        front++; // queue pop

        for(i=1; i<=V; i++){ // why i starts from 1? not 0?
            if(a[v][i]==1 && group[i] ==0){
                Q[rear] = i; //queue push
                rear++; 
                group[i] = count;
                count++;// queue push
            }
        }
    }
}

///////////////////////////////////////////////////////
/////////////////////// from ohilho ///////////////////
///////////////////////////////////////////////////////

void bfs2(int s){
    //s means start vertex index
    int rear = 0;
    int front = 0;
    int v; int i;
    Q[rear] = s; //큐 초기화
    rear++;
    while(front!= rear){
        v = Q[front]; // queue pop
        front++; // queue pop
        for(i=1; i<=V; i++){
            if(a[v][i]==1){
                if(group[i] != count){ // prevent infinite loop
                    Q[rear] = i; //queue push
                    rear++; // queue push
                    group[i] = count;
                }
            }
        }
    }
}
///////////////////////////////////////////////////////
//////////////////////////END /////////////////////////
///////////////////////////////////////////////////////

int main(){


    int i; int j;
    int from; int to;
    count = 1;
    scanf("%d", &V);

    while(1){
        scanf("%d %d", &from, &to);
        if(from==0 && to==0){
            break;
        }
        else{
            a[from][to] = a[to][from] = 1;
        }
    } // 인접행렬 입력 받음

    bfs(1);
    for(i=1; i<=V; i++){
        printf("%d ",group[i] );
    }

    /*for(i=1; i<=V; i++){

        if(group[i]==0){
            count++;
            bfs(i);
        }
    }

    for(i=1; i<=V; i++){
        printf("%d ",group[i] );
    }
    */
    return 0;
}
