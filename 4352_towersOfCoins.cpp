#include<iostream>

using namespace std ;
int arr_M[50];
char answer_M[50];
int K, L, M; // K<L<M
char arr[1000001];


void make_answer(int n){
    int N = arr_M[n];

    arr[1] = 'A';
    arr[K] = 'A';
    arr[L] = 'A';

    for(int i=2; i<K; i++){
        if(arr[i-1] == 'A'){
            arr[i] = 'B';
        }
        else{
            arr[i] = 'A';
        }
    }

    for(int i=K+1 ; i< L; i++){

        if(arr[i-1] == 'A' && arr[i-K] == 'A'){
            arr[i] = 'B';
        }
        else{
            arr[i] = 'A';
        }
    }
    for(int i =L+1; i<= N; i++){
        if(arr[i-1] == 'A' && arr[i-K] == 'A' && arr[i-L] == 'A'){
            arr[i] = 'B' ;
        }
        else{
            arr[i] = 'A';
        }
    }

}





int main(){

    //int K, L, M;
    cin>> K>>L>>M;
    for(int i=0; i<M; i++){
        cin>> arr_M[i];
    }

    for(int i=0; i<M; i++){
        make_answer(i);
        cout<<arr[arr_M[i]];
    }


    return 0;
}
