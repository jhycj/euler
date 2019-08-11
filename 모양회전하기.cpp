#include<stdio.h>
int rot;
int n; int theta;
int new_y;
int new_x;
char map1[101][101];
char map2[101][101];



void get_pos_90_ele(int y, int x){
      new_y = x;
      new_x = n-y+1;
      map2[new_y][new_x] = map1[y][x];
}

void get_pos_90_ent(int n){
    int i; int j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            get_pos_90_ele(i, j);
        }
    }
}

void move_to_map2(void){
    int i; int j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            map1[i][j] = map2[i][j];
        }
    }
}

int main(){
    int i; int j; int k;
    scanf("%d %d\n", &n, &theta);

    for(i=1; i<=n; i++){
        for(j=1; j<=n-1; j++){
            scanf("%c", &map1[i][j]);
            scanf(" ");
        }
        scanf("%c\n", &map1[i][j]);
    }
    rot = theta/90;

    if(rot==0|| rot==4){
        for(i=1;i<=n; i++){
            for(j=1; j<=n-1; j++){
                printf("%c", map1[i][j]);
                printf(" ");
            }
            printf("%c\n", map1[i][j]);
        }
    }

    else{
        for(k=1; k<=rot; k++){
            get_pos_90_ent(n);
            move_to_map2();
        }

        for(i=1;i<=n; i++){
            for(j=1; j<=n-1; j++){
                printf("%c", map2[i][j]);
                printf(" ");
            }
            printf("%c\n", map2[i][j]);
        }
    }

    return 0;
}
