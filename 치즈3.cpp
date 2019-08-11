#include<stdio.h>
int n; int m;
int arr[101][101];
int Q[20000];
int sum;
int count_cheese;

void get_count_cheese(void){
    int i; int j;
    count_cheese = 0;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j] == 1){
                count_cheese ++;
            }
        }
    }
}

int get_sum(void){
    int i; int j;
    sum = 0;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            sum= sum+arr[i][j];
        }
    }
    return sum;
}

void bfs(int sy, int sx){
    int i;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int y; int x;
    int ty; int tx;
    int rear; int front;

    rear = 0; front = 0 ;

    Q[rear] = sy;
    rear++;
    Q[rear] = sx;
    rear++;

    while(rear>front){
        y = Q[front];
        front++;
        x = Q[front];
        front++;
        arr[y][x] = -1; //외부공기라고 표시 (일종의 visit)

        for(i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+dx[i];

            if(ty>=1 && ty<= n && tx>=1 && tx<=m){
                if(arr[ty][tx]==0){//4방향 돌았는데 공기이면
                    arr[ty][tx] = -1; //-1로 바꿔서 외부공기인거 알려주기
                    Q[rear] = ty;
                    rear++;
                    Q[rear] = tx;
                    rear++;
                }

                else if(arr[ty][tx]==1){ //4방향 돌았는데 치즈면
                    arr[ty][tx] = -2; //사라지는 치즈임
                }
            }
        }
    }
}

void after_bfs(void){
    int i; int j;
    count_cheese = 0;
 //bfs 실행하고 나면 외부공기는 -1, 내부공기는 0이고, 없어질 치즈는 -2이고 살아있는 치즈는 1로 표시됨
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0; //공기로 바꿈
            }
            else if(arr[i][j] ==-2){
                arr[i][j] = 0; //공기로 바꿈
            }
        }
    }
}


int main(){
    int answer1; //치즈가 녹는데 걸리는 시간
    int answer2;//녹기 1시간 전 치즈의 갯수
    int i; int j;
    int after_bfs_sum;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &arr[i][j]); //치즈는 1, 공기는 0,
        }
    }
    after_bfs_sum = 1;
    count_cheese = 1;
    while(after_bfs_sum!=0){
        bfs(1,1);
        after_bfs();
        answer1++;
        get_count_cheese();
        if(count_cheese!=0){
            answer2 = count_cheese;
        }

        after_bfs_sum=get_sum(); //arr 값들 다 더했을 때
    }

    printf("%d\n", answer1);
    printf("%d\n", answer2);

    return 0;
}
