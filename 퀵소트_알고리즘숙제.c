#include<stdio.h>
#include <windows.h>

/* Quicksort.c                               */
/* 입력: input_size, 배열                     */
/* 출력: 정렬된 배열의 앞, 뒤 각각 10개 data  */

int N; //입력받는 배열의 size 
float arr[50000]; //최대 배열 size는 50000개이다. 
float execution_time; //실행 시간
int comparison_num; //비교 횟수 

void divide_arr(float arr[], int low_index, int high_index, int* next_pivot_index){
	int i; int j;
	float pivot;
	float tmp;
	pivot = arr[low_index]; //pivot 초기화: 입력받은 배열의 제일 첫번째 요소 
	i = low_index + 1;
	j = high_index;
	while (i<j){//i, j 의 방향이 교차될 때까지 다음을 진행한다. 
		while (i <= high_index && arr[i] <= pivot){//[디버깅 노트1] arr[i]<pivot 하면 오류발생!(등호주의) 
			//index i는 pivot 값보다 크거나 같은 요소를 찾을 때까지 증가한다.
			i++;
		}
		while (j >= low_index && arr[j] > pivot){
			//index j는 pivot 값보다 작은 요소를 찾을 때까지 감소한다.
			j--;

			/* <주의할 점> ---> [디버깅 노트2]
			이미 정렬된 배열을 입력받으면 j는 low가 아닌 low+1이 된다.
			ex) arr[3]= {1, 5, 7} 인 경우 */
		}
		if (i < j){//[디버깅 노트3] i와 j가 역전된 상태가 아닐 때에만 교환한다. 
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			comparison_num++; //비교 횟수 증가
		}
	}
	if (arr[j] < pivot){ //위의 주의할 점 [디버깅 노트2]와 관련된 내용이다. 
		//이미 정렬된 배열을 입력받으면 j는 피벗보다 큰 값을 가리킬 수 있다.  
		tmp = arr[j];   //따라서, j가 피벗보다 작은 값을 가리킬 때만 값을 교환한다.
		arr[j] = arr[low_index];
		arr[low_index] = tmp;
		comparison_num++; //비교 횟수 증가
	}
	*next_pivot_index = j; //next_pivot_index 가 가리키는 곳에 찾고자 하는 index를 반환한다.
}

void quick_sort(float arr[], int low_index, int high_index){//퀵소트 알고리즘 

	int pivot_index; //arr[]를 분할의 기준이 되는 index 

	/* Divide and Conquer */
	if (low_index < high_index){ //low_index==high_index인 경우는 base case로서 정렬하지 않아도 된다. 
		divide_arr(arr, low_index, high_index, &pivot_index);
		//arr[]를 분할한다. 분할되는 기준 index를 pivot_index에 받아온다.
		quick_sort(arr, low_index, pivot_index - 1);
		//pivot_index를 기준으로 Left side 부분배열에 대해 퀵소트를 진행한다.
		quick_sort(arr, pivot_index + 1, high_index);
		//pivot_index를 기준으로 Right side 부분배열에 대해 퀵소트를 진행한다. 
	}
}
void open_file(int num){
	FILE* fp = NULL;
	int i;
	if (num == 100){
		fp = fopen("data100r.txt", "r");
	}
	else if (num == 500){
		fp = fopen("data500r.txt", "r");
	}
	else if (num == 1000){
		fp = fopen("data1000r.txt", "r");
	}
	else if (num == 5000){
		fp = fopen("data5000r.txt", "r");
	}
	else if (num == 10000){
		fp = fopen("data10000r.txt", "r");
	}
	else if (num == 50000){
		fp = fopen("data50000r.txt", "r");
	}
	if (fp != NULL){
		for (i = 0; i < num; i++){
			fscanf(fp, "%f", &arr[i]);
		}
	}
	fclose(fp);
}
int main(){

	int i;
	LARGE_INTEGER BeginTime, EndTime, Frequency; // 시간 측정을 위해 필요한 변수들

	/* LARGE_INTEGER */
	//부호가 있는 64bit 정수형 데이터를 저장하기 위해 선언된 사용자 정의 datatype. 
	//microsecond(1/1000000초)까지 측정하기 위해 64bit 정수형이 필요하다.

	scanf("%d", &N);//input_size를 입력받는다.
	open_file(N);//파일을 open한다.

	QueryPerformanceFrequency(&Frequency);// 고해상도 타이머의 주파수(1초당 진동수)를 Frequency에 저장한다.
	QueryPerformanceCounter(&BeginTime); //이 시점의 고해상도 타이머 값을 BeginTime에 저장한다. 

	quick_sort(arr, 0, N - 1); // QuickSort 알고리즘을 수행

	QueryPerformanceCounter(&EndTime);//이 시점의 고해상도 타이머 값을 EndTime에 저장한다. 

	execution_time = (float)(EndTime.QuadPart - BeginTime.QuadPart) / (float)Frequency.QuadPart;
	//실행시간은 카운터 값의 차이를 time resolution으로 나눈 값이다.
	//의미: (알고리즘을 수행에 걸린 진동수) / (진동수/초) = (알고리즘 수행 걸린 시간(초)) 

	/*결과 출력*/
	printf("The result of QuickSort with size %d\n", N);
	printf("\n");
	printf("The number of comparison: %d번\n", comparison_num);
	printf("\n");
	printf("The execution time: %.9f초\n", execution_time);
	printf("\n");
	for (i = 0; i < 10; i++){//앞에서 10개 정렬된 데이터 
		printf("%.4f\n", arr[i]);
	}
	printf("\n");
	for (i = N - 10; i <= N - 1; i++){//뒤에서 10번째부터 정렬된 데이터 
		printf("%.4f\n", arr[i]);
	}
	return 0;
}