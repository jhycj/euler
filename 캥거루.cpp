#include<stdio.h>

int main(){
    int i; int j;
    int count = 0; int tmp;
    int A; int B; int C; int left; int right;
    int arr[3];

    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);

    arr[0] = A;
    arr[1] = B;
    arr[2] = C;

    for(i=0; i<2; i++){
        for(j=0; j<2-i; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = arr[j];
            }
        }
    }
    A = arr[0];
    B = arr[1];
    C = arr[2];

    left = B-A;
    right = C-B;

    while(left % 2 == 0 || right % 2 == 0){

        if(left % 2==0 && right %2 ==1){
            C = (A+B)/2;
            count++;
        }

        else if(left%2 ==1 && right %2==0){
            A = (B+C)/2;
            count++;
        }

        else{
            if(left>=right){
                C = (A+B)/2;
                count++;
            }
            else(left < right){
                A = (B+C)/2;
                count++;
            }
        }

        for(i=0; i<2; i++){
            for(j=0; j<2-i; j++){
                if(arr[j] > arr[j+1]){
                    tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = arr[j];
                }
            }
        }
        A = arr[0];
        B = arr[1];
        C = arr[2];

        left = B-A;
        right = C-B;

    }

    printf("%d\n", count);
    return 0;
}
