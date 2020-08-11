#include<stdio.h>

int deadline;
int N; //Á¤ºñ¼Ò °¹¼ö 
int distance[101];
int time[101];
int dynamic[101];
int min_index[101];

int get_min_index(int index){
	int i;
	int sum;
	sum = 0;
	for (i = index - 1; i >= 0; i--){
		sum = sum + distance[i];
		if (sum > deadline){
			return i + 1;
			break;
		}
		else if (sum == deadline){
			return i;
			break;
		}
	}
}

void get_min_index_array(void){
	int i;

	min_index[0] = 0;
	min_index[1] = 0;
	for (i = 2; i <= N + 1; i++){
		if (get_min_index(i) == -1){
			min_index[i] = 0;
		}
		else{
			min_index[i] = get_min_index(i);
		}
	}
	for (i = 0; i <= N + 1; i++){
		printf("%d ", min_index[i]);
	}
}

void get_dynamic(void){
	int i;
	int x;
	int min;
	dynamic[0] = 0;
	dynamic[1] = time[1];

	for (i = 2; i <= N + 1; i++){
		min = dynamic[i - 1];
	}


}


int main(){
	int i;
	scanf("%d", &deadline);
	scanf("%d", &N); //Á¤ºñ¼Ò °¹¼ö 
	for (i = 0; i < N + 1; i++){
		scanf("%d", &distance[i]);
	}
	for (i = 0; i < N; i++){
		scanf("%d", &time[i]);
	}
	get_min_index_array();
	if (min_index[N + 1] == 0){
		printf("0\n");
		printf("0\n");
	}

	/*for (i = 0; i < N + 1; i++){
	printf("%d", distance[i]);
	}
	for (i = 0; i < N; i++){
	printf("%d", time[i]);
	}*/
	return 0;
}