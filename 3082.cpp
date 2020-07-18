#include <iostream> 
#include <queue> 
#include <vector> 

using namespace std; 
int X[1002][82] ; 

int bfs(int sy, int sx, int H, int W){

    queue<int> Q; 

    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0}; 
    int y; int x; 
    int ty; int tx; 
    int ret = 1; 

    Q.push(sy); 
    Q.push(sx) ; 

    while(!Q.empty()){

        y = Q.front() ; 
        Q.pop();
        x = Q.front(); 
        Q.pop(); 
        
        X[y][x] = 0 ; 
        for(int i=0; i<4; i++){

            ty = y+dy[i]; 
            tx = x+dx[i]; 

            if(ty>=1 && ty<=H && tx>= 1 && tx<=W && X[ty][tx] ==1){
                Q.push(ty); 
                Q.push(tx); 
                X[ty][tx] = 0; 
                ret ++; 
            }
        }
    }
    return ret; 
}


int main(){

    //1002  는 H, 82는 W
    int W, H; 
    int sy, sx; 
    int i; int j;
    int answer=0; 
    
    char tmp[82]; 
  

    cin>> W >> H ;
    for (i=1; i<= H; i++){
        cin >> tmp ;
        
        for (j=0; j< W; j++ ){
            if(tmp[j] == '.'){
                X[i][j+1] = 0; 
            }
            else {
                X[i][j+1] = 1;
            }

        }
    }  

    for(i=1; i<=H; i++){
        for(j=1; j<=W; j++){
            if(X[i][j]==1){
                int ret = bfs(i, j, H, W);
                if(ret>answer){
                    answer= ret; 
                }
            }
        }
    }

    cout<<answer; 


    return 0; 
}