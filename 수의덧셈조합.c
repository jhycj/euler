#include<stdio.h>

int N; // 3<=N<=7
int S;  //10<=S<= 100
int answer[8];

void process(int level, int Max){
	int i;
	int part_sum=0;

	if (level >=N){

		for (i = 1; i <= N - 1; i++){
			part_sum = part_sum + answer[i];
		}
		
		if (S-part_sum > answer[level - 1]){
			answer[level] = S - part_sum;
			for (i = 1; i <= N; i++){
				printf("%d ", answer[i]);
			}
			printf("\n");
	
		}
	}

	else{
		for (i = answer[level - 1] + 1; i <= Max; i++){
			answer[level] = i;
			process(level + 1, Max);
		}
	}
}

int main(){
	int Max;

	answer[0] = 0;
	scanf("%d %d", &S, &N);
	Max = S - (N - 1) * N * (1 / 2);
	process(1, Max);
	return 0;
}