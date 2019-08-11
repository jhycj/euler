#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int i; int j;
	int sum = 0; int avg; int max; int index;
	int arr[10]; int b[101];

	for (i = 0; i < 101; i++) {
		b[i] = 0;
	}

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < 10; i++) {
		sum = sum + arr[i];
	}

	avg = sum / 10;

	for(i=0; i<10; i++){
		b[arr[i]/10]++;
	}

	max = b[0];

	for(i=0; i<101; i++){
		if(max < b[i]){
			max = b[i];
			index = i;
		}
	}


	printf("%d\n", avg);
	printf("%d\n", index*10);
	return 0;
}
