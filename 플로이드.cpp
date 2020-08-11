#define INF 999;
#include<stdio.h>
int path[51][51];
int length;
int V;//�׷��� ������ ���� 
int E;//�׷��� ���� ���� 
int start_v;//������
int end_v;//������
int dynamic[51][51];//v_i ���� v_j���� �ִ� ����� ���� (dynamic)

void input(void){ //�Է¹޴� ��� 
	int i; int j;
	int tmp1; int tmp2; int tmp3;

	scanf("%d %d %d", &V, &start_v, &end_v);
	scanf("%d", &E);

	for (i = 1; i <= V; i++){//������� �ʱ�ȭ 
		for (j = 1; j <= V; j++){
			dynamic[i][j] = INF;
		}
	}

	for (i = 1; i <= V; i++){ //v_i���� v_i���� ���̴� 0�̴�. 
		dynamic[i][i] = 0;
	}

	for (i = 0; i < E; i++){
		scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
		dynamic[tmp1][tmp2] = tmp3;
	}
}

/*
find_short_length:
	�߰� ��� {v_1, v_2, ... , v_k} �� ��
	
	case1) �ִ� ��ο� k�� ���Ե� ���
			dynamic[i][j] = dynamic[i][k] + dynamic[k][j]

	case2) �ִ� ��ο� k�� ���Ե��� �ʴ� ���
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
	input(); //������� �ʱ�ȭ �� ���� �Է¹���.

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