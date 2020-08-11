#include<stdio.h>
#include<stdlib.h>


void get_dynamic_table(int n, int*arr){
	
	if (n == 1){
		arr[n] = 0;
	}
	else if (n % 2==0){//if n is even 
		arr[n] = arr[n / 2] + 1;
	}
	else if (n % 2 == 1){//if n is odd
		arr[n] = arr[(n + 1) / 2] + 2;
	}
}


int main(){
	setbuf(stdout, NULL);
	int T;
	int n1, n2;
	long long answer;
	int i; int k;
	int* arr;
	
	scanf("%d", &T);

	for (k = 0; k < T; k++){

		answer = 0;
		n1 = 0;
		n2 = 0;
		scanf("%d %d", &n1, &n2);

		arr = (int*)malloc(sizeof(int)*(n2 + 1));

		for (i = 1; i <= n2; i++){
			get_dynamic_table(i, arr);
		}

		for (i = n1; i <= n2; i++){
			answer = answer + arr[i];
		}
		
		printf("Case #%d\n", k+1);
		printf("%lld\n", answer);
		free(arr);
	}
	
	return 0;
}