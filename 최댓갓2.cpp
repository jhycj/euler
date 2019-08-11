#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int data[81];
	int max_idx = 0;
	int max_val = data[0];

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) {
			scanf("%d", &(data[i * 9 + j]));
		}
	}

	for (int i = 0; i<81; ++i) {
		if (data[i]> max_val) {
			max_val = data[i];
			max_idx = i;
		}
	}

	printf("%d\n", max_val);
	printf("%d %d", max_idx / 9, max_idx % 9);
	return 0;
}