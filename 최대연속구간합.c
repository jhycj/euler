#include<stdio.h>
int N; //배열 원소 개수 
int arr[10]; 

void find_cross_max_subarr(int arr[], int low, int high, int* return_left_index, int* return_right_index, int* return_max_sum){
	int mid = (low + high) / 2;
	int left_index;
	int right_index;
	int left_sum;
	int right_sum;
	int i;
	int sum;//check 해 나갈 대상 

	//low ~ mid 까지 
	left_index = mid;
	left_sum = -999; 
	sum = 0;
	for (i = mid; i >= low; i--){
		sum = sum + arr[i]; 
		if (sum > left_sum){
			left_sum = sum;
			left_index = i;
		}
	}
	//left sum  과 left index 값이 있음

	//mid+1  부터 high 까지
	right_index = mid + 1;
	right_sum = -999;
	sum = 0;
	for (i = mid + 1; i <= high; i++){
		sum = sum + arr[i];
		if (sum > right_sum){
			right_sum = sum;
			right_index = i;
		}
	}
	//right sum과 right index 값이 있음.

	*return_left_index = left_index;
	*return_right_index = right_index;
	*return_max_sum = left_sum + right_sum;
}

void find_max_subarr(int arr[], int low, int high, int* return_low_index, int* return_high_index, int* return_max_sum){
	
	int left_low_index; //출력할 답에 해당
	int	left_high_index; //출력할 답에 해당  
	int left_max_sum;

	int right_low_index;
	int right_high_index; 
	int right_max_sum;

	int cross_low_index;
	int cross_high_index;
	int cross_max_sum;
	 
	int mid;

	mid = (low + high) / 2;

	if (low == high){//base case, 단 하나의 원소 
		*return_low_index = low;
		*return_high_index = high;
		*return_max_sum = arr[low];
	}

	else{
		//LEFT SIDE 
		find_max_subarr(arr, low, mid, &left_low_index, &left_high_index, &left_max_sum);
		//Right SIDE 
		find_max_subarr(arr, mid + 1, high, &right_low_index, &right_high_index, &right_max_sum);
		//CROSS
		find_cross_max_subarr(arr, low, high, &cross_low_index, &cross_high_index, &cross_max_sum);

		
		if (left_max_sum >= right_max_sum && left_max_sum >= cross_max_sum){
			*return_max_sum = left_max_sum;
			*return_low_index = left_low_index;
			*return_high_index = left_high_index;
		}
		else if (right_max_sum >= left_max_sum && right_max_sum >= cross_max_sum){
			*return_max_sum = right_max_sum;
			*return_low_index = right_low_index;
			*return_high_index = right_high_index;
		}
		else if (cross_max_sum >= left_max_sum&& cross_max_sum >= right_max_sum){
			*return_max_sum = cross_max_sum;
			*return_low_index = cross_low_index;
			*return_high_index = cross_high_index;
		
		}
	}
}

int main(){
	int i;
	int answer_sum;
	int answer_low_index;
	int answer_high_index; 

	scanf("%d", &N);
	
	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}

	find_max_subarr(arr, 0, N - 1, &answer_low_index, &answer_high_index, &answer_sum);

	printf("최댓값: %d\n", answer_sum);
	printf("왼쪽 index: %d\n", answer_low_index);
	printf("오른쪽 index: %d\n", answer_high_index);

}