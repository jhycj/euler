#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {

	int i; int j;  int tmp; int max1; int max2;
	int arr[7]; 

	for (i = 0; i < 7; i++) {
		scanf("%d", &arr[i]);	
	}

	for (j = 0; j < 2; j++) {
		for (i = 0; i < 6 - j; i++)
		{
			if (arr[i + 1] < arr[i]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}

	max1 = arr[6];
	max2 = arr[5];

	printf("%d\n", max1);
	printf("%d", max2);
	return 0;
}