#include <stdio.h>

struct Paper{
    Paper(){}
    Paper(int w, int h):width(w),height(h),area(w*h),stackable(0){
        if(w < h ){
            width = h;
            height = w;
        }
    }
    bool operator>=(Paper& other)const{
        return (width >= other.width)&&(height >= other.height);
    }
    int width;
    int height;
    int area;
    int stackable;
};

int get_input(Paper* papers){
int n = 0;
int width = 0;
int height = 0;
    scanf("%d",&n);
    for(int i=0; i< n ; ++i){
        scanf("%d",&width);
        scanf("%d",&height);
        papers[i] = Paper(width,height);
    }
    return n;
}


int main(){
    Paper papers[100];
    int num_papers = get_input(papers);
    int count =0;
    for(int i = num_papers-1; i>=0; i --){
        for(int j = 0; j < i; j++ ){
            if(papers[j].area > papers[j+1].area){
                Paper tmp = papers[j];
                papers[j] = papers[j+1];
                papers[j+1]=tmp;
            }
        }
    }

    for(int i =0; i <num_papers; ++i){
        int max_idx = i;
        int max_stack_count = 0;
        for(int j=0; j<i; j++){
            if((papers[j].stackable > max_stack_count)&&(papers[i] >= papers[j])){
                max_idx = j;
                max_stack_count = papers[j].stackable;
            }
        }
        papers[i].stackable = max_stack_count+1;
        if(count < papers[i].stackable){
            count = papers[i].stackable;
        }
        //printf("%d : %d, %d , stack : %d\n",i, papers[i].width,papers[i].height,papers[i].stackable);
    }
    printf("%d",count);
    return 0;
}
