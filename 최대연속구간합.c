#include<stdio.h>
int N; //�迭 ���� ���� 
int arr[10]; 

void find_cross_max_subarr(int arr[], int low, int high, int* return_left_index, int* return_right_index, int* return_max_sum){
	int mid = (low + high) / 2;
	int left_index;
	int right_index;
	int left_sum;
	int right_sum;
	int i;
	int sum;//check �� ���� ��� 

	//low ~ mid ���� 
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
	//left sum  �� left index ���� ����

	//mid+1  ���� high ����
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
	//right sum�� right index ���� ����.

	*return_left_index = left_index;
	*return_right_index = right_index;
	*return_max_sum = left_sum + right_sum;
}

void find_max_subarr(int arr[], int low, int high, int* return_low_index, int* return_high_index, int* return_max_sum){
	
	int left_low_index; //����� �信 �ش�
	int	left_high_index; //����� �信 �ش�  
	int left_max_sum;

	int right_low_index;
	int right_high_index; 
	int right_max_sum;

	int cross_low_index;
	int cross_high_index;
	int cross_max_sum;
	 
	int mid;

	mid = (low + high) / 2;

	if (low == high){//base case, �� �ϳ��� ���� 
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

	printf("�ִ�: %d\n", answer_sum);
	printf("���� index: %d\n", answer_low_index);
	printf("������ index: %d\n", answer_high_index);

}