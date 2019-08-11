#include<stdio.h>
int size[105];
int dynamic[105];
int answer;


int main() {
	int i; int j;
	int N;
	int lis[101]={0,};

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &size[i]);
	}

	size[0] = 0;
	dynamic[0] = 0;

	for (i = 1; i <= N; i++) {
		for (j = 0; j <= i-1; j++) {
			if (size[j]<size[i]) {
				if(dynamic[j]+1>dynamic[i]){
					dynamic[i] = dynamic[j]+1;
				}
			}
		}
	}
	answer = dynamic[1];
	for(i=1; i<=N; i++){
		if(answer<dynamic[i]){
			answer = dynamic[i];
		}
	}

	printf("%d\n", answer);

	lis[answer+1] = N+1;

	for (i=answer; i>=1; i--){
		for(j=N; j>=1; j--){
			if(lis[i]<=j &&lis[i+1]>j && dynamic[j] == i){
				lis[i] = j;
			}
		}
	}

	for(i=1; i<=answer; i++){
		printf("%d ",size[lis[i]]);
	}
	return 0;
}
