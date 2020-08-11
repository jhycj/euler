#include<stdio.h>
int A[101][101];
int V;
int E;

int main(){
	int i;
	int j;
	int a; int b; int c;
	scanf("%d\n", &V);
	scanf("%d\n", &E);

	for (i = 0; i < E; i++){
		scanf("%d %d %d", &a, &b, &c); 
		A[a][b] = c;
	}

	for (i = 1; i <= V; i++){
		for (j = 1; j <= V; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	

}