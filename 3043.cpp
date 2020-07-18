#include <iostream> 
#include <vector> 
#include<algorithm> 

using namespace std; 

vector<int> dynamic_f (vector<int>V, vector<int> dV, int N){

    int i;
    int j;  

    for(i=1; i<=N; i++){
        int max = 0 ; 

        for(j=0; j<i; j++){
            if(V[j] < V[i]){
                if(max <= dV[j]+1 ){
                    max = dV[j] + 1; 
                }
            }
        }
        dV[i] = max; 
    }
    return dV;
}



int main(){
    int N; //사람 수 
    vector<int> V ;
    vector <int> dynamicV; 

    int tmp;

    cin >> N; 
    V.push_back(0);
    dynamicV.push_back(0);

    for(int i=0; i<N; i++){
        cin >> tmp ;  
        V.push_back(tmp); 
        dynamicV.push_back(0); 
    }

    vector<int> retV = dynamic_f(V, dynamicV, N); 

    int answer= * max_element(retV.begin(), retV.end()); 
    cout<<answer;
    /*test
    for(int i= 0; i<N; i++){
        cout<<V[i]<< endl; 
    }
    */
    return 0; 
}