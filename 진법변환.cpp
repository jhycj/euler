#include<stdio.h>

char d[17] = "0123456789ABCDEF";

void change_digit(int N, int m){
    int q = N/m;
    int r = N%m;

    if(q==0){
        printf("%c",d[r]);
    }
    else{
        change_digit(q, m);
        printf("%c",d[r]);
    }

}


int main(){
    int i;
    int N;
    int m;

    scanf("%d %d", &N, &m);

    change_digit(N,m);


}
