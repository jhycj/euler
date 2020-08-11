#include<stdio.h>
#define max2(x,y) (x>y? x:y)

int N;
int money[30001];
long long get0[30001];
long long get1[30001];
long long get2[30001];
long long dynamic[30001];

long long find_max(int index){
	return max2(max2(get2[index], get1[index]), get0[index]);
}

void initialize(void){
	get0[1] = 0;
	get1[1] = money[1];
	get2[1] = 0;
	dynamic[1] = money[1];
}

void get_dynamic(int index){

	get0[index] = dynamic[index - 1];
	get1[index] = get0[index - 1] + money[index];
	get2[index] = get1[index - 1] + money[index];
	dynamic[index] = find_max(index);
}

void get_dynamic_array(void){
	int i;
	for (i = 2; i <= N; i++){
		get_dynamic(i);
	}
}

int main(){
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		scanf("%d", &money[i]);
	}
	initialize();
	get_dynamic_array();
	printf("%lld", dynamic[N]);

	return 0;
}