#include<stdio.h>

int main() {
	int i; int j; 
	int rear; int rear2;
	int I[100] = { 0, };//������ 
	int A[100];//A ���� ���� 
	int B[100]; //B ���� ���� 
	int n_A;//A�� ���� ���� 
	int n_B; //B�� ���� ���� 
	int tmp;
	scanf("%d", &n_A);
	for (i = 0; i < n_A; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &n_B);
	for (i = 0; i < n_B; i++) {
		scanf("%d", &B[i]);
	}

	for (i = 2; i <= n_A; i++) {
		for (j = 0; j <= n_A -i; j++) {
			if (A[j] > A[j+1]){
				tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp; 
			}
		}
	}

	for (i = 2; i <= n_B; i++) {
		for (j = 0; j <= n_B - i; j++) {
			if (B[j + 1] < B[j]) {
				tmp = B[j + 1];
				B[j + 1] = B[j];
				B[j] = tmp;
			}
		}
	} //�������� ���� �Ϸ�! 

	rear = 0; 

	for (i = 0; i < n_A; i++) {
		for (j = 0; j < n_B; j++) {
			if (A[i] == B[j]) {
				I[rear] = A[i];
				rear++;
				A[i] = 0;
			}
		}
	}

	rear2 = n_B; 

	if (rear != 0) { //�������� �������� �ƴ� ��� //B���տ� 0�ƴ� A�� ���Ҹ� �߰��� ���� 

		for (i = 0; i < n_A; i++) {
			if (A[i] != 0) {
				B[rear2] = A[i];
				rear2++;
			}
		}
		
		for (i = 2; i <= rear2; i++) {
			for (j = 0; j <= rear2 - i; j++) {
				if (B[j + 1] < B[j]) {
					tmp = B[j + 1];
					B[j + 1] = B[j];
					B[j] = tmp;
				}
			}
		} //B���� �������� ���� �Ϸ�! 
		
		for (i = 0; i < rear2; i++) {
			printf("%d ", B[i]);
		}
		printf("\n");
		for (i = 0; i < rear; i++) {
			printf("%d ", I[i]);
		}
	}
	
	else {

		for (i = 0; i < n_A; i++) {
			B[rear2] = A[i]; 
			rear2++;
		}

		for (i = 2; i <= rear2; i++) {
			for (j = 0; j <= rear2 - i; j++) {
				if (B[j] > B[j + 1]) {
					tmp = B[j + 1];
					B[j + 1] = B[j];
					B[j] = tmp;
				}
			}
		}

		for (i = 0; i < rear2; i++) {
			printf("%d ", B[i]);
		}
		printf("\n");
		printf("-1\n");

	}


	return 0;
}