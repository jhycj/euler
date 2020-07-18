#include <iostream>
using namespace std;

int N, M;
int arr[2501];
int dynamic[2501] = {0,};
int sum_arr[2501];


void make_sum(int M){
    int sum = 0;
    for(int i=1; i<=M; i++){
        sum = sum+ arr[i];
        sum_arr[i] = sum;
    }
}

int calculate(int n){ //n가지 경우의 수 중 최소값 리턴
    int tmp ;
    int min = sum_arr[n] + (2*M);
    for(int i=1; i<n; i++){
        tmp =dynamic[i] + dynamic[n-i];
        if(tmp<min){
            min = tmp;
        }
    }
    return min;
}


void make_dynamic(int M){
    for(int i=1; i<=M; i++){
        int tmp = calculate(i);
        dynamic[i] = tmp;
    }
}


int main(){

    cin>> N>>M;
    arr[0] = M;

    for(int i=1; i<=N; i++){
        cin>> arr[i];
    }

    make_sum(N);
    make_dynamic(N);
    /*
    cout<<".,,,,."<<endl;
    for(int i=1; i<=N; i++){
        cout<<dynamic[i]<<endl;
    }
    */
    cout<< dynamic[N] - M;


    return 0;
}
