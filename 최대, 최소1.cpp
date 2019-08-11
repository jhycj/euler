#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int N; 
	int i; int arr[100]; int min; int max;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	min = arr[0];
	max = arr[0];

	for (i = 0; i < N; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	printf("%d\n", min);
	printf("%d\n", max); 

	return 0;
}