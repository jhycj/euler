//3093 CCTV 

#include <iostream> 
#include <queue> 

using namespace std;

int map[52][52]; 

int bfs(int H, int W, int sy, int sx){
    int ty, tx; 
    int y, x; 
    int dy[4] = {0, 1, 0, -1}; 
    int dx[4] = {1, 0, -1, 0}; 
    int i, j; 
    int ret= 1; 
    queue<int> Q; 

    Q.push(sy); 
    Q.push(sx); 

    while(!Q.empty()){
        y = Q.front() ;
        Q.pop(); 
        x = Q.front(); 
        Q.pop(); 

        map[y][x] = 0 ; 

        for(i=0; i<4; i++){
            ty = y + dy[i];
            tx = x + dx[i]; 

            if(ty>=0 && ty<=H && tx>=0 && tx<=W){
                if(map[ty][tx] == 1){
                    Q.push(ty); 
                    Q.push(tx); 
                    map[ty][tx] = 0;
                }
            }
        }

    }
    return ret; 

}


int main(){
    int W, H; 

    cin>> H>>W; 
    int i, j; 
    int ret = 0; 

    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            cin>> map[i][j] ; 
        }
    }
    /*
    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            cout<< map[i][j]; 
        }
        cout<<'\n';
    }
    */
    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            if(map[i][j] ==1 ){
                int sy = i; 
                int sx = j;
                ret += bfs(H, W, sy, sx);
            }
        }
    }
    cout<<ret; 


}