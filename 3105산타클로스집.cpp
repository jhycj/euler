#include<iostream>
#include<stack>

using namespace std;
int E[6][6] = {0,};
int visit[6][6] = {0,};
stack<int> S ;

void make_E(){
    E[1][2] = E[2][1] = 1;
    E[1][3] = E[3][1] = 1;
    E[1][5] = E[5][1] = 1;

    E[2][3] = E[3][2] = 1;
    E[2][5] = E[5][2] = 1;

    E[3][4] = E[4][3] = 1;
    E[3][5] = E[5][3] = 1;

    E[4][5] = E[5][4] = 1;
}

bool check_is_end(){
    int count = 0;
    for(int i=1; i<=4; i++){
        for(int j= i+1; j<=5; j++){
            if(visit[i][j]==1){
                count++;
            }
        }
    }
    if(count==8 ){
        return true;
    }

    else{
        return false;
    }
}


void print_answer(stack<int> S){
    stack<int> A ;
    stack<int> copy_S;
    copy_S = S;
    while(!copy_S.empty()){
        int top_ele = copy_S.top();
        A.push(top_ele) ;
        copy_S.pop();
    }
    while(!A.empty()){
        cout<<A.top();
        A.pop();
    }
    cout<<endl;
}


void back_track(int node_num){

    S.push(node_num);
    bool is_end = check_is_end();
    if(is_end == true){
        //답출력
        print_answer(S);
        if(!S.empty()){
            int top_first_ele = S.top();
            S.pop();
            int top_sec_ele = S.top();
            visit[top_first_ele][top_sec_ele] = visit[top_sec_ele][top_first_ele] = 0;

        }
        
        return;
    }

    else{ // is_end == false;
        for(int i= 1; i<=5; i++){
            if(E[node_num][i] == 1 && visit[node_num][i]==0){ //node_num->i 로의 엣지가 있고 방문 아직 안한 i 노드를 찾으면
                visit[node_num][i] = visit[i][node_num]= 1;

                back_track(i);
            }
        }
        if(!S.empty()){
            int top_first_ele = S.top();
            S.pop();
            if(!S.empty()){
                int top_sec_ele = S.top();
                visit[top_first_ele][top_sec_ele] = visit[top_sec_ele][top_first_ele] = 0;

            }
            
        }

    }
}


int main(){

    make_E();

    // for(int i=1; i<=5; i++){
    //     for(int j=1; j<= 5; j++){
    //         cout<<E[i][j];
    //     }
    //     cout<<endl;
    // }

    back_track(1);

    return 0;
}
