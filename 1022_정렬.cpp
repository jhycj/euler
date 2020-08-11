#include<iostream>
using namespace std; 





int main(){

    int N; 
    int arr[101];

    cin>> N; 
    for(int i=1; i<=N; i++){
        cin>> arr[i]; 
    }

    for(int i=1; i<=N; i++){
        cout<< arr[i]<<' ';
    }
    cout<<endl; 

    for(int i=1; i<=N-1; i++){
        for(int j=1 ; j<= N-i; j++ ){
            if(arr[j] >= arr[j+1]){
                int tmp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = tmp; 
            }
        }
    }

    for(int i=1; i<=N; i++){
        cout<< arr[i]<<' ';
    }
    cout<<endl; 

    return 0; 
}