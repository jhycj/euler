#include<stdio.h>
#define INF 987654321
int N; //주유소 갯수 
int distance[101]; 
int cost[101]; 
int dynamic[5005];

int total_distance; 





void get_total_distance(void){
	int i; 
	for (i = 1; i <= N; i++){
		total_distance = total_distance + distance[i];
	}
}
void initialize_dynamic(void){
	int i;
	int j;
	int rear = 1;

	for (i = 1; i <= 5000; i++){
		dynamic[i] = INF;
	}

	for (i = 1; i <= N; i++){
		for (j = rear; j < rear+50; j++){
			if (dynamic[j] > cost[i]){
				dynamic[j] = cost[i];
			
			}
		}
		rear = rear + distance[i]; 
	}
}

int main(){
	int i;
	int answer=0;

	scanf("%d", &N);//스키장 갯수 
	for (i = 1; i <= N; i++){
		scanf("%d", &distance[i]);
	}
	for (i = 1; i <= N; i++){
		scanf("%d", &cost[i]);
	}
	get_total_distance();
	initialize_dynamic();
	
	
	for (i = 1; i <= total_distance; i++){
		answer = answer + dynamic[i];
	}
	printf("%d", answer);

	return 0;
}