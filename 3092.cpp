//3092. Red and Black 
#include <iostream>
#include <queue> 
using namespace std;

int map[22][22]; 

int bfs(int sy, int sx, int H, int W){
    queue<int> Q ;
    
    int dy[4] = {0,1,0,-1};
    int dx[4] = {1, 0, -1, 0}; 
    int i, j; 
    int ty, tx; 
    int y, x; 
    int ret = 1; 

    Q.push(sy); 
    Q.push(sx); 
    
    while(!Q.empty()){
        y = Q.front() ;
        Q.pop(); 
        x = Q.front(); 
        Q.pop();
        map[y][x] = 0 ;  

        for(i=0; i<4; i++){
            ty = y+dy[i]; 
            tx = x+dx[i]; 

            if(ty>=0 && ty< H && tx>=0 && tx<W && map[ty][tx] ==1 ){
                Q.push(ty);
                Q.push(tx); 
                map[ty][tx] = 0; 
                ret++; 
            }
        }

    }
    return ret; 


}

int main(){
    int W, H; 
    int i;
    int j; 
    int sy, sx; 
    string tmp;  

    cin>> W >> H; //W: 가로, H: 세로 

    for (i=0; i<H; i++){
        cin>> tmp ; 
        for(j=0; j<W; j++){
            if(tmp[j] == '.'){
                map[i][j] = 1 ; 
            }
            else if(tmp[j] == '#'){
                map[i][j] = 0  ; 
            }
            else if(tmp[j] == '@'){
                sy = i; 
                sx = j; 
            }
        }
    }

    int ret = bfs(sy, sx, H, W); 

    cout<< ret  ;
    /*
    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            cout<< map[i][j]; 
        }
        cout<<'\n'; 
    }
    */

    return 0; 
}