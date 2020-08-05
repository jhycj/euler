#include<iostream>

using namespace std; 

int N; //학생수 
int M; //아이스크림 수 
int arr[8] ; 
int count = 0; 

void process(int level){
    int i; 

    if(level> N){
        for(int i=1; i<=N; i++){
            cout<< arr[i] <<' '; 
        }
        printf("\n");
        count++;
    }

    else{
        for(int i=1; i<=M; i++){
            arr[level] = i;
            process(level+1); 
        }
    }

}
int main(){

    cin>> N>>M; 

    process(1);
    cout<<count;
    return 0; 
}