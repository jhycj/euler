#include<stdio.h>

int calculate(int n){
	int count;
	int change;
	int arr[6]; //500, 100, 50, 10, 5, 1 =>6가지 종류 화폐 
	int i;

	arr[0] = 500;
	arr[1] = 100;
	arr[2] = 50; 
	arr[3] = 10;
	arr[4] = 5;
	arr[5] = 1;

	count = 0;
	change = n;
	for (i = 0; i < 6; i++){
		count += change / arr[i];
		change = change % arr[i];

	}
	return count;
}

int main(){
	int N; 
	int answer;
	scanf("%d", &N);
	answer= calculate(1000 - N);
	printf("%d", answer);
	return 0;
}