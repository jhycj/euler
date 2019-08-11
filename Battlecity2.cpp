#define INF 900000
#include<stdio.h>

int n;
int m;
int sy;
int sx;
int ey;
int ex;
int dynamic[305][305];
int visit[305][305];
int Q[180005];

void bfs(int sy, int sx){
    int i;
    int rear=0;
    int front=0;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int tmp;
    int y;
    int x;
    int ty;
    int tx;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(front<rear){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];
            tmp = dynamic[y][x] + dynamic[ty][tx];
            if(dynamic[ty][tx] != -1 &&
                ty>=1 && ty<=n && tx>=1 && tx<=m &&
                dynamic )
        }
    }



}


int main(){
    char tmp[305];
    int i; int j;

    scanf("%d %d\n", &n, &m);

    for(i=1; i<=n; i++){
        scanf("%s", &tmp[1]);
        for(j=1; j<=m; j++){
            if(tmp[j]== 'Y'){
                sy = i;
                sx = j;
                dynamic[i][j] = 0;
            }
            else if(tmp[j] == 'T'){
                ey = i;
                ex = j;
                dynamic[i][j] = 1;
            }
            else if(tmp[j]=='S'){
                dynamic[i][j] = -1;
            }
            else if(tmp[j] =='B'){
                dynamic[i][j] = 2;
            }
            else if(tmp[j] =='R'){
                dynamic[i][j] = -1;
            }
            else if(tmp[j]=='E'){
                dynamic[i][j] = 1;
            }
        }
    }

    return 0;
}
