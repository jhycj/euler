#include<iostream>
#include<stack>

using namespace std;

int R, C;
int map[114][78] = {0,};
int visit[114][78] = {0,};
stack<int> S ;
stack<int> A;
int ok = 0;

void back_track(int y, int x){

    int ey = R;
    int ex = C;

    int ty, tx;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    S.push(y);
    S.push(x);

    visit[y][x] = 1;

    if(y == ey && x == ex){ //들어온 좌표가 종료 지점 이면
        ok = 1;
        return ;
    }
    if (ok== 1){
        return;
    }
    if(ok == 0){
        for(int i=0; i<4; i++){

            if(ok==0){
                ty = y+dy[i];
                tx = x+ dx[i];

                if(ty>=1 && ty<=R && tx>=1 && tx<=C){
                    if(visit[ty][tx] == 0 && map[ty][tx] != 1){ //방문 안했고 장애물 없을 때
                        back_track(ty, tx);
                    }
                }
            }
        }
    }

    if(ok==0){
        S.pop();
        S.pop();
    }
}

int main(){
    string tmp;
    cin>> R>>C ;
    for(int i=1; i<=R; i++){
        cin>> tmp;
        for(int j=0; j<C; j++){
            if(tmp[j]=='*'){
                map[i][j+1] = 1;
            }
        }
    }
    back_track(1,1);

    while(!S.empty()){
        int tmp_x = S.top();
        S.pop();
        int tmp_y = S.top();
        S.pop();

        A.push(tmp_x);
        A.push(tmp_y);
    }

    while(!A.empty()){
        cout<<A.top()<<' ';
        A.pop();
        cout<<A.top()<<endl;
        A.pop();
    }



    return 0;
}
