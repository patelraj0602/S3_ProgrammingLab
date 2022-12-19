#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int gcd(int a,int b,int c){
    if((a%c==0) && (b%c==0)) return c;
    return gcd(a,b,c-1);
}
int main(){
    int a,b; scanf("%d %d", &a, &b);
    a=abs(a); b=abs(b);
    int c = a>b ? b : a;
    int d = a>b ? a : b;
    if((a==0) || (b==0)) printf("%d",d);
    else printf("%d",gcd(a,b,c));
}