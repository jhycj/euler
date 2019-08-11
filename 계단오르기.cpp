#include<stdio.h>

int n; //계단수
int stair[301];
long long dynamic[301];

long long get_max(long long x, long long y){
    if(x>=y){
        return x;
    }
    else{
        return y;
    }
}

void initialize_dynamic(void){

    dynamic[0] = 0;
    dynamic[1] = stair[1];
    dynamic[2] = dynamic[1] + stair[2];
}

void get_dynamic(void){
    int i;

    for(i=3; i<=n; i++){
        dynamic[i] = get_max(dynamic[i-2]+stair[i], stair[i-1]+stair[i]+dynamic[i-3]);
    }
}

int main(){
    int i;
    scanf("%d", &n);
    stair[0] = 0;
    for(i=1; i<=n; i++){
        scanf("%d", &stair[i]);
    }
    initialize_dynamic();
    get_dynamic();

    printf("%d ", dynamic[n]);

    return 0;
}
