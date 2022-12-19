#include <stdio.h>
#include <stdlib.h>

int helper(int n){
    int a=0; int b=n;
    while(n>0){
        a+=n%10; n=n/10;
        a*=10;
    }
    a/=10;
    if(a==b) return 1;
    else return 0;
}

int main(){
    int n; scanf("%d",&n);
    int* arr = (int*)malloc(n * sizeof(int));
    int ans=0;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i]>=0){
            if(helper(arr[i])) ans++;
        }
    }
    printf("%d\n",ans);
    free(arr);

}
