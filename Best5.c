#include<stdio.h>
int score[2][9];
int total;
void bubble_sort5(void){
	int i; int j;
	int tmp1, tmp0;
	for (i = 1; i <= 7; i++){
		for (j = 1; j <= 8 - i; j++){
			if (score[1][j] < score[1][j + 1]){
				tmp1 = score[1][j];
				score[1][j] = score[1][j + 1];
				score[1][j + 1] = tmp1; 

				tmp0 = score[0][j];
				score[0][j] = score[0][j + 1];
				score[0][j + 1] = tmp0;
			}
		}
	}

	for (i = 1; i <= 5; i++){
		total += score[1][i]; 
	}

	for (i = 1; i <= 4; i++){
		for (j = 1; j <= 5 - i; j++){
			if (score[0][j] > score[0][j + 1]){

				tmp0 = score[0][j];
				score[0][j] = score[0][j + 1];
				score[0][j + 1] = tmp0;
			}
		}
	}



}



int main(){

	int i;
	for (i = 1; i <= 8; i++){
		scanf("%d", &score[1][i]);
		score[0][i] = i; 
	}
	bubble_sort5(); 
	printf("%d\n", total);
	for (i = 1; i <= 5; i++){
		printf("%d ", score[0][i]);
	}

	return 0;
}