#include<stdio.h>
#define INF 9876543
int sy; int sx;
int ey; int ex;
int answer;
int answer_y;
int answer_x;
int map1[1001][1001]; //정보 입력받는 행렬
int map0[1001][1001]; //장애물 정보 입력받는 행렬
int map2[1001][1001]; //bfs2 돌릴 행렬

int index[1000000][3];
int n;
int m;
int Q[2004002];
void block2(int count){
    int i; int j;
    int y; int x; int min;
    int ty; int tx;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    for(i=0; i<count; i++){
        y = index[i][0];
        x = index[i][1];
        min = INF;

        for(j=0; j<4; j++){
            ty = y+dy[j];
            tx = x+dx[j];

            if(ty>=1 && ty<= n &&tx>=1 && tx<=m && map0[ty][tx] != -1){

                if(min>map2[ty][tx]){
                    min = map2[ty][tx];
                }
            }
        }
        map2[y][x] = min+1;
        index[i][2] = index[i][2] + min+1;
    }
}
void block1(int count){
    int i; int j;
    int y; int x; int min;
    int ty; int tx;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    for(i=0; i<count; i++){
        y = index[i][0];
        x = index[i][1];
        min = INF;

        for(j=0; j<4; j++){
            ty = y+dy[j];
            tx = x+dx[j];

            if(ty>=1 && ty<= n &&tx>=1 && tx<=m && map0[ty][tx] != -1){

                if(min>map1[ty][tx]){
                    min = map1[ty][tx];
                }
            }
        }
        map1[y][x] = min+1;
        index[i][2] = index[i][2] + min+1;
    }
}
void bfs0(int sy, int sx){
    int rear;
    int front;
    int y; int x;
    int ty; int tx;
    int i; int j;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] ={1, 0, -1, 0};

    rear =0;
    front =0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y=Q[front];
        front++;
        x=Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m  &&map0[ty][tx]>map0[y][x]+1){
                map0[ty][tx] = map0[y][x]+1;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}
//map1 에서 bfs (장애물 모두 있다고 가정하고)
void bfs1(int sy, int sx){
    int rear;
    int front;
    int y; int x;
    int ty; int tx;
    int i; int j;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] ={1, 0, -1, 0};

    rear =0;
    front =0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y=Q[front];
        front++;
        x=Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m  &&map1[ty][tx]>map1[y][x]+1){
                map1[ty][tx] = map1[y][x]+1;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}
//map1 에서 bfs (장애물 모두 있다고 가정하고)
void bfs2(int sy, int sx){ //map2에서 bfs
    int rear;
    int front;
    int y; int x;
    int ty; int tx;
    int i; int j;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] ={1, 0, -1, 0};

    rear =0;
    front =0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y=Q[front];
        front++;
        x=Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m  &&map2[ty][tx]>map2[y][x]+1){
                map2[ty][tx] = map2[y][x]+1;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}
void find_min(int num){
    int i;
    answer = index[num-1][2];
    answer_y = index[num-1][0];
    answer_x = index[num-1][1];

    for(i=num-1; i>=0; i--){
        if(answer>=index[i][2]){
            answer = index[i][2];
            answer_y = index[i][0];
            answer_x = index[i][1];
        }
    }
}


int main(){
    int i; int j; int k;
    int count;
    count = 0;

    scanf("%d %d", &n, &m);
    sy = n;
    sx = 1;
    ey = 1;
    ex = m;

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &map1[i][j]);  //장애물 정보 입력받기

            if(map1[i][j]==1){

                index[count][0] = i;
                index[count][1] = j;
                count++;
                map1[i][j] = -1;
                map0[i][j] = -1;
                map2[i][j] = -1;
            }
            else if(map1[i][j]==0){
                map0[i][j] = INF;
                map1[i][j] = INF;
                map2[i][j] = INF;
            }
        }
    }

    map1[sy][sx] = 1;
    map2[ey][ex] = 0;
    map0[sy][sx] = 1;
    bfs1(sy, sx);
    block1(count);

    bfs2(ey, ex);
    block2(count);

    find_min(count); //answer 에 index[i][2] 값들의 최솟값이 저장되어있음
    bfs0(sy, sx);

    if(answer==0){
        answer = map0[ey][ex];
    }


    /*for(i=0; i<count; i++){
        printf("%d \n", index[i][2]);
    }*/
    if(map0[ey][ex] <= answer){
        printf("0 0\n");
        printf("%d", map0[ey][ex]);
    }

    else{
        printf("%d %d\n", answer_y, answer_x);
        printf("%d", answer);
    }

    return 0;
}
