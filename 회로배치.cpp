#include<stdio.h>
#define INF 987654321
int N;
int map[51][51]; //회로 정보 담을 배열
int D[51][51]; //다익스트라 돌릴 배열
int visit[51][51]; //visit 행렬
int path[2][51][51]; //path 정보를 담을 배열  y=[0][i][j], x=[1][i][j]
int sy; int sx; int ey; int ex;
int K;
int M; //이미 배치된 회로 갯수
int Q[50000];
int Q_path[50000];
int min_y;
int min_x;
int answer;
int length_path;
int answer_path[50000];


void find_change_of_path(void){
    int tx; int ty;
    int cx; int cy;
    int rear=0;
    int front;
    front = length_path-1;

    cy = Q_path[front];//현재
    front--;
    cx = Q_path[front];
    front--;
    ty = Q_path[front]; //다음꺼
    front--;
    tx = Q_path[front];
    front--;

    answer_path[rear] = cy;
    rear++;
    answer_path[rear] = cx;
    rear++;

    while(front>0){
        if(cy==ty){ //cx != tx 라는 뜻
            cy = ty;
            cx = tx;
            ty = Q_path[front];
            front--;
            tx = Q_path[front];
            front--;
            if(cx==tx){ //cy!= ty 라는 뜻
                answer_path[rear] = cy;
                rear++;
                answer_path[rear] = cx;
                rear++;
            }
        }

        else {
            cy = ty;
            cx = tx;
            ty = Q_path[front];
            front--;
            tx = Q_path[front];
            front--;
            if(cy==ty){
                answer_path[rear] = cy;
                rear++;
                answer_path[rear] = cx;
                rear++;
            }
        }
    }
    answer_path[rear] = ey;
    rear++;
    answer_path[rear] = ex;
    rear++;
    answer = rear/2;
}
void get_path(void){
    int rear; int front;
    int prior_y;
    int prior_x;
    rear = 0 ; front = 0;

    Q_path[rear] = ex;
    rear++;
    Q_path[rear] = ey;
    rear++;

    while(prior_y!=sy && prior_x!=sx){
        prior_x = Q_path[front];
        front++;
        prior_y = Q_path[front];
        front++;

        Q_path[rear] = path[1][prior_y][prior_x];
        rear++;
        Q_path[rear] = path[0][prior_y][prior_x];
        rear++;
    }
    Q_path[rear] = sx;
    rear++;
    Q_path[rear] = sy;
    rear++;
    length_path = rear;
}
int check(void){
    int i; int j;
    int check_value = 0;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            if(D[i][j]==INF){//아직 더돌아야함
                check_value = 1;
                break;
            }
        }
    }
    return check_value;
}
void find_min_index(void){
    int i; int j;
    int min ;
    min= INF;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            if(visit[i][j]!=1 && D[i][j]<=min){
                min = D[i][j];
                min_y = i;
                min_x = j;
            }
        }
    }
}
void initialize_map(void){
    int i; int j;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            map[i][j]= 1;
        }
    }
}
void initialize_dynamic(void){
    int i; int j;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            D[i][j] = INF;
        }
    }
    D[sy][sx] = 1;
}
int max(int x, int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}
int min(int x, int y){
    if(x>y){
        return y;
    }
    else{
        return x;
    }
}

void Dijkstra(int sy, int sx){
    int i;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int ty; int tx;
    int y; int x;
    int front;
    int rear;

    rear = 0; front = 0;
    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;
    while(check()==1){
        y = Q[front];
        front++;
        x = Q[front];
        front++;
        visit[y][x] = 1; //방문했음.
        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];
            if(ty>=1 && ty<=N && tx>=1 && tx<=N){
                if(visit[ty][tx]!=1){//방문 아직 안했고
                    if(D[y][x]+map[ty][tx]<D[ty][tx]){ //바꾸면 더 작아진다!
                        D[ty][tx] = D[y][x] + map[ty][tx];
                        path[0][ty][tx] = y;
                        path[1][ty][tx] = x;
                    }
                }
            }
        }
        find_min_index();
        Q[rear] = min_y;
        rear++;
        Q[rear]= min_x;
        rear++;
    }
}

int main(){
    int i; int j; int k;
    int tmp;
    int tmp_y; int tmp_x;
    int prior_y; int prior_x;
    scanf("%d", &N);
    scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
    scanf("%d", &K);
    scanf("%d", &M);
    initialize_map();
    initialize_dynamic();
    for(i=0; i<M; i++){
        scanf("%d", &tmp);
        prior_y = 0;
        prior_x = 0;
        for(j=0; j<tmp; j++){
            scanf("%d %d", &tmp_y, &tmp_x);
            map[tmp_y][tmp_x] = K;

            if(prior_y == tmp_y){
                for(k=min(prior_x, tmp_x); k<=max(prior_x, tmp_x); k++){
                    map[tmp_y][k] = K;
                }
            }
            else if(prior_x == tmp_x){
                for(k= min(prior_y, tmp_y); k<=max(prior_y, tmp_y); k++){
                    map[k][tmp_x] = K;
                }
            }
            prior_y = tmp_y;
            prior_x = tmp_x;
        }
    }

    Dijkstra(sy, sx);
    printf("%d\n", D[ey][ex]);//첫번째 답
    get_path();
    find_change_of_path();
    printf("%d ", answer);
    for(i=0; i<answer*2; i++){
        printf("%d ", answer_path[i]);
    }


    return 0;
}
