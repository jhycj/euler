#include<stdio.h>
#include<stdlib.h>
#include<algorithm>


int num_test_case;
int N; 
int Q;
unsigned long long *start_table;
unsigned long long *end_table;
unsigned long long *q_s_table;
unsigned long long  *q_e_table;

void bubble_sort(void){
	int i, j;
	unsigned long long tmp_s;
	unsigned long long tmp_e;

	for (i = 1; i <= N; i++){
		for (j = 0; j < N - i; j++){
			if (end_table[j] > end_table[j + 1]){
				tmp_e = end_table[j];
				end_table[j] = end_table[j + 1];
				end_table[j + 1] = tmp_e; 

				tmp_s = start_table[j];
				start_table[j] = start_table[j + 1];
				start_table[j + 1] = tmp_s;
			}

			else if (end_table[j] == end_table[j + 1]){
				if (start_table[j] > start_table[j + 1]){
					tmp_s = start_table[j];
					start_table[j] = start_table[j + 1];
					start_table[j + 1] = tmp_s; 
				}
			}
		}
	}
}

int greedy(unsigned long long q_s, unsigned long long q_e){
	int i; 
	unsigned long long end; 
	int count=0;

	end = q_s; 

	for (i = 0; i < N; i++){

		if (start_table[i] >= end && end_table[i] <= q_e ){
			end = end_table[i]; 
			count++;
		}
	}	
	return count;
}



int main(){
	int i,  k;

	int answer;


	scanf("%d", &num_test_case);

	for (k = 1; k <= num_test_case; k++){
		answer = 0;
		scanf("%d %d", &N, &Q); // È¸ÀÇ °¹¼ö, Áú¹® °¹¼ö 

		start_table = (unsigned long long*)malloc(sizeof(unsigned long long)* N);
		end_table = (unsigned long long*)malloc(sizeof(unsigned long long)*N);

		q_s_table = (unsigned long long *)malloc(sizeof(unsigned long long) * Q);
		q_e_table = (unsigned long long*)malloc(sizeof(unsigned long long) * Q);

		for (i = 0; i < N; i++){
			scanf("%lld %lld", &start_table[i], &end_table[i]); 
		}

		for (i = 0; i < Q; i++){
			scanf("%lld %lld", &q_s_table[i], &q_e_table[i]);
		}
	
		bubble_sort();

		for (i = 0; i < Q; i++){
			answer = answer + (i+1)* greedy(q_s_table[i], q_e_table[i]);
		}
		printf("#%d %d", k, answer);
		free(start_table);
		free(end_table);
		free(q_s_table);
		free(q_e_table);
	}



	return 0;
}