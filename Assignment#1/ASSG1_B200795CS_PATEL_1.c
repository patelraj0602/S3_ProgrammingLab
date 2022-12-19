#include <stdio.h>
#include <math.h>
int main(){
    int n; scanf("%d", &n);
    int tmp=0; int ans=0;
    while(n>0){
        int b = n%10;
        ans+=(b*pow(8,tmp));
        n/=10; tmp++;
    }
    printf("%d",ans);
}