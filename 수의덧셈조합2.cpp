#include<stdio.h>
int N; 
int S; 
int answer[8];

void process(int s, int n){
	int i;

	if (n ==1){
		if (s > answer[N-n]){
			answer[N] = s;
			for (i = 1; i <= N; i++){
				printf("%d ", answer[i]);
			}
			printf("\n");
		}
	}
	else{
		for (i = answer[N-n]+1; i < S; i++){
			answer[N-n+1] = i;
			process(s - i, n - 1);
			
		}
	}
}
int main(){
	int i;
	scanf("%d %d", &S, &N);
	answer[0] = 0;
	process(S, N);
	return 0;
}