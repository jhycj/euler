#include <iostream> 
#include <algorithm> 
#include <queue> 

using namespace std; 


queue<int> InitializeQ(int S, queue<int> Q){

    for (int i=0; i<S-1 ; i++){

        int x = Q.front(); 
        Q.pop() ; 
        Q.push(x);    
    }
    return Q ; 
}

queue <int> delete_ele(int K, queue<int> Q) {

    for (int i=0; i<K-1; i++){

        int x= Q.front(); 
        Q.pop(); 
        Q.push(x); 
    }
    Q.pop(); 
    return Q; 
}



int main(){
    
    int N; 
    int S; 
    int K; 

    queue<int> Q; 

    cin >> N ;
    cin >> S ;
    cin >> K ; 
   

    for (int i=0; i<N; i++){

        Q.push(i+1); 
    }

    Q = InitializeQ(S, Q);
    
    while(Q.size() >1){
        Q = delete_ele(K, Q); 
    }

    cout << Q.front() << endl; 

    return 0;
}