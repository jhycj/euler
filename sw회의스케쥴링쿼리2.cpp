#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

typedef struct table{
	unsigned long long start;
	unsigned long long end; 
}T;



int num_test_case;
int N;
int Q;

unsigned long long *q_s_table;
unsigned long long  *q_e_table;

vector<T> table;
bool cmp(const T &t1, const T &t2){

	if (t1.end < t2.end){
		return true;
	}

	else if (t1.end == t2.end){

		return t1.start < t1.start;

	}

	else{

		return false;

	}

}


int greedy(unsigned long long q_s, unsigned long long q_e){
	int i;
	unsigned long long end;
	int count = 0;

	end = q_s;

	for (i = 0; i < N; i++){
		
		if (table[i].start >= end && table[i].end <= q_e){
			end = table[i].end;
			count++;
		}
	}
	return count;
}



int main(){
	int i, k;

	int answer;
	unsigned long long tmp1, tmp2;

	scanf("%d", &num_test_case);

	for (k = 1; k <= num_test_case; k++){
		answer = 0;
		scanf("%d %d", &N, &Q); // È¸ÀÇ °¹¼ö, Áú¹® °¹¼ö 

		q_s_table = (unsigned long long *)malloc(sizeof(unsigned long long) * Q);
		q_e_table = (unsigned long long*)malloc(sizeof(unsigned long long) * Q);

		for (i = 0; i < N; i++){
			
			scanf("%lld %lld", &table[i].start, &table[i].end);
		}


		for (i = 0; i < Q; i++){
			scanf("%lld %lld", &q_s_table[i], &q_e_table[i]);
		}


		sort(table.begin(), table.end(), cmp);

		for (i = 0; i < N; i++){
			printf("%lld %lld", table[i].start, table[i].end);
		}



		for (i = 0; i < Q; i++){
			answer = answer + (i + 1)* greedy(q_s_table[i], q_e_table[i]);
		}
		printf("#%d %d", k, answer);
	
		free(q_s_table);
		free(q_e_table);
	}



	return 0;
}