//3096 오염된 잔디 
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std; 

int map[1001][1001];

int bfs(int sy, int sx, int H, int W){
    int i, j;
    int ty, tx; 
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}; 
    int ret =1 ;
    int y, x; 
    queue<int> Q; 

    Q.push(sy);
    Q.push(sx); 
    while(!Q.empty()) {
        y = Q.front();
        Q.pop();
        x = Q.front();
        Q.pop(); 
        map[y][x] = -1 ; 

        for(i=0; i<8; i++){
            ty = y + dy[i]; 
            tx = x + dx[i]; 

            if(ty>=0 && ty<H && tx>=0 && tx<W){
                if(map[ty][tx] >0){
                    Q.push(ty); 
                    Q.push(tx); 
                    map[ty][tx] = -1 ; 
                }
            }
        }
    }
    return ret; 
} 


int main(){
    int ret = 0 ; 

    int R, C; //R: 세로, C: 가로 

    cin>> R>> C; 
    int i, j; 

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            cin>> map[i][j]; 
        }
    }
    
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(map[i][j] >0){
                ret += bfs(i, j, R, C); 
            }
        }
    }
     
    cout<<ret; 

    return 0; 
}