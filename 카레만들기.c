#define INF 9999999999
#include<stdio.h>
#include<stdlib.h>
int min = INF;
int N;
int S; //�Ÿ�
int B;//����

int sour[11];
int bad[11];
int answer;

void process(int level, int multi_sour, int sum_bad, int not){
	int diff;
	if (level >= N){
		if (not != 0){
			diff = abs(multi_sour - sum_bad);

			if (diff < min){
				min = diff;
			}
		}

	}
	else{
		process(level + 1, multi_sour * sour[level + 1], sum_bad + bad[level + 1], not + 1); //÷����
		process(level + 1, multi_sour, sum_bad, not); //÷�� ����   

	}


}

int main(){
	int i;
	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		scanf("%d %d", &sour[i], &bad[i]);
	}

	process(0, 1, 0, 0);
	printf("%d", min);
	return 0;
}