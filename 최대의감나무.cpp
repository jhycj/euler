#include<stdio.h>
int map[1001][1001];
int count_map[1001][1001];
int answer_map[1001][1001];
int num_tree; //감나무 수 
int M; int N; //토지의 가로 세로
int m; int n; //window 가로 세로 

int find_max(void){
	int i;
	int j;

	int max = answer_map[1][1];
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			if (max <= answer_map[i][j]){
				max = answer_map[i][j];
			}
		}
	}

	return max; 
}



int get_answer(int y, int x){

	answer_map[y][x] = count_map[y][x] - count_map[y][x - m] - count_map[y - n][x] + count_map[y - n][x - m];
	return answer_map[y][x];
	
}


int count_tree(int y, int x){
	int i; int j;
	int answer=0;
	if (map[y][x] == 1){
		answer++;
	}

	answer = answer + count_map[y][x - 1] + count_map[y - 1][x] - count_map[y - 1][x - 1];
		
	return answer;
}

int main(){
	int i; int j; 
	int tmp1; int tmp2; 
	int tree_count=0; 

	scanf("%d", &num_tree);
	scanf("%d %d", &M, &N); //가로 세로 
	for (i = 0; i < num_tree; i++){
		scanf("%d %d", &tmp1, &tmp2);
		map[tmp2][tmp1] = 1; 
	}
	scanf("%d %d", &m, &n);

	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			count_map[i][j] = count_tree(i, j);
		}
	}

	for (i = n; i <= N; i++){
		for (j = m; j <= M; j++){
			answer_map[i][j] = get_answer(i, j);
		}
	}


	/*for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			printf("%d ", answer_map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			printf("%d ", count_map[i][j]);
		}
		printf("\n");
	}*/

	printf("%d", find_max());

	return 0;
}