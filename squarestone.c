#include<stdio.h>
int N;
int arr[201][201];
int dynamic[201][201]; 
int answer[201];


void get_input(void){
	int i; int j;
	char tmp[202];
	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		scanf("%s", &tmp[1]);
		for (j = 1; j <= N; j++){
			if (tmp[j] == '0'){
				arr[i][j] = 0; 
			}
			else{
				arr[i][j] = 1; 
			}
		}
	}
}

void init_dynamic(int k){
	int i; int j;
	int num=0;
	for (i = k; i <= N; i++){
		for (j = k; j <= N; j++){
			if (dynamic[i][j] == 1){
				num++;
			}
			arr[i][j] = dynamic[i][j];
		}
	}

	answer[k] = num;

	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			dynamic[i][j] = 0;  // ÃÊ±âÈ­ 
		}
	}
}

void print_answer(void){
	int i;
	for (i = 2; i <= N; i++){
		if (answer[i] != 0){
			printf("%d : %d\n", i, answer[i]);
		}
	}
}

int main(){
	int i, j, k;
	int count; 
	int l;
	int dy[4] = { 0, 0, -1, -1 };
	int dx[4] = { 0, -1, -1, 0 };
	int x, y;
	int tx, ty;
	get_input();

	for (k = 2; k <= N; k++){
		for (i = k; i <= N; i++){
			for (j = k; j <= N; j++){
				y = i; 
				x = j; 
				count = 0;
				for (l = 0; l < 4; l++){
					ty = y + dy[l];
					tx = x + dx[l];
					if (arr[ty][tx] == 1){
						count++;
					}
				}

				if (count == 4){
					dynamic[y][x] = 1; 
				}
			}
		}

		init_dynamic(k);
	}

	print_answer();

	return 0;
}