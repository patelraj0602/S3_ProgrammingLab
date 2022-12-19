#include <stdio.h>
#include <stdlib.h>

//Using insertion sort for this particular question..
void sorting(int* arr, int n){

    for(int i=1; i<n; i++){
        int j; int tmp = arr[i];
        for(j=i-1; j>=0 && arr[j]>tmp; j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=tmp;
    }
}

int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    sorting(arr,n);

    int ans=0;
    for(int i=0; i<m; i++) ans+=(arr[n-1-i]-arr[i]);
    printf("%d",ans);
    free(arr);
}