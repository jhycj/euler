#include<stdio.h>
int count;

int answer[21];
int N; //��ȣ ���� ���� , 

void process(int level, int count1, int count2){//count1�� ( ���� , count2�� )���� 
	int i;

	if (level > 2 * N){
		
		for (i = 1; i <= 2 * N; i++){
			if (answer[i] == 1){
				printf("(");
			}
			else if (answer[i] == 2){
				printf(")");
			}
		}
		printf("\n");
		count++;
	}
	

	else {
	
		if (count2 <=count1 ){
			if (count1 == N){
				answer[level] = 2;
				process(level + 1, count1, count2 + 1);
			}

			else{
				for (i = 1; i <= 2; i++){
					answer[level] = i;
					if (i == 1){
						process(level + 1, count1 + 1, count2);
					}
					else if (i == 2){
						process(level + 1, count1, count2 + 1);
					}
				}
			
			}
		}
		else{
			return;
		}
	}
}


int main(){

	scanf("%d", &N);
	answer[1] = 1; //�� ù��°�� ( �� �ۼ��ؾ� ��. 
	process(2, 1, 0);
	printf("%d", count);
	return 0;
}