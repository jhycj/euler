#include<stdio.h>
#define INF 500

int n;
int m;
int map[22][22];
int dirty[22][22];
int Q[1000];
int count;
int answer;


void bfs(int sy, int sx){
    int i;

    int dy[4]={0, 1, 0, -1};
    int dx[4]={1, 0, -1, 0};
    int y; int x;
    int ty; int tx;
    int front=0; int rear=0;

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

            if(ty>=1 && ty<=n && tx>=1 && tx<=m  && map[ty][tx]>map[y][x]+1){
                map[ty][tx] = map[y][x]+1;
                Q[rear] = ty;
                rear++;
                Q[rear] = tx;
                rear++;
                answer++;
                if(dirty[ty][tx]==1){ //제거한 게 더러운 거였다!!
                    dirty[ty][tx] = 0; // 깨끗해졌다.
                    count--;
                    if(count==0){
                        front = rear+1;
                    }
                }
            }
        }
    }
}

int main(){
    int i; int j;
    int sy; int sx;
    char tmp[22];

    scanf("%d %d", &m, &n);

    for(i=1; i<=n; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=m; j++){
            if(tmp[j]=='.'){//깨끗한 격자
                map[i][j] = INF;

            }
            else if(tmp[j]=='*'){//더러운 격자
                map[i][j] = INF;
                dirty[i][j] = 1;
                count ++;
            }
            else if(tmp[j]=='x'){//장애물
                map[i][j] = -1;
            }
            else if(tmp[j]=='o'){//로봇이 있는 격자
                map[i][j] = 0;
                sy = i;
                sx = j;
            }
        }
    }
    bfs(sy,sx);


    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("%d", answer);

    return 0;

}
