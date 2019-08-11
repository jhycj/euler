#include<stdio.h>

int Q[2][4];
int arr[5][8];
int curr[5]; // 현재 12시 방향을 누가 가르키고 있나 커서 index저장
int rear;


int check_right(int num){
    if(num+1<=4 &&  arr[num][(curr[num]+2)%8] != arr[num+1][(curr[num+1]+6)%8]){
        return num+1;
    }
    else{
        return 0;
    }
}

int check_left(int num){
    if(num-1>=1 && arr[num][(curr[num]+6)%8] != arr[num-1][(curr[num-1]+2)%8]){
        return num-1;
    }
    else{
        return 0;
    }
}

void find_rotate_list(int s_num, int s_direction){

    int front;
    int visit[5]={0,};
    int num; int direction;

    rear=0;
    front=0; //Q의 초기화

    Q[0][rear] = s_num;
    Q[1][rear] = s_direction;
    rear++;
    visit[s_num] = 1; //방문했음.

    while(rear>front){
        num = Q[0][front];  //현재 탐색중인 자석 번호
        direction = Q[1][front]; //현재 탐색 자석 방향
        front++;
        if(check_left(num)!=0 && visit[check_left(num)]!=1){ //반환값이 있고 방문 안했으면
            Q[0][rear] = check_left(num);  //rear 삽입
            Q[1][rear] = direction *(-1);
            rear++;
            visit[check_left(num)] = 1; //num의 왼쪽 방문 했음.
        }
        if(check_right(num)!=0 && visit[check_right(num)]!=1){ //반환값이 있고 방문 안했음
            Q[0][rear] = check_right(num); //rear 삽입
            Q[1][rear] = direction * (-1);
            rear++;
            visit[check_right(num)] = 1; //num의 오른쪽 방문 했음.
        }
    }
}

void rotate_unit(int num, int direction){ //커서가 수정됨
    if(direction==1){
        curr[num] = (curr[num] +7) % 8;
    }
    else if(direction==-1){
        curr[num] = (curr[num] +1) % 8;
    }
}

void rotate_whole(int num, int direction){
    int i;
    find_rotate_list(num, direction); //Q[2][4] 에 회전해야할 자석이 저장됨
    for(i=0; i<rear; i++){
        rotate_unit(Q[0][i], Q[1][i]);
    }
}

int main(){
    int answer;
    int i;
    int j;
    char tmp[10];
    int info[100][2];
    int N ; //회전 횟수

    for(i=1; i<=4; i++){
        scanf("%s", &tmp[0]);
        for(j=0; j<8; j++){
            if(tmp[j]=='0'){
                arr[i][j] = 0;
            }
            else{
                arr[i][j]= 1;
            }
        }
    }

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d %d", &info[i][0], &info[i][1]);
    }

    for(i=0; i<N; i++){
        rotate_whole(info[i][0], info[i][1]);
    }

    answer = arr[1][curr[1]]*1 + arr[2][curr[2]]*2 + arr[3][curr[3]]*4 + arr[4][curr[4]]*8;

    printf("%d", answer);

    return 0;
}
