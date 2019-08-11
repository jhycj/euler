#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int find_max(int *p) {
	int i; 
	int max = p[0];

	for (i = 0; i < 9; i++) {
		if (max < p[i]) {
			max = p[i];
		}
	}
	return max;
}

/* int find_index(int *p) {
	int i;  int x;
	x = find_max(p);

	for (i = 0; i < 9; i++) {
		if (x == p[i]) {
			return i;
		}
	}
}
*/

int main() {

	int arr[9];
	int i; int max; int index;
	//find_max(arr);

	for (i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}

	max = find_max(arr);
	
	for (i = 0; i < 9; i++) {
		if (arr[i] = max) {
			index = i;
		}
	}
	printf("%d \n", max);
	printf("%d \n", index);
}