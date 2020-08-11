#include<stdio.h>
int N;
int M;
int answer[8];
int count; 

void process(int level){
	int i;

	if (level > M){
		for (i = 1; i <= M; i++){
			printf("%d ", answer[i]);
		}
		printf("\n");
		count++;
	}
	else{
		for (i = answer[level-1] ; i <= N; i++){
			answer[level] = i;
			process(level + 1);
		}
	}
}

int main(){
	answer[0] = 1;
	scanf("%d %d", &N, &M);
	process(1);
	printf("%d\n", count);

	return 0;
}