#include<stdio.h>
int N; 
int M;
int check[8];
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
		for (i = 1; i <= N; i++){
			if (check[i] ==0 ){//아직 사용 안함
				answer[level] = i;
				check[i] = 1; 
				process(level + 1);
				check[i] = 0; 
			}
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	process(1);
	printf("%d\n", count);
	return 0;
}