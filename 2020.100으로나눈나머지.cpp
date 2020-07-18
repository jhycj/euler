#include<iostream>
using namespace std;

int make_answer(int N){
    int answer[1001] ;
    int ret;
    answer[0] = 0 ;
    answer[1] = 2;

    answer[N] = (answer[N-1]*2 ) % 100;

    ret = answer[N];

    return ret;
}


int main(){
    //int answer[1001] ;
    int N;
    int answer;
    cin>> N;
    answer = make_answer(N);
    cout<< answer;
    return 0;
}
