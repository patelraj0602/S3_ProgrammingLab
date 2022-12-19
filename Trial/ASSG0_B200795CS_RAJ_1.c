#include <stdio.h>
int main(){
    int n; int a=0;
    scanf("%d", &n);
    int b=n;
    while(n>0){
        a+=n%10; n=n/10;
        a*=10;
    }
    a/=10;
    if(a==b) printf("YES\n");
    else printf("NO\n");
}
