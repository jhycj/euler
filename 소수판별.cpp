#include<stdio.h>
#include<mpi.h>


int arr[30001]; //정수 1~30000 사이의 정수 x가 소수이면 p[x] = 1 , 소수가 아니면 p[x] = 0
int prime[10000]; //소수 담는 배열

void is_prime(void){ //p[]의 값을 채워주는 함수 
	int i; 
	int n;
	int rear=0;
	int front = 0;

	arr[2] = 1; //나머지 arr[2n] = 0 으로 초기화 되어있음
	prime[rear] = 2; 
	rear++;//rear = 1;

	arr[3] = 1; 
	prime[rear] = 3; 
	rear++; //rear =2;

	for (n = 4; n <= 30000; n++){
		
		if (n % 2 != 0){ //i가 4이상의 홀수이면 
			
			front = 0;

			while (rear>front){
			
				if (n % prime[front] == 0){//이전에 구한 소수의 배수이면 
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


