#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int arr[9][9];
	int i; int j;
	int max;
	int row;
	int col;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	max = arr[0][0];
	row = 0;
	col = 0;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {

			if (max < arr[i][j]) {
				max = arr[i][j];
				row = i;
				col = j;
			}
		}
	}


	printf("%d\n", max);
	printf("%d %d", row + 1, col +1);

	return 0;

}
