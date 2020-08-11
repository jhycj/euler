#include<stdio.h>
int arr[100];



void bubble_sort(int n){
	int tmp;
	int i; int j; int k;
	int count=0;

	for (i = n-2; i >=0 ; i--){
		count = 0;
		for (j = 0; j <= i; j++){
			if (arr[j] > arr[j + 1]){
				count++;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (count == 0){
			break;
		}
		else{
			for (k = 0; k < n; k++){
				printf("%d ", arr[k]);
			}
			printf("\n");
		}
	}
}


int main(){
	int i;
	int N;
	scanf("%d\n", &N);

	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubble_sort(N);

	return 0;
}