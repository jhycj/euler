#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main() {
	
	int arr[9];
	int i; int max; int index;

	for (i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}

	max = arr[0]; 

	for (i = 0; i < 9; i++) {
	
		if (arr[i] > max) {
		
			max = arr[i];
			
		}
	}

	printf("%d\n", max);
	printf("%d\n", index+1);

	return 0;
}
