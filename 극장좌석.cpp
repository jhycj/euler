#include<stdio.h>
int N; //전체 좌석 수
int M;// block 갯수
int dynamic[41];

void get_Fibo(int index){

    if(index==1){
        dynamic[index] = 1;
    }
    else if(index==0){
        dynamic[index] = 1;
    }
    else if(index==2){
        dynamic[index]  = 2;
    }
    else{
        dynamic[index] = dynamic[index-1] + dynamic[index-2];
    }

}

void get_Fibo_array(void){
    int i;
    for(i=0; i<=40; i++){
        get_Fibo(i);
    }
}

//void init_Fibo(){
//    dynamic[1]=1;
//    dynamic[2]=2;
//    for(int i =3; i<=40;++i){
//        dynamic[index] = dynamic[index-1] + dynamic[index-2];
//    }
//}

int main(){
    int i;
    int fix_seat = 0 ;
    int current_seat=0;
    int answer=1;
    int tmp;
    get_Fibo_array();
    scanf("%d", &N);
    scanf("%d", &M);


    for(i=0; i<M; i++){
        scanf("%d", &fix_seat);

        answer = answer * dynamic[fix_seat - current_seat - 1];
        current_seat = fix_seat;
    }
    answer = answer * dynamic[N-current_seat];
    printf("%d", answer);

}
