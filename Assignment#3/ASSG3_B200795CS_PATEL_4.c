#include <stdio.h> 
#include <stdlib.h>
#define INF 1000000007


int merge(int* arr, int low, int mid, int high){
    int count = 0;
    int tmp1 = mid-low+1;
    int tmp2 = high-mid;
    int *arr1 = (int*)malloc((tmp1+1)*sizeof(int));
    int *arr2 = (int*)malloc((tmp2+1)*sizeof(int));

    for(int i=0; i<tmp1; i++) arr1[i]=arr[low+i];
    arr1[tmp1]=INF;
    for(int i=0; i<tmp2; i++) arr2[i]=arr[mid+1+i];
    arr2[tmp2]=INF;
    
    int a=0; int b=0;
    for(int i=low; i<=high; i++){
        count++;
        if(arr1[a]<=arr2[b]){
            arr[i]=arr1[a];
            a++;
        }
        else{
            arr[i]=arr2[b];
            b++;
        }
    }

    free(arr1);
    free(arr2);
    return count;
}

int mergesort(int* arr, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        return(mergesort(arr,low,mid)+mergesort(arr,mid+1,high)+merge(arr,low,mid,high));
    }
    return 0;
}

void printer(int* arr, int n){
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int n; scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);

    int count = mergesort(arr,0,n-1);
    printer(arr,n);
    printf("%d",count);
    free(arr);
}