#define INF 9999999
#include<stdio.h>

int V; //노드 개수 1000개 이하 
int E; //간선 개수 
int weight[1001][1001];
long cost[1001];
int stage[1001];
int Q[3000];
int visit[1001];
long sum_cost; 
long sum_stage;

void default_weight(void){
	int i; int j;
	for (i = 1; i <= V; i++){
		for (j = 1; j <= V; j++){
			weight[i][j] = INF;
		}
	}

	for (i = 1; i <= V; i++){
		cost[i] = INF;
	}
	cost[1] = 0; 

	stage[1] = 1;

}

void bfs(void){
	int x;
	int i; int j;
	int rear = 0;
	int front = 0; 

	Q[rear] = 1; 
	rear++;
	
	while (rear > front){
		x = Q[front];
		front++;
		visit[x] = -1; 

		for (i = 1; i <= V; i++){
			if (weight[x][i] != INF && visit[i] != -1){
				if (cost[i] > cost[x] + weight[x][i]){
					cost[i] = cost[x] + weight[x][i];
					stage[i] = stage[x] + 1; 
					Q[rear] = i; 
					rear++; 
				}
			}
		}
	}
}


int main(){
	int i; int j;
	int tmp1 = 0; 
	int tmp2=0; 
	int tmp3=0; 

	scanf("%d", &V);
	scanf("%d", &E);
	
	default_weight();
	for (i = 0; i < E; i++){
		scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
		weight[tmp1][tmp2] = tmp3;
	}
	bfs();

	for (i = 1; i <= V; i++){
		sum_cost += cost[i];
		sum_stage += stage[i];
	}
	printf("%ld\n", sum_cost); 
	printf("%ld\n", sum_stage);
	
	return 0;
}