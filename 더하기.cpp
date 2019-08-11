#include<stdio.h>
int dynamic[11];
int calc_max =0;
int calc_number_of_case(int n);
int get_number_of_case(int n);

int main(){
    int i, j, n;
    scanf("%d", &n);


    printf("%d", number_of_case(n));

    return 0;
}

int calc_number_of_case(int n){
    int result = 0;

    if(n==1){
        result= 1;
    }

    else if(n==2){
        result=2;
    }
    else if(n==3){
        result = 4;
    }
    if(n>3){
        result = get_number_of_case(n-1) + get_number_of_case(n-2) + get_number_of_case(n-3);
    }
    return result;
}
int get_number_of_case(int n){
    if(calc_max < n){
        for(;calc_max < n; calc_max ++){
            calc_number_of_case(calc_max+1);
        }
    }
    return dynamic[n];
}
