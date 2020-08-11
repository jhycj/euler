#define INF 999;
#include<stdio.h>
int path[51][51];
int length;
int V;//그래프 꼭짓점 개수 
int E;//그래프 간선 개수 
int start_v;//시작점
int end_v;//도착점
int dynamic[51][51];//v_i 에서 v_j로의 최단 경로의 길이 (dynamic)

void input(void){ //입력받는 행렬 
	int i; int j;
	int tmp1; int tmp2; int tmp3;

	scanf("%d %d %d", &V, &start_v, &end_v);
	scanf("%d", &E);

	for (i = 1; i <= V; i++){//인접행렬 초기화 
		for (j = 1; j <= V; j++){
			dynamic[i][j] = INF;
		}
	}

	for (i = 1; i <= V; i++){ //v_i에서 v_i로의 길이는 0이다. 
		dynamic[i][i] = 0;
	}

	for (i = 0; i < E; i++){
		scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
		dynamic[tmp1][tmp2] = tmp3;
	}
}

/*
find_short_length:
	중간 경로 {v_1, v_2, ... , v_k} 일 때
	
	case1) 최단 경로에 k가 포함된 경우
			dynamic[i][j] = dynamic[i][k] + dynamic[k][j]

	case2) 최단 경로에 k가 포함되지 않는 경우
			dynamic[i][j]
*/

void get_length(int start, int end){
	
	int k = path[start][end];

	if (k != 0){
		length++;
		get_length(start, k);
		get_length(k, end);
	}
}


void find_path(int start, int end){
	int k;

	if (path[start][end] == 0){
		printf("%d ", start);
	}

	else{
		k = path[start][end];
		find_path(start, k);
		find_path(k, end);
	}
	
}

int main(){
	
	int i; int j; int k; 
	input(); //인접행렬 초기화 및 정보 입력받음.

	for (k = 1; k <= V; k++){
		for (i = 1; i <= V; i++){
			for (j = 1; j <= V; j++){
				if (dynamic[i][k] + dynamic[k][j] < dynamic[i][j]){
					dynamic[i][j] = dynamic[i][k] + dynamic[k][j]; 
					path[i][j] = k;
				}
			}
		}
	}
	
	printf("%d\n", dynamic[start_v][end_v]); 
	get_length(start_v, end_v);
	printf("%d\n",length+2);
	find_path(start_v, end_v);
	printf("%d", end_v);

	return 0;
}