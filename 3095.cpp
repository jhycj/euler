//3095.cpp 단지 번호 붙이기 
#include<iostream> 
#include<queue> 
#include<vector> 
#include<algorithm>

using namespace std; 

int map[25][25]; 

int bfs(int sy, int sx, int H, int W){
    int ty, tx;
    int y, x; 
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0}; 
    int ret = 1; 
    int i, j;

    queue<int> Q; 
    Q.push(sy); 
    Q.push(sx); 

    while(!Q.empty()){
        y  = Q.front(); 
        Q.pop();
        x = Q.front(); 
        Q.pop(); 

        map[y][x] = 0; 

        for(i=0; i<4; i++){
            ty = y+ dy[i]; 
            tx = x+ dx[i]; 

            if(ty>=0 && ty<H && tx>=0 && tx<W){
                if(map[ty][tx] ==1){
                    ret++; 
                    map[ty][tx]=0; 
                    Q.push(ty); 
                    Q.push(tx); 

                }
            }
        }
    
    }
    return ret; 

}


int main(){
    int i, j; 
    string tmp; 
    int N; 
    cin>> N; 
    vector<int> X; 

    for(i=0; i<N; i++){
        cin>>tmp; 
        for(j=0; j<N; j++){
            if(tmp[j] == '0'){
                map[i][j] = 0;
            }
            else{
                map[i][j] = 1; 
            }
        }
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(map[i][j] == 1){
                int tmp =bfs(i, j, N, N);
                X.push_back(tmp); 
            }
        }
    }
    sort(X.begin(), X.end()); 

    cout<< X.size()<< '\n';

    for(i=0; i<X.size(); i++){
        cout<<X[i]<<'\n';
    }
}