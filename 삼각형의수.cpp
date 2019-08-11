#include<stdio.h>
int n; //삼각형의 줄 수
int depth[500520];
int data[500520];
int dynamic[500520];

void dyn(int vertex_num){
    int front;
    int x;
    int tx;
    int d; //data
    int D; //depth;
    int i;

    front = 1;

    while(vertex_num>=front){
        x= front;
        d = data[x];
        D = depth[x];
        for(i=0; i<2; i++){
            tx = x+D+i;
            if(tx>=1 && tx<= vertex_num){
                // 여기가 잘못된 인덱스. front가 마지막 줄의 한 원소의 인덱스일 경우를 생각해 보자.
                // 할당되지 않은 메모리에 접근하게 됨. segmataion fault.
                if(dynamic[tx] <=dynamic[x] + data[tx]){
                    dynamic[tx] = dynamic[x]+data[tx];
                }
            }
        }
        front++;
    }
}

int find_max(int rear){
    int i;
    int max = dynamic[rear-1];

    for(i=1; i<n; i++){
        if(max<=dynamic[rear-1-i]){
            max = dynamic[rear-1-i];
        }
    }
    return max;
}

int main(){
    int i; int j;
    int rear;
    rear = 1;
    int answer;

    scanf("%d\n", &n);
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            scanf("%d", &data[rear]);
            depth[rear] = i;
            rear++;
        }
    }

    dynamic[1] = data[1];
    dyn(rear-1);
    answer= find_max(rear);
    /*for(i=1; i<rear; i++){
            printf("%d ", dynamic[i]);
        }
    printf("\n");*/
    printf("%d", answer);

    return 0;
}
