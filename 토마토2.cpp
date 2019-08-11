#include<stdio.h>
#define INF 987654321
int n;
int m;
int h;
int map[101][101][101];
int Q[3000000];
int rear;
int front;

void bfs (void){
    int i;
    int dz[6] = {0, 0, 0, 0, 1, -1};
    int dy[6] = {0, 1, 0, -1, 0, 0};
    int dx[6] = {1, 0, -1, 0, 0, 0};
    int z; int y; int x;
    int tz; int ty; int tx;

    front = 0;

    while(rear>front){
        z= Q[front];
        front++;
        y= Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<6; i++){
            tz = z+dz[i];
            ty = y+dy[i];
            tx = x+dx[i];

            if(tz>= 1 && tz<= h && ty>=1 && ty<=n && tx>=1 && tx<=m && map[tz][ty][tx] > map[z][y][x]+1){
                Q[rear] = tz;
                rear++;
                Q[rear]= ty;
                rear++;
                Q[rear] = tx;
                rear++;
                map[tz][ty][tx] = map[z][y][x] +1;
            }
        }
    }
}

int get_maximum(void){
    int i;
    int j;
    int k;
    int max;
    max = map[1][1][1];

    for(k=1; k<=h; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(max<=map[k][i][j]){
                    max = map[k][i][j];
                }
            }
        }
    }
    return max;
}

void get_answer(void){
    int answer;
    answer = get_maximum();

    if(answer==0){ // 처음부터 익어있는 상황
        printf("%d", 0);
    }
    else if(answer==INF){ //모두 익지 못하는 상황
        printf("%d", -1);
    }
    else{
        printf("%d", answer);
    }
}



int main(){
    int i; int j; int k;
    int tmp;
    int count = 0;
    int bar=0;
    scanf("%d %d %d", &m, &n, &h); //가로, 세로, 높이

    for(k=1; k<=h; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                scanf("%d", &tmp);
                if(tmp==0){ //아직 익지 않은 토마토
                    map[k][i][j] = INF;
                }
                else if(tmp==1){ //익은 토마토
                    map[k][i][j] = 0;
                    Q[rear] = k;
                    rear++;
                    Q[rear] = i;
                    rear++;
                    Q[rear] = j;
                    rear++;
                    count++;
                }
                else if(tmp==-1){
                    map[k][i][j] = -1;
                    bar++;
                }
            }
        }
    }

    bfs();
    get_answer();

    /*for(k= 1; k<=h; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                printf("%d ",map[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }*/


    return 0;
}
