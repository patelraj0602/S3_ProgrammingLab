#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int non_decreasing(int val){
    int last = val%10; val/=10;
    while(val>0){
        if((val%10)>last) return 0;
        last=val%10; val/=10;
    }
    return 1;
}

int main(){
    int n; scanf("%d",&n);
    int ans=0; int tmp;
    for(int i=0; i<n; i++){
        scanf("%d",&tmp);
        if(non_decreasing(abs(tmp))==1) printf("%d ",tmp);
    }
}