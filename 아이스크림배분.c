#include<stdio.h>

/* 중복을 허용하는 순열 */
int N;
int M;
int answer[12];
int count;

void process(int level){
	int i;

	if (level > N ){
		for (i = 1; i <= N; i++){
			printf("%d ", answer[i]);
		}
		printf("\n");
		count++;
	}
	else{
		for (i = 1; i <= M; i++){
			answer[level] = i;
			process(level+1);
		}
	}

}

int main(){
	scanf("%d %d", &N, &M);
	process(1);
	printf("%d\n", count);
	return 0;
}