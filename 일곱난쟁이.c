#include<stdio.h>
int arr[10]; //9개의 숫자를 입력 받는다.
int N;
int x; int y;

int main(){
	int i;
	int j; 
	int sum;
	sum = 0;

	for (i = 1; i <= 9; i++){
		scanf("%d", &arr[i]);
		sum = sum + arr[i];
	}

	N = sum-100;
	

	for (i = 1; i <= 8; i++){
		for (j = i+1; j <= 9; j++){
			if (arr[i] + arr[j] == N){
				x = i;
				y = j;
				
			}
		}
	}

	for (i = 1; i <= 9 ; i++){
		if (i != x && i != y){
			printf("%d\n", arr[i]);
		}
	}



	return 0;
}