#include<stdio.h>

int N; //1<=N<=10
int answer[11];
int check[11];
int count;

void process(int level){
	int i;
	if (level > N){
		for (i = 1; i <= N; i++){
			if (answer[i] == 10){
				printf("A");
			}
			else{
				printf("%d", answer[i]);
			}
		}
		printf("\n");
		count++;
	}

	else{
		if ( level % 2 == 1){// È¦¼ö levelÀÌ´Ù 
			for (i = 1; i < answer[level-1] && i<=N ; i++){
				if (check[i] == 0){
					answer[level] = i;
					check[i] = 1;
					process(level + 1);
					check[i] = 0;
				}
			}
		}

		else if (level % 2 == 0){
			for (i = answer[level-1] + 1 ; i <= N; i++){
				if (check[i] == 0 ){
					answer[level] = i;
					check[i] = 1;
					process(level + 1);
					check[i] = 0;

				}
			}
		}
	}
}

int main(){
	answer[0] =11;
	scanf("%d", &N);

	process(1);
	printf("%d", count);
}