//전력 위기 
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
queue<int> Q; 

queue<int> initQ(int N){
    queue<int> Q; 
    for(int i=1; i<=N; i++){
        Q.push(i);
    }
    return Q;
}

int func(int N, int M){
    int ret; 
    int i;

    queue<int>Q = initQ(N);
    
    Q.pop(); 

    while(!Q.empty()){
        for(i=0; i<M-1; i++){
            int tmp = Q.front();
            Q.pop(); 
            Q.push(tmp);
        } 
        ret = Q.front();
        Q.pop();
    }
    
    return ret; 
}


int main(){
    int N; //지역 개수 
    int ret; 
    int i;
    int answer;
    cin>> N; 

    for(i=1; true; i++){
        ret = func(N,i); 
        if(ret == 13){
            answer = i;
            break; 
        }
    }
    cout<< answer; 
    return 0;
}