#include<stdio.h>
int path[101];
int deadline;
int N; //정비소 갯수
int distance[101];
int time[101];
int dynamic[101];
int min_index[101];

int get_min_index(int index){
   int i;
   int sum;
   sum = 0;
   for (i = index - 1; i>=0; i--){
      sum = sum + distance[i];
      if (sum > deadline){
         return i+1;
         break;
      }
      else if (sum == deadline){
         return i;
         break;
      }
   }
}

void get_min_index_array(void){
   int i;
   min_index[0] = 0;
   min_index[1] = 0;
   for (i = 2; i <= N + 1; i++){
      if (get_min_index(i) == -1){
         min_index[i] = 0;
      }
      else{
         min_index[i] = get_min_index(i);
      }
   }
   printf("\n");
   for (i = 0; i <= N + 1; i++){
      printf("%d ", min_index[i]);
  }
  printf("\n");
}

void get_dynamic(void){
   int i; int j;
   int x;
   int min;
   dynamic[0] = 0;
   dynamic[1] = time[1];
   for (i = 2; i <= N + 1; i++){
      min = dynamic[i - 1]+time[i];
      for(j=i-1; j>=min_index[i]; j--){
          if(min > dynamic[j]+time[i]){
              min = dynamic[j]+time[i];
              path[i] = j;
          }
      }
      dynamic[i] = min;
   }
}

int main(){
   int i;
   scanf("%d", &deadline);
   scanf("%d", &N); //정비소 갯수
   for (i = 0; i < N + 1; i++){
      scanf("%d", &distance[i]);
   }
   for (i = 1; i <= N; i++){
      scanf("%d", &time[i]);
   }

   get_min_index_array();


   if (min_index[N + 1] == 0){
      printf("0\n");
      printf("0\n");
   }
   else{
       get_dynamic();
       for(i=0; i<=N+1; i++){
           printf("%d ", dynamic[i]);
       }
       printf("\n");
       for(i=0; i<=N+1; i++){
           printf("%d ", path[i]);
       }
   }

   /*for (i = 0; i < N + 1; i++){
      printf("%d", distance[i]);
   }
   for (i = 0; i < N; i++){
      printf("%d", time[i]);
   }*/
   return 0;
}
