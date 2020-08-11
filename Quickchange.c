#include<stdio.h>
int N;
int arr[4] = { 25, 10, 5, 1 };

void calculate(int n){
	int i;
	int answer; 
	int change=n; //초기값은 n

	for (i = 0; i < 4; i++){
		answer = change / arr[i]; 
		change = change % arr[i];
		printf("%d ", answer);
	}
	
}



int main(){
	scanf("%d", &N);

	calculate(N);


	return 0;
}