#include<stdio.h>
long long map[26][26];
long long dynamic[26][26];
int n;

int main(){
    int i; int j; int k;
    scanf("%d", &n);
    long long answer;
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            scanf("%d", &map[i][j]);
        }
    }

    dynamic[1][1] = map[1][1];


    for(i=2; i<=n; i++){
        for(j=1; j<=i; j++){
            for(k=1; k>=0; k--){
                if(dynamic[i][j]<=dynamic[i-1][j-k] + map[i][j]){
                        dynamic[i][j] = dynamic[i-1][j-k]+ map[i][j];
                }
            }
        }
    }

    answer = dynamic[1][1];

    for(i=1; i<=n; i++){
        if(answer<=dynamic[n][i]){
            answer = dynamic[n][i];
        }
    }

    printf("%d\n", answer);



    return 0;
}
