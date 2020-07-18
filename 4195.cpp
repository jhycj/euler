#include<iostream> 
#include<queue> 
#include<vector> 

using namespace std; 

queue<int> InitializeQ(int N, vector<int> V, queue<int> Q){

    int i;
    for (i=0; i<N; i++){
        Q.push(i+1); 
    }
    return Q;
}

queue<int> delete_element(vector<int> V, queue<int> Q){

    int vector_size  = V.size() ; 
    int i; 
    int v_pointer = 0; 

    while(Q.size()>1 ){ 
    
        int x = V[v_pointer % vector_size];  
        
        for (i=0; i<x-1; i++){
            int tmp = Q.front(); 
            Q.pop();
            Q.push(tmp); 
        }

        Q.pop(); 
        v_pointer ++; 
    }
    
    return Q; 
}




int main(){

    int N; 
    int L; 
    vector<int> V; 
    queue<int> Q; 

    int x;

    cin >> N >> L ; 
    
    for (int i=0; i<L; i++){
        cin >> x; 
        V.push_back(x) ; 

    } 

    Q = InitializeQ(N, V, Q); 
    Q = delete_element(V, Q); 


    cout<<Q.front()<< endl; 
  
    return 0;
}