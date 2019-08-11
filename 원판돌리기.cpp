#include<stdio.h>
int answer;
int start[4];
int end[4];
int num_check;
int check_list[10000][4];
int Q[40000];


int is_it_answer(int x1, int x2, int x3, int x4){
    int R = 0 ;
    if(x1== end[0] && x2 == end[1] && x3 == end[2] && x4 == end[3]){
        R = 1;
    }
    return R;
}

int is_in_check_list(int x1, int x2, int x3, int x4){
    int R=0;
    for(i=0; i<num_check; i++){
        if(x1 == arr[i][0] && x2 == arr[i][1] && x3 == arr[i][2] && x4 == arr[i][3]){
            R=1;
            break;
        }
    }
    return R;
}


void bfs(void){
    int rear;
    int front;
    int current[4];
    int tmp[4];

    rear = 0; front = 0;
    answer = 0 ;
    Q[rear] = start[0];
    rear++;
    Q[rear] = start[1];
    rear++;
    Q[rear] = start[2];
    rear++;
    Q[rear] = start[3];
    rear++;

    while(rear>front){

        current[0] = Q[front];
        front++;
        current[1] = Q[front];
        front++;
        current[2] = Q[front];
        front++;
        current[3] = Q[front];
        front++;

        for(i=0; i<4; i++){
            tmp[i] = current[i];
        }

        for(i=0; i<4; i++){
            for(j=0; j<2; j++){
                if(j==0){
                    tmp[i] = (tmp[i] + 1) %10 ;
                }
                else if(j==1){
                    tmp[i] = (tmp[i] -1) %10;
                }

                if(is_in_check_list(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]) ==0
                    && is_it_{ //해도 된다는 뜻
                    Q[rear] = tmp[0];
                    rear++;
                    Q[rear] = tmp[1];
                    rear++;
                    Q[rear] = tmp[2];
                    rear++;
                    Q[rear] = tmp[3];
                    rear++;
                }
            }
        }
    }
}



int main(){

    int i;
    int j;

    for(i=0; i<4; i++){
        scanf("%d", &start[i]);
    }

    for(i=0; i<4; i++){
        scanf("%d", &end[i]);
    }

    scanf("%d", &num_check);

    for(i=0; i<num_check; i++){
        for(j=0; j<4; j++){
            scanf("%d", &check_list[i][j]);
        }
    }

    for(i=0; i<num_check; i++){
        for(j=0; j<4; j++){
            printf("%d ", check_list[i][j]);
        }
        printf("\n");
    }



    return 0;
}
