#include <stdio.h>
#include <stdlib.h>

int count=1;
int binarysearch(int *arr, int low , int high, int target){
    if(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target) return mid;

        if(arr[mid]>target) {
            count++;
            return binarysearch(arr,low,mid-1,target);
        }

        if(arr[mid]<target){
            count++;
            return binarysearch(arr,mid+1,high,target);
        }
    }
    return -1;
}

int main(){
    int n,target; scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    scanf("%d",&target);
    int ans = binarysearch(arr,0,n-1,target);
    printf("%d\n%d",ans,count);
    free(arr);
}