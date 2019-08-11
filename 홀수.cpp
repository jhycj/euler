
#include<stdio.h>
int main() {

	int i; int sum; int min;
	int arr[7];
	int b[7];
	sum = 0; 

	for (i = 0; i < 7; i++) {
		scanf("%d", &arr[i]);
	}
	

	for (i = 0; i < 7; i++) {
	
		if (arr[i] % 2 == 1) {
			sum = sum + arr[i];
			b[i] = arr[i];
		}
		else {
			b[i] = 100;
		}
	}
	min = b[0];

	for (i = 0; i < 7; i++) {
		if (min > b[i]) {
			min = b[i];
		}
	}

	if (sum == 0) {
		printf("-1\n");
	}

	else {
		printf("%d\n", sum);
		printf("%d\n", min);
	}
	return 0;
}