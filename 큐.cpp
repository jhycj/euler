#include<stdio.h>

int main(){

    int N; int x; int y; int i;
    int Q[1000];
    int rear=0;
    int front=0;

    scanf("%d\n", &N);

    for(i=0; i<N; i++){
        scanf("%d", &x);
        if(x==1){
            scanf("%d", &y);
            Q[rear] = y;
            rear ++;
        }

        if(x==2){
                if(front-rear !=0){
                    front++;
                }
        }

    }
        //for(i=front; i<rear; i++){
        //    printf("%d ", Q[i]);
        //}
        //printf("\n");
    //}




    if(rear-front ==0){
        printf("-1");

    }
    else{
        printf("%d\n", rear-front);
        printf("%d ", Q[front]);

        printf("%d ", Q[rear-1]);
    }

    return 0;
}
