#include<stdio.h>
#include<mpi.h>


int arr[30001]; //���� 1~30000 ������ ���� x�� �Ҽ��̸� p[x] = 1 , �Ҽ��� �ƴϸ� p[x] = 0
int prime[10000]; //�Ҽ� ��� �迭

void is_prime(void){ //p[]�� ���� ä���ִ� �Լ� 
	int i; 
	int n;
	int rear=0;
	int front = 0;

	arr[2] = 1; //������ arr[2n] = 0 ���� �ʱ�ȭ �Ǿ�����
	prime[rear] = 2; 
	rear++;//rear = 1;

	arr[3] = 1; 
	prime[rear] = 3; 
	rear++; //rear =2;

	for (n = 4; n <= 30000; n++){
		
		if (n % 2 != 0){ //i�� 4�̻��� Ȧ���̸� 
			
			front = 0;

			while (rear>front){
			
				if (n % prime[front] == 0){//������ ���� �Ҽ��� ����̸� 
					break;
				}

				else if (n % prime[front] != 0){
					front++;
			
				}
			}

			if (front == rear){
				arr[n] = 1; 
				prime[rear] = n;
				rear++;
			}
		}
	}
	printf("%d %d\n ", prime[rear - 1], rear - 1);

}


int main(){
	int i;

	is_prime(); 

	/*for (i = 0; i < 10000; i++){
		printf("%d\n",prime[i]);
	}*/
	return 0;
}


