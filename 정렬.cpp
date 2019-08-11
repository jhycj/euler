#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {

	int N; int i; int j; int tmp;
	int arr[100]; int b[100];

	scanf("%d\n", &N);

	for (i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
	}
	for (i = 0; i < N; i++) {
		b[i] = arr[i];
	}

	for (j = 0; j < N; j++) {
		for (i = 0; i < N - 1 - j; i++) {

			if (arr[i + 1] < arr[i]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}

	for (i = 0; i < N; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		printf("%d ", arr[i]);
		}
	return 0;
}