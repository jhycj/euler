#include<stdio.h>
int N;
int answer[21];
int win;
int lose;
int n;

void process(int level, int win, int lose){
	int i;

	if (win >= N){

		for (i = 1; i <= win + lose; i++){
			if (answer[i] == 1){
				printf("o");
			}
			else if (answer[i] == 0){
				printf("x");
			}
		}
		printf("\n");
		n++;
	}
	else{//win<N

		if (lose >= N){
			return;
		}
		else { //lose<N;
			for (i = 1; i >= 0; i--){
				answer[level] = i;
				process(level + 1, win + i, lose + ((i + 1) % 2));
			}
		}
	}
}

int main(){
	scanf("%d", &N); //N은 10이하의 자연수 
	
	process(1, 0, 0);
	printf("%d", n);
	return 0;
}