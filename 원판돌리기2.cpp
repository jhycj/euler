#include<stdio.h>
#define INF 999999

int map[10][10][10][10];
int s1, s2, s3, s4;
int e1, e2, e3, e4;
int num_block;
int Q[80000];

void bfs(void){
    int rear;
    int front;
    int i; int j; int k; int l;
    int x, y, z, w;
    int tx, ty, tz, tw;
    int dx[8] = {1, -1, 0, 0, 0, 0, 0, 0};
    int dy[8] = {0, 0, 1, -1, 0, 0, 0, 0};
    int dz[8] = {0, 0, 0, 0, 1, -1, 0, 0};
    int dw[8] = {0, 0, 0, 0, 0, 0, 1, -1};

    rear = 0;
    front = 0;

    Q[rear] = s1;
    rear++;
    Q[rear] = s2;
    rear++;
    Q[rear] = s3;
    rear++;
    Q[rear] = s4;
    rear++;

    while(rear>front){

        x= Q[front];
        front++;
        y = Q[front];
        front++;
        z = Q[front];
        front++;
        w = Q[front];
        front++;

        for(i=0; i<8; i++){
            tx = (x+dx[i]+10)%10;
            ty = (y+dy[i]+10)%10;
            tz = (z+dz[i]+10)%10;
            tw = (w+dw[i]+10)%10;

            if(map[tx][ty][tz][tw]!= -1 && map[tx][ty][tz][tw] > map[x][y][z][w]+1){
                map[tx][ty][tz][tw] = map[x][y][z][w] +1;
                Q[rear] = tx;
                rear++;
                Q[rear] = ty;
                rear++;
                Q[rear] = tz;
                rear++;
                Q[rear] = tw;
                rear++;
            }
        }
    }
}


int main(){

    int i; int j; int k; int l;
    int tmp1; int tmp2; int tmp3; int tmp4;

    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            for(k=0; k<10; k++){
                for(l=0; l<10; l++){
                    map[i][j][k][l] = INF;
                }
            }
        }
    }

    scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
    map[s1][s2][s3][s4] = 0;
    scanf("%d %d %d %d", &e1, &e2, &e3, &e4);
    scanf("%d", &num_block);
    for(i=0; i<num_block; i++){
        scanf("%d %d %d %d", &tmp1, &tmp2, &tmp3, &tmp4);
        map[tmp1][tmp2][tmp3][tmp4] = -1;
    }
    bfs();

    if(map[e1][e2][e3][e4]==INF){
        printf("-1");
    }

    else{
        printf("%d", map[e1][e2][e3][e4]);
    }
    return 0;
}
