#include<stdio.h>
#define INF 987654321

int sx; //start vertex;
int ex; // end vertex;
int vertex_num; //정점의 수;
int edge_num;
int adjoint[101][101] ;// 인접행렬
int dynamic[101];
int path[101];
int Q[100000];
int visit[101];
int answer[100000];


void Dijkstra(int sx){
    int i; int j;
    int v;
    int front; int rear;

    front = 0; rear = 0;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        v = Q[front] ;
        front++;
        visit[v] = -1;

        for(i=1; i<=vertex_num; i++){
            if(adjoint[v][i]>0 && visit[i] != -1){ // v와 인접해있고 아직 방문하지 않은 꼭짓점이면
                if(dynamic[i] >= dynamic[v] + adjoint[v][i]){
                    dynamic[i] = dynamic[v] + adjoint[v][i];
                    path[i] = v;
                    Q[rear]= i;
                    rear++;
                }
            }
        }
    }
}

void initialize_dynamic(int vertex_num){
    int i;
    for(i=1; i<=vertex_num; i++){
        dynamic[i] = INF;
    }
    dynamic[sx] = 0;
}

void find_path(void){

    int rear;
    int i;

    rear = 0;
    answer[rear] = ex;
    while(answer[rear]!= sx){
        rear++;  //rear = 1 이 됨
        answer[rear] = path[answer[rear-1]];
    }

    printf("%d\n", rear+1);
    for(i=rear; i>=0; i--){
        printf("%d ", answer[i]);
    }
}

int main(){
    int i; int j;
    int temp_s;
    int temp_e;
    int temp_value;

    scanf("%d %d %d", &vertex_num, &sx, &ex);
    scanf("%d", &edge_num);
    for(i=0; i<edge_num; i++){
        scanf("%d %d %d", &temp_s, &temp_e, &temp_value);
        adjoint[temp_s][temp_e] = temp_value;
    }

    initialize_dynamic(vertex_num);

    Dijkstra(sx);

    printf("%d\n", dynamic[ex]); //첫번째 답. 가장 짧은 경로 길이
    find_path();

    return 0;
}
