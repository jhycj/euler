#include<stdio.h>

int N;
int money[30001];
int dynamic[30001];
int max[30001];

void find_max_array(int index){



}
void get_dynamic(int index){
    int x;
    int y;

    if(index==1){
        dynamic[index] = money[1];
    }
    else if(index==2){
        dynamic[index] = money[1] + money[2];
    }
    else if(index==3){
        if(money[1] + money[3] > money[2] + money[3]){
            dynamic[index] = money[1]+money[3];
        }
        else{
            dynamic[index] = money[2] + money[3];
        }
    }

    else{
        x = dynamic[index-3] + money[index-1] + money[index];
        y = dynamic[index-2] + money[index];

        if(x>y){
            dynamic[index] = x;
        }
        else{
            dynamic[index] = y;
        }
    }
}

int main(){
    int i;
    scanf("%d", &N);
    for(i=1; i<=N; i++){
        scanf("%d", &money[i]);
    }
    for(i=1; i<=N; i++){
        get_dynamic(i);
    }
    printf("\n");
    for(i=1; i<=N; i++){
        printf("%d ", dynamic[i]);
    }
    return 0;
}
