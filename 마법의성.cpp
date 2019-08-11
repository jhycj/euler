#include<stdio.h>
#define INF 1000000
int n;
int m;
int map1[1001][1001]; //입력 받는 행렬
int map2[1001][1001]; //bfs 돌려서 정보 입력 받을 행렬
int map3[1001][1001];
int count;
int index[1001][1001]; //index 저장

int Q[20000];

void answer(void){
    int i;
    int j;
    int sum=0;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            sum = sum + index[i][j];
        }
    }

    if(sum==0){
        printf("0 0\n");
    }
    else{
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(index[i][j] == 1){
                    printf("%d %d\n", i, j);
                    i = INF;
                    j =INF;
                }
            }
        }
    }
}

void bfs4(int ey, int ex){
    int front;
    int rear;
    int y;
    int x;
    int ty;
    int tx;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int i;

    front = 0;
    rear = 0;

    Q[rear] = ey;
    rear++;
    Q[rear] = ex;
    rear++;

    while(rear>front){
        y = Q[front] ;
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && map1[ty][tx] != -1 && map2[ty][tx] == map2[y][x]-1){
                map3[ty][tx] = INF;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}

void bfs3(int sy, int sx){
    int front;
    int rear;
    int y;
    int x;
    int ty;
    int tx;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int i;

    front = 0; rear= 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++ ;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i] ;

            if(ty>=1 && ty<=n && tx>= 1 && tx<=m && map3[ty][tx]>map3[y][x]+1){
                if(map1[y][x]==1 && map1[ty][tx]==1){
                    map3[ty][tx] = map3[y][x]+1;
                    Q[rear] = ty;
                    rear++;
                    Q[rear] = tx;
                    rear++;
                }
                else if(map1[y][x] == 0 && map1[ty][tx] ==0){
                    map3[ty][tx] = map3[y][x]+1;
                    Q[rear] = ty;
                    rear++;
                    Q[rear] = tx;
                    rear++ ;
                }

                else if(map1[y][x]==0 && map1[ty][tx] ==1){
                    map3[ty][tx] = map3[y][x]+1;
                    Q[rear] = ty;
                    rear++;
                    Q[rear] = tx;
                    rear++ ;
                    index[ty][tx] = 1;
                    count++;
                }
            }
        }
    }
}
void bfs(int sy, int sx){
    int front;
    int rear;
    int y;
    int x;
    int ty;
    int tx;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int i;

    front =0; rear =0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<=n && tx>=1 && tx<=m && map2[ty][tx]>map2[y][x]+1 && map1[ty][tx] <=1){ //map1은 장애물
                map2[ty][tx] = map2[y][x]+1;
                map1[ty][tx] = map1[ty][tx] + map1[y][x];
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
            }
        }
    }
}


int main(){
    int i;
    int j;
    int k;
    int ey;
    int ex;
    int sy;
    int sx;
    int answer2;

    scanf("%d %d", &n, &m);
    ey = 1;
    ex = m;
    sy = n;
    sx = 1;


    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &map1[i][j]);
            map2[i][j] = INF;
        }
    }

    map2[sy][sx] = 1;

    bfs(sy, sx); //map2를 변형시킴_ 장애물 없다고 가정하고 bfs 돌림.

    //answer2 = map2[ey][ex]; //두번 째 답 출력

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(map1[i][j]>=2){ //여기는 장애물을 2개 이상 뿌셔야 하므로 못지나감
                map1[i][j] = -1;
                map3[i][j] = -1;
            }
            else{
                map3[i][j] = INF;
            }
        }
    }
    map3[sy][sx] = 1;

    bfs3(sy, sx); // 장애물 2개 이상 가는 길은 map3에  -1 로 처리한 후  bfs를 실행함 .map3에는 장애물을 딱 한개만 부시도록 이동

    printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map3[i][j]);
        }
        printf("\n");
    }

    answer2 = map3[ey][ex];

    bfs4(ey, ex);

    printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map3[i][j]);
        }
        printf("\n");
    }




    /*printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map1[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map2[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map3[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", index[i][j]);
        }
        printf("\n");
    }*/

    for(k=0; k<count; k++){
        for(i=0; i<=n ; i++){
            for(j=0; j<=m; j++){
                if(index[i][j]==1 && map3[i][j] !=INF){
                    index[i][j] =0;
                }
            }
        }
    }
    /*printf("\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", index[i][j]);
        }
        printf("\n");
    }*/

    answer();
    printf("%d", answer2);

    return 0;
}
