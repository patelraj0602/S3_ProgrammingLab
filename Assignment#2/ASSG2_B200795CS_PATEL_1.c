#include <stdio.h>
#include <stdlib.h>
int main(){
    int n; scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    int non_negative=0;
    int max = -1000;
    int ans = 0;
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
        if(arr[i]>max) max=arr[i];
        if(arr[i]>=0) {
            non_negative++;
            ans+=arr[i];
        }
    }
    if(non_negative==0) printf("%d 1",max);
    else printf("%d %d",ans, non_negative);
    free(arr);
}