#include<stdio.h>
#define INF 999999
int m;//세로
int n;//가로
int A;
char map[102][102];
int river[101][101];
int water_map[102][102];

int sy; int sx;
int ey; int ex;
int Q[10100];

void water_map_bfs(void){
   int i; int j; int k;
   int dy[4] = { 0, 1, 0, -1 };
   int dx[4] = { 1, 0, -1, 0 };
   int ty; int tx;
   int y; int x;
   int rear = 0;
   int front = 0;


   for(i=1; i<=m; i++){
       for(j=1; j<=n; j++){
           if(water_map[i][j] == 0){
               Q[rear] = i;
               rear++;
               Q[rear] = j;
               rear++;
           }
       }
   }

   while(rear>front){
       y = Q[front];
       front++;
       x = Q[front];
       front++;

       for(i=0; i<4; i++){
           ty = y+dy[i];
           tx = x+dx[i];

           if(ty>=1 && ty<=m && tx>=1 && tx<=n && water_map[ty][tx]>=water_map[y][x]+A){
               water_map[ty][tx] = water_map[y][x] + A;
               Q[rear]= ty;
               rear++;
               Q[rear] = tx;
               rear++;
           }
       }
   }
}


void bfs(int sy, int sx){
   int ty; int tx;
   int y; int x;
   int i; int j;
   int k;
   int rear = 0;
   int front = 0;
   int dy[4] = { 0, 1, 0, -1 };
   int dx[4] = { 1, 0, -1, 0 };


   Q[rear] = sy;
   rear++;
   Q[rear] = sx;
   rear++;

   while (rear > front){
      y = Q[front];
      front++;
      x = Q[front];
      front++;

      for (i = 0; i < 4; i++){
         ty = y + dy[i];
         tx = x + dx[i];

         if (water_map[ty][tx]>= river[y][x]+1 && ty >= 1 && ty <= m && tx >= 1 && tx <= n &&
            river[y][x] + 1 <= river[ty][tx]){

            river[ty][tx] = river[y][x] + 1;

            Q[rear] = ty;
            rear++;
            Q[rear] = tx;
            rear++;

         }
      }
      /*printf("\n");
      for(i=1; i<=m; i++){
          for(j=1; j<=n; j++){
              printf("%d ", river[i][j]);
          }
          printf("\n");
      }
      printf("\n");*/
  }
}



int main(){
   int i;
   int j;

   scanf("%d %d %d", &m, &n, &A);

   for (i = 1; i <= m; i++){
      scanf("%s", &map[i][1]);
   }

   for(i=1; i<=m; i++){
       for(j=1; j<=n; j++){
           water_map[i][j] = INF;
       }
   }

   for (i = 1; i <= m; i++){
      for (j = 1; j <= n; j++){
         if (map[i][j] == 'F'){
            water_map[i][j] = 0;
            river[i][j] = -1;

         }
         else if (map[i][j] == 'O'){
            river[i][j] = INF;
         }
         else if (map[i][j] == 'Y'){
            river[i][j] = 0;
            sy = i;
            sx = j;
         }

         else if (map[i][j] == 'S'){
            river[i][j] = INF;
            ey = i;
            ex = j;
         }
      }
   }

   water_map_bfs();
   bfs(sy, sx);

   printf("%d", river[ey][ex]);
   /*for(i=1; i<=m; i++){
       for(j=1; j<=n; j++){

           printf("%d ", river[i][j]);
       }
       printf("\n");
   }*/




   return 0;
}
