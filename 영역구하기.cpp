#include<stdio.h>
int map[100][100];
int n;
int m;
int K;
int answer;
int Q[20000];
int area[200];
int answer2;

void bfs(int sy, int sx){
    int i;
    int j;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int rear;
    int front;
    int y; int x;
    int ty; int tx;

    rear = 0;
    front = 0;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;

        map[y][x] = 1;

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(map[ty][tx]!= -1 && ty>=0 && ty< n && tx>=0 && tx< m){
                if(map[ty][tx]!= 1){
                    map[ty][tx] = 1; //방문했음
                    answer2++;
                    Q[rear] = ty;
                    rear++;
                    Q[rear] = tx;
                    rear++;
                }
            }
        }
    }

}

int main(){
    int i;
    int j;
    int k;
    int tmp[4];
    int answer_rear=0;
    int temp;

    scanf("%d %d %d", &n, &m, &K);

    for(k=1; k<=K; k++){
        scanf("%d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
        for(i= n-tmp[3]; i<= n-1-tmp[1]; i++){
            for(j= tmp[0]; j<= tmp[2]-1; j++){
                map[i][j] = -1;
            }
        }
    }


    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(map[i][j] == 0){
                answer2 = 1;
                bfs(i, j);
                answer++;
                area[answer_rear] = answer2;
                answer_rear++;
            }
        }
    }

    for(i=0; i<answer; i++){
        for(j=0; j<answer-1-i; j++){
            if(area[j]>= area[j+1]){
                temp = area[j];
                area[j] = area[j+1];
                area[j+1] = temp;
            }
        }
    }

    printf("%d\n", answer);
    for(i=0; i<answer; i++){
        printf("%d ", area[i]);
    }

    return 0;
}
