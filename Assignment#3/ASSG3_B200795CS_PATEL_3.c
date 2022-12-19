#include <stdio.h> 
#include <stdlib.h>

int binarysearch(int *arr, int low, int high, int target){
    if(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target) return 1;

        if(arr[mid]<target) return binarysearch(arr,low,mid-1,target);

        if(arr[mid]>target) return binarysearch(arr,mid+1,high,target);
    }
    return -1;
}

int main(){
    int a,b; scanf("%d %d",&a,&b);
    int * find = (int*)malloc(a*sizeof(int));
    int * lookup = (int*)malloc(b*sizeof(int));

    for(int i=0; i<a; i++) scanf("%d",&find[i]);
    for(int i=0; i<b; i++) scanf("%d",&lookup[i]);

    for(int i=0; i<a; i++){
        if(binarysearch(lookup,0,b-1,find[i])==1) printf("%d ",find[i]);
    }
        
    free(find);
    free(lookup);

}