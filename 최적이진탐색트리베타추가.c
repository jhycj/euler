#include<stdio.h>
int arr[51][51];
int beta[51];
int min[51];
int root[51][51];
int level[51];
int beta_level[51];
int N;

void process(int from, int to, int length){

	int R;
	R = root[from][to];

	if (from == to){
		level[from] = length;
	}
	else{
		level[R] = length;

		if (from <= R - 1){
			process(from, R - 1, length + 1);
		}
		if (R + 1 <= to){
			process(R + 1, to, length + 1);
		}
	}
}

int find_max(int x, int y){
	if (x < y){
		return y;
	}
	else{
		return x;
	}
}


int main(){
	int answer;
	int beta_sum;
	int i;
	int j;
	int k;
	int start;
	int end;
	int rear = 0;
	int M;
	int sum;

	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		scanf("%d", &arr[i][i]);
	}
	
	for (i = 0; i < N + 1; i++){
		scanf("%d", &beta[i]);
	}

	for (k = 1; k < N; k++){
		for (i = 1; i <= N - k; i++){

			start = i;
			end = i + k;
			min[0] = arr[start + 1][end];
			min[k] = arr[start][end - 1];

			rear = 1;

			for (j = start + 1; j< end; j++){ //rootÀÇ ÀÌµ¿ 
				min[rear] = arr[start][j - 1] + arr[j + 1][end];
				rear++;
			}
			sum = 0;
			for (j = start; j <= end; j++){
				sum = sum + arr[j][j];
			}

			M = min[0];
			root[i][i + k] = start;
			for (j = 1; j <= k; j++){
				if (min[j] <= M){
					root[i][i + k] = start + j;
					M = min[j];
				}
			}
			arr[i][i + k] = M + sum;
		}
	}

	printf("\n");
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for (i = 1; i <= N; i++){
	for (j = 1; j <= N; j++){
	printf("%d ", root[i][j]);
	}
	printf("\n");
	}

	process(1, N, 1);

	beta_level[0] = level[1];
	beta_level[N] = level[N];

	for (i = 0; i < N; i++){
		beta_level[i] = find_max(level[i], level[i + 1]);
	}
	beta_sum = 0;
	for (i = 0; i <= N; i++){
		beta_sum = beta_sum + (beta_level[i])*beta[i];
	}


	answer = arr[1][N] + beta_sum;
	
	printf("%d\n", answer);
	

	return 0;
}