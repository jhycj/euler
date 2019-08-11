#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int i; int j;
	int tmp;
	int avg; int mid; int sum = 0;
	int arr[5];

	for (i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < 5; i++) {
		sum = sum + arr[i];
	}

	avg = sum / 5; 

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	mid = arr[2];

	printf("%d\n", avg);
	printf("%d\n", mid);
	return 0;
}