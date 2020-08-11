#include<stdio.h>
int arr[10];
int main(){
	int i;
	int j;
	int tmp;
	for (i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
	}

	for (i = 9; i >= 0; i--){
		for (j = 0; j <= i-1; j++){
			if (arr[j] >= arr[j + 1]){
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp; 
			}
		}
	}

	printf("%d", arr[7]);
	return 0;
}