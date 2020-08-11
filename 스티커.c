#define max(a, b) (a>b? a:b)
#include<stdio.h>
#include<stdlib.h>

int N; 
int arr[2][100001];
unsigned long dynamic[2][100001]; 
unsigned long M[100001];

void initialize(void){
	dynamic[0][1] = arr[0][1];
	dynamic[1][1] = arr[1][1];

	M[1] = max(dynamic[0][1], dynamic[1][1]);

	dynamic[0][2] = arr[0][2] + dynamic[1][1];
	dynamic[1][2] = arr[1][2] + dynamic[0][1];
	M[2] = max(dynamic[0][2], dynamic[1][2]);
	
}

void run_dynamic(void){
	int i; 

	for (i = 3; i <= N; i++){
		dynamic[0][i] = max(dynamic[1][i - 1] + arr[0][i], M[i - 2] + arr[0][i]); 
		dynamic[1][i] = max(dynamic[0][i - 1] + arr[1][i], M[i - 2] + arr[1][i]);
		M[i] = max(dynamic[0][i], dynamic[1][i]);
	}

}



int main(){
	int i;
	int j;
	
	scanf("%d", &N);
	
	for (i = 0; i <= 1; i++){
		for (j = 1; j <= N; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	initialize();
	run_dynamic();
	printf("%d\n", M[N]);
	return 0;
}