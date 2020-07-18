#include<iostream>

#include<stack>
using namespace std;
int map[21][21]={0,};
int visit[21][21] = {0,};
int R, C;
int sy, sx;
int N;
stack<int> S;

int dist2start(int y, int x){
    return abs(y-sy) + abs(x-sx);
}

void back_track(int y, int x, int prev_gold_count){
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int ty, tx;
    int gold_count= prev_gold_count;

    //visit[y][x] = 1;
    S.push(y);
    S.push(x);

    if(map[y][x]== 1 && prev_gold_count+1 == N){ //종료해야함
        cout<<(S.size()/2) ;
        cout<<endl;

        if(!S.empty()){
            S.pop();
            S.pop();
            //visit[y][x] = 1;
        }
        return;
    }
    else{
        if(map[y][x]==1){
            gold_count ++;
        }
        visit[y][x] = 1;
        for(int i=0; i<4; i++){
            ty = y+dy[i];
            tx = x+ dx[i];
            if(ty>=1 && ty<= R && tx>=1 && tx<=C && visit[ty][tx] != 1){
                back_track(ty, tx, gold_count);
                
            }
        }
        if(!S.empty() && gold_count<N){
            int top_x= S.top();
            S.pop();
            if(!S.empty()){
                int top_y = S.top();
                S.pop();
                visit[top_y][top_x] = 0;
            }


        }

    }

}


int main(){
    int tmp1, tmp2;

    cin>> R>>C;
    cin>>sy>>sx;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>> tmp1>> tmp2 ;
        map[tmp1][tmp2] = 1;
    }

    back_track(sy, sx,0);


    return 0;
}
