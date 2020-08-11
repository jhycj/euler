#include<stdio.h>
int N;
int sum; 
int arr[2][21];
int answer[21];
int j;

void process(int level){
	int i;
	int local_sum;
	

	if (level > j){

		local_sum = 0;
		for (i = 1; i <= j; i++){
			local_sum = local_sum + answer[i];
		}
		if (local_sum == sum){
			for (i = 1; i <= j; i++){
				printf("%d ", answer[i]);
			}
			printf("\n");
		}
	}

	else{
		for (i = arr[0][level-1]+1; i <= N; i++){
			answer[level] = arr[1][i];
			process(level + 1);
		}		
	}
}

void bubble_sort(void){
	int i;
	int j; 
	int tmp;

	for (i = 1; i <= N - 1; i++){
		for (j = 1; j <= N - i; j++){
			if (arr[1][j] > arr[1][j + 1]){
				tmp = arr[1][j];
				
				arr[1][j] = arr[1][j + 1];
				arr[1][j + 1] = tmp;

			}
		}
	}

}


int main(){
	int i;
	scanf("%d %d", &N, &sum);
	for (i = 1; i <= N; i++){
		scanf("%d", &arr[1][i]);
		arr[0][i] = i;
	}
	bubble_sort();
	arr[1][0] = 0;
	arr[0][0] = 0;
	for (j = N; j >=1 ; j--){
		process(1);
	}

	return 0;
}