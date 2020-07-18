//3083 홍수피해 
#include <iostream> 
#include<queue> 

using namespace std;
queue<int> Q ; 
int X[101][101];

int bfs(int sy, int sx, int N, int M){
    int dy[4] = {0,1,0,-1}; 
    int dx[4] = {1,0,-1,0}; 
    int ty, tx; 
    int y, x; 
    int ret=1; 

    Q.push(sy); 
    Q.push(sx); 
    while(!Q.empty()){  
        y = Q.front(); 
        Q.pop();
        x = Q.front(); 
        Q.pop(); 

        X[y][x] = -1;
        for(int i=0; i<4; i++){
            ty = y+dy[i]; 
            tx = x+dx[i]; 
            if(ty>=0 && ty<N && tx>=0 &&tx<M && X[ty][tx]==1){
                ret++;
                Q.push(ty);
                Q.push(tx);
                X[ty][tx] = -1;  
            }       
        }
    }
    return ret; 
}


int main(){
    int answer = 0; 
    int N, M, K; 
    int ret;
    int tmpx, tmpy; 
    cin>> N>>M>>K; 
    for (int i=0; i<K; i++){
        cin>> tmpy>>tmpx; 
        X[tmpy-1][tmpx-1] = 1;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(X[i][j]==1){
                ret = bfs(i,j, N,M);
                if(answer<ret){
                    answer = ret; 
                }
            }
        }
    }
    cout<<answer; 

}


/*
int** make2Array(int N, int M){
    int** X = new int*[N]; 
    
    for(int i=0; i<M; i++){
        X[i] = new int[M];
    }
    return X; 
}

int main(){
    int N, M, K;
    int tmpX; int tmpY;
    cin>> N >> M>> K; 
    int ** X = make2Array(N,M); 

    for (int i=0; i<K; i++){
        cin>> tmpY>> tmpX; 
        X[tmpY][tmpX] = 1;  
    }

    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<X[i][j];
        }
        cout<<endl;
    }

}
*/ 

