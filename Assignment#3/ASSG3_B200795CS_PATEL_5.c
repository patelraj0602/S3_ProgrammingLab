#include <stdio.h> 
#include <stdlib.h>

#define mod 1000000007
void merge(int* arr, int low, int mid, int high, int* inversion,int* count){

    int tmp1 = mid-low+1;
    int tmp2 = high-mid;
    int *arr1 = (int*)malloc((tmp1+1)*sizeof(int));
    int *arr2 = (int*)malloc((tmp2+1)*sizeof(int));

    for(int i=0; i<tmp1; i++) arr1[i]=arr[low+i];
    arr1[tmp1]=mod;
    for(int i=0; i<tmp2; i++) arr2[i]=arr[mid+1+i];
    arr2[tmp2]=mod;
    
    int a=0; int b=0;
    for(int i=low; i<=high; i++){
        (*count)++;
        if(arr1[a]<=arr2[b]){
            arr[i]=arr1[a];
            a++;
        }
        else{
            (*inversion)+=(tmp1-a);
            arr[i]=arr2[b];
            b++;
        }
    }

    free(arr1);
    free(arr2);
}

void mergesort(int* arr, int low, int high,int* inversion,int* count){
    if(low<high){
        int mid = (low+high)/2;
        mergesort(arr,low,mid,inversion,count);
        mergesort(arr,mid+1,high,inversion,count);
        merge(arr,low,mid,high,inversion,count);
    }
}

int main(){
    int n; scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    
    int inversion = 0;
    int count=0;
    mergesort(arr,0,n-1,&inversion,&count);
    printf("%d\n%d",inversion,count);
    free(arr);
}