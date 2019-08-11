#include<stdio.h>
int fibo[41];

void init_Fibo(){
    fibo[0]=1;
    fibo[1]=1;
    fibo[2]=2;
    for(int i=0; i<39; i++){
        fibo[i+2]=fibo[i]+fibo[i+1];
    }
}

int main(){
    int num_seat=0;
    int num_fix_seat=0;
    int last_fix_seat=0;
    int fix_seat=0;
    int ans = 1;
    init_Fibo();
    scanf("%d",&num_seat);
    scanf("%d",&num_fix_seat);
    for(int i=0; i< num_fix_seat;++i){
        scanf("%d",&fix_seat);
        ans *=fibo[fix_seat - last_fix_seat-1];
        last_fix_seat =fix_seat;
    }
    ans *= fibo[num_seat - last_fix_seat];
    printf("%d",ans)  ;
}
