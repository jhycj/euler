#include<stdio.h>
#define INF 999999999999

long long map[25][35];

int n;
int m;
int sy; int sx;
int ey; int ex;

void initialize_map(void){
    int i;
    for(i=sy; i<=n; i++){
        if(map[i][1] != -1){
            map[i][1] = 1;
        }
    }
    for(i=sx; i<=m; i++){
        if(map[1][i] != -1){
            map[1][i] = 1;
        }
    }
}

void bfs(int sy, int sx){

    int i; int j; int k;
    int dy[2] = {0, -1};
    int dx[2] = {-1, 0};
    int ty; int tx;

    for(i=sy; i<=n; i++){
        for(j=sx; j<=m; j++){//각 점에 대해서
            for(k=0; k<2; k++){
                ty = i+dy[k];
                tx = j+dx[k];
                if(map[i][j]!=-1 && ty>=sy && ty<= n && tx>= sx && tx<=m && map[ty][tx]!= -1){
                    map[i][j] = map[ty][tx]+map[i][j];
                }
            }
        }
    }
}



int main(){
    int i; int j;
    char tmp;
    scanf("%d %d\n", &n, &m);

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%c ", &tmp);

            if(tmp=='C'){
                map[i][j] = 1;
                sy = i;
                sx = j;
            }
            else if(tmp=='R'){
                map[i][j] = -1;
            }
            else if(tmp=='B'){
                ey = i;
                ex = j;
            }
        }
    }

    bfs(sy, sx);

    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }*/

    printf("%lld", map[ey][ex]);

    return 0;
}
