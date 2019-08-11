#include<stdio.h>


int arr[5001];
int dynamic[5001];

int main() {
	int answer=0;
	int n; //Á¢½Ã °¹¼ö 
	int i; int j;
	scanf("%d", &n); 

	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dynamic[i] = 0; 
	}

	arr[0] = 5002; 
	dynamic[0] = 0;

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= n - 1; j++) {
			if (arr[j] > arr[i]) {
				if (dynamic[j] + 1 >= dynamic[i]) {
					dynamic[i] = dynamic[j] + 1;
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {
		if (answer < dynamic[i]) {
			answer = dynamic[i];
		}
	}
	
	printf("%d", answer);

	return 0;
}