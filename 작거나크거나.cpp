#include<stdio.h>

int main(){
	int x; int y;
	scanf("%d %d", &x, &y);
	if (x > y){
		printf(">");
	}
	else if (x < y){
		printf("<");
	}
	else{
		printf("=");
	}
}