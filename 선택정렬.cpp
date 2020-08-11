#include<stdio.h>

int data[10];

void print_array(int list[], int n){
	int i; 
	for (i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
}

void select_sort(int list[], int n){

	int i; int j; int tmp;
	int min; int min_index;

	for (i = 0; i < n-1; i++){
		min = list[i + 1];
		min_index = i + 1; 
		for (j = i + 1; j < n; j++){
			if (min > list[j]){
				min = list[j];
				min_index = j; 
			}
		}

		if (min <= list[i]){
			tmp = list[min_index];
			list[min_index] = list[i];
			list[i] = tmp;
		}
		
	}
}

int main(){
	int i;

	for (i = 0; i < 10; i++){
		scanf("%d", &data[i]); 
	}
	
	select_sort(data, 10);
	print_array(data, 10);
	return 0;
}