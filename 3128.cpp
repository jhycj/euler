#include<iostream> 
#include<algorithm>
#include<queue>
#include<vector>

using namespace std; 

int map[750][750] ;

int bfs(int sy, int sx, int H, int W){
    queue<int> Q; 
    int y, x, ty, tx; 
    int i;
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int ret = 1; 

    Q.push(sy);
    Q.push(sx); 

    while(!Q.empty()){
        y = Q.front();
        Q.pop();
        x = Q.front();
        Q.pop(); 
        map[y][x] = 0; 

        for(i=0 ; i<8; i++){
            ty = y + dy[i]; 
            tx = x + dx[i]; 

            if(ty>=0 && ty<H && tx>=0 && tx<W){
                if(map[ty][tx] == 1){
                    Q.push(ty); 
                    Q.push(tx);
                    map[ty][tx] = 0; 
                    ret++; 
                }
            }
        }
    }
    return ret; 
}



int main(){

    int W, H; 
    int i, j;
    cin >> W>> H ;
    
    string tmp; 
    for(i=0; i<H; i++){
        cin>> tmp;
        for(j=0; j<W; j++){
            if(tmp[j] == '.'){
                map[i][j] = 1; 
            }
            else{
                map[i][j] = 0; 
            }
        } 
    }

    vector<int> V; 

    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            if(map[i][j] == 1 ){
                V.push_back(bfs(i, j, H, W));
            }
        }
    }
    //cout<<V.size();

    cout<< *max_element(V.begin(), V.end()); 

    /*
    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            cout<< map[i][j] << '\t';

        }
        cout<<'\n';
    }
    */

}