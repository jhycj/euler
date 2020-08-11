#include<stdio.h>
int N; 
int arr[10000]; //최대 배열 size는 1000개이다. 

void divide_arr(int arr[], int low_index, int high_index, int* next_pivot_index){
	
	int i; int j;
	int pivot; 
	int tmp;

	pivot = arr[low_index];
	

	i = low_index + 1;
	//printf("%d\n", i);
	j = high_index; 
	//printf("%d\n", j);

	while (i<j){
		
		while (i <= high_index && arr[i] < pivot){
			i++; 
		}
		//이 while 문을 빠져나온 i는 arr[i] 가 pivot보다 크다. 
		//printf("i: %d ,arr[i]: %d, pivot: %d\n", i, arr[i], pivot);

		while (j >= low_index && arr[j] > pivot){
			j--;
		}
		//printf("j: %d ,arr[j]: %d, pivot: %d\n", j, arr[j], pivot);
		//printf("\n");
		//이 while문을 빠져나온 j는 arr[j] 가 pivot 보다 작다. 
		if (i < j){
		
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	//이 while 문을 빠져나온 i, j는 역전된 상태이며 j가 가리키는 값이 새로운 pivot값이다. 
	if (arr[j] < pivot){
		tmp = arr[j];
		arr[j] = arr[low_index];
		arr[low_index] = tmp;
		
	}

	*next_pivot_index = j;
	for (i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
}

void quick_sort(int arr[], int low_index, int high_index){
	
	int i;
	int pivot_index;
	
	if (low_index < high_index){
		
		divide_arr(arr, low_index, high_index, &pivot_index);
		
		quick_sort(arr, low_index, pivot_index - 1);
		quick_sort(arr, pivot_index + 1, high_index); 

	}
}




int main(){
	int i;
	scanf("%d", &N); //배열 size 
	
	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	quick_sort(arr, 0, N - 1);

	

	return 0;
}