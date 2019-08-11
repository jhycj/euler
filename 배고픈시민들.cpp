#include<stdio.h>


int arr[5001];
int dy[5001] = { 1, };

int main() {
	int i; int j;
	int n;
	int answer = 1;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	arr[0] = 0;
	dy[0] = 0;

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= n-1; j++) {
			if (arr[j] < arr[i]) {
				if (dy[j] + 1 > dy[i]) {
					dy[i] = dy[j] + 1;
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {
		if (answer < dy[i]) {
			answer = dy[i];
		}
	}

	printf("%d", answer);


	return 0;
}
