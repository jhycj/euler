#include <iostream>
#include <queue>

using namespace std; 
int map[101][101] = {0,}; 

int main(){
    
    int R, C; 
    int sy, sx;
    string tmp;
    //char tmp;
    int i, j; 
    cin >> R>>C; 
    cout<<R;

    for( i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            cout << map[i][j] ;
        }
        cout<<endl;
    }
  


    for(i=0; i<R; R++){
        cin >> tmp ;
        cout<<tmp<<endl;
        for(j=0; j<C; j++){
            //tmp = str[j]; 
            //cout<<tmp<< endl;
            if(tmp.at(j) == '.'){
                map[i][j] = 0; 
            }
            else if(tmp.at(j)=='*'){
                map[i][j] = 1;
            }
            else if (tmp.at(j) == 'C'){
                sy = i+1; 
                sx = j+1; 
                map[i][j] = 0;
            }
            else if(tmp.at(j) == 'B'){
                map[i][j] = 0;
            }
        }
    }
    cout<<'j';
    for( i = 0; i< R; i++){
        for(j = 0; j< C; j++){
            cout << map[i][j] ;
        }
        cout<<endl;
    }



    return 0;
}