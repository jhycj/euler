#include<stdio.h>
int N;
int arr[128][128];
int WHITE;
int BLUE;

void find(int y, int x, int size){
    int white=0;
    int blue=0;
    int i; int j;

    for(i=y; i<y+size; i++){
        for(j=x; j<x+size; j++){
            if(arr[i][j] == 0){//흰색
                white = white+1;
            }
            else if(arr[i][j]==1){//파란색
                blue++;
            }
        }
    }

    if (blue ==0){
        WHITE++;
    }
    else if(white ==0){
        BLUE++;
    }

    else{
        find(y, x, size/2);
        find(y, x+(size/2), size/2);
        find(y+(size/2), x, size/2);
        find(y+(size/2), x+(size/2), size/2);
    }

}



int main(){
    int i; int j;

    scanf("%d", &N);

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &arr[i][j]); //흰색: 0, 파란색: 1
        }
    }

    find(0, 0, N);

    printf("%d\n", WHITE);
    printf("%d\n", BLUE);


    return 0;
}
