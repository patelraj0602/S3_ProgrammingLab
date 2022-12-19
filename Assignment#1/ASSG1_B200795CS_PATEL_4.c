#include <stdio.h>
#include <stdlib.h>
int *ptr;
int* to_binary(int n){
    ptr = (int*)malloc(16*sizeof(int));
    for(int i=15; i>=0; i--){
        ptr[i]=n%2;
        n/=2;
    }
    return ptr;
}
int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int* arr = to_binary(n);

    //To binary..
    for(int i=0; i<16; i++) printf("%d", arr[i]);
    printf("\n");

    //Left shift..
    printf("%d",arr[k%16]);
    for(int i=k+1; (i%16)!=(k%16); i++) printf("%d", arr[i%16]);
    printf("\n");

    //Right shift..
    int a=16-k; printf("%d",arr[a%16]);
    for(int i=a+1; (i%16)!=(a%16); i++) printf("%d", arr[i%16]);

    free(ptr);
    return 0;
}