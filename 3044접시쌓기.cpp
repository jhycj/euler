#include<iostream>
using namespace std;


void func(int* arr, int* dynamic, int N){
    int i;
    int j;

    for(i=0; i<N; i++){
        for(j=0; j<i; j++){
            if(arr[j] > arr[i] && dynamic[j]+1 > dynamic[i]){
                dynamic[i] = dynamic[j]+1;
            }
        }
    }
}

int find_max(int*dynamic, int N){
    int ret = -1;
    for(int i=0; i<N; i++){
        if(ret < dynamic[i]){
            ret = dynamic[i];
        }
    }
    return ret;
}


int main(){
    int arr[5000];
    int dynamic[5000];

    int N;
    cin>> N;

    for(int i=0; i<N; i++){
        cin>>arr[i];
        dynamic[i] = 1;
    }

    func(arr, dynamic, N);

    cout<<find_max(dynamic, N);



    return 0;
}
