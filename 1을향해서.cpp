#include<stdio.h>
#define MAX_SIZE 1000001
#define INF 987654321
#define min2(x, y) (x<y ? x:y )

int N;
int dynamic[MAX_SIZE];

int find_min(int x, int y, int z){
    int min;
    min=min2(min2(x, y),z);
    return min;
}

void get_dynamic(int index){
    int x = INF;
    int y = INF;
    int z = INF;

    x = dynamic[index-1]+1;
    if(index%2 ==0){
        y = dynamic[index/2]+1;
    }
    if(index%3==0){
        z = dynamic[index/3] + 1;
    }
    dynamic[index] = find_min(x, y, z);
}

void get_dynamic(void){
    int i;
    dynamic[1] = 0;
    for(i=2; i<=N; i++){
        get_dynamic(i);
    }
}

int main(){
    int i;
    scanf("%d", &N);
    get_dynamic();
    printf("%d", dynamic[N]);

    return 0;
}
