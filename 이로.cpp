#include<stdio.h>
#define q_size = 20000;
#define n_max = 100;

int map[n_max][n_max];
int cost[n_max][n_max];

int size=0;
int rear =0;
int front =0;
int queue[q_size];
int start_x,start_y;
int dest_x, dest_y;
int now_x,now_y;
void push(int x, int y){
    queue[rear]=x;
    rear++;
    queue[rear]=y;
    rear++
}
void pop(int* x, int*y){
    x* = queue[front];
    front++;
    y* = queue[front];
    front++;
}
void init_queue(){
    front=0;
    rear = 0;
}
void get_input(){

}

void update_cost(int x, int y){

}
int main(){
    int old_cost;
    int new_cost;
    init_queue();
    get_input();
    push(start_x,start_y);
    while(rear>front){
        pop(&now_x,&now_y);
        if(now_x>0){
            old_cost=cost[now_x-1][now_y];
            new_cost=cost[now_x][now_y]+map[now_x-1][now_y];
            if(old_cost>new_cost){
                cost[now_x-1][now_y] = new_cost;
                push(now_x-1, now_y);
            }
        }
        if(now_x<(size-1)){
            old_cost=cost[now_x+1][now_y];
            new_cost=cost[now_x][now_y]+map[now_x+1][now_y];
            if(old_cost>new_cost){
                cost[now_x+1][now_y] = new_cost;
                push(now_x+1,now_y);
            }
        }
        if(now_y>0){
            old_cost=cost[now_x][now_y-1];
            new_cost=cost[now_x][now_y]+map[now_x][now_y-1];
            if(old_cost>new_cost){
                push(now_x,now_y-1);
                cost[now_x][now_y-1] = new_cost;
            }
        }
        if(now_y<(size-1)){
            old_cost=cost[now_x][now_y+1];
            new_cost=cost[now_x][now_y]+map[now_x][now_y+1];
            if(old_cost>new_cost){
                push(now_x,now_y+1);
                cost[now_x][now_y+1] = new_cost;
            }
        }
    }
    print_result();
    return 0;
}
