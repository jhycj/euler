#include<stdio.h>
int num; //°­ÀÇ ¼ö 
int arr[3][21]; //arr[0][x] : index, arr[1][x] : start time, arr[2][x]: end time 
int answer[25];
int max; 
int rear;

void bubble_sort(void){
	int i; int j;
	int tmp0, tmp1, tmp2;

	for (j = 1; j <= num-1; j++){
		for (i = 1; i <= num - j; i++){
			if (arr[2][i] > arr[2][i + 1]  ){

				tmp2 = arr[2][i];
				arr[2][i] = arr[2][i + 1];
				arr[2][i + 1] = tmp2;

				tmp1 = arr[1][i];
				arr[1][i] = arr[1][i + 1];
				arr[1][i + 1] = tmp1; 

				tmp0 = arr[0][i];
				arr[0][i] = arr[0][i + 1];
				arr[0][i + 1] = tmp0;

			}

			else if (arr[2][i] == arr[2][i + 1]){
				
				if (arr[1][i] > arr[1][i + 1]){
					tmp1 = arr[1][i];
					arr[1][i] = arr[1][i + 1];
					arr[1][i + 1] = tmp1;

					tmp0 = arr[0][i];
					arr[0][i] = arr[0][i + 1];
					arr[0][i + 1] = tmp0;

				}
			}
		}
	}
}

void greedy(void){
	int i;
	
	int order = 1;
	int start = arr[1][order];
	int end = arr[2][order];
	answer[rear] = arr[0][order];
	rear++;
	max++;

	for (i = order + 1; i <= num; i++){
		
		if (end <= arr[1][i]){
			order = i;
			answer[rear] = arr[0][order]; 
			rear++; 
			max++;
			start = arr[1][order];
			end = arr[2][order];
		}
	}


}

int main(){
	
	int i;

	scanf("%d", &num);
	for (i = 1; i <= num; i++){
		scanf("%d %d %d", &arr[0][i], &arr[1][i], &arr[2][i]);
	}

	bubble_sort();


	greedy();
	printf("%d\n", max);
	for (i = 0; i < rear; i++){
		printf("%d ", answer[i]);
	}
	

	return 0;
}