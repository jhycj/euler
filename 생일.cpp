#include<stdio.h>

int main(){

    int i;
    int year;
    int month;
    int day;
    int sum = 0;
    int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //char c[8][3] = {'월', '화', '수', '목', '금', '토', '일', '\0'};

    scanf("%d", &year);
    scanf("%d", &month);
    scanf("%d", &day);

    for(i=1; i<year; i++){
        if((i % 4==0 && i %100 != 0) || i % 400==0){
            sum = sum + 366;
        }
        else{
            sum = sum + 365;
        }
    }

    if(month==1){
        sum = sum + day;
    }

    if(month ==2){
        sum = arr[1] + day;
    }

    if(month>2){
        for(i=1; i<month; i++){
            sum = sum + arr[i];
        }
        sum = sum + day;

        if ((year % 4==0 && year%100 != 0) || year % 400==0){
            sum = sum + 1;
        }
    }

    if(sum%7==1){
        printf("monday\n");
    }

    if(sum%7==2){
        printf("tuesday\n");
    }
    if(sum%7==3){
        printf("wednesday\n");
    }
    if(sum%7==4){
        printf("thursday\n");
    }
    if(sum%7==5){
        printf("friday\n");
    }
    if(sum%7==6){
        printf("saturday\n");
    }
    if(sum%7==0){
        printf("sunday\n");
    }


    return 0;
}
