#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b; scanf("%d %d",&a,&b);

    //The frequency of particular element..
    int* lookup = (int*)calloc(2001,sizeof(int));

    //Stores the distinct elements in a continuous manner..
    int *checker = (int*)malloc(2001*sizeof(int));
    int j=0;
    for(int i=0; i<(a+b); i++){
        int tmp; scanf("%d",&tmp);
        if(lookup[1000+tmp]==0){checker[j]=tmp; j++;}
        lookup[1000+tmp]++;
    }
    for(int i=0; i<j; i++){
        if(lookup[checker[i]+1000]>1){
            int c = lookup[checker[i]+1000]; int d = checker[i];
            for(int i=0; i<c; i++) printf("%d ",d);
        }
    }
    for(int i=0; i<j; i++){
        if(lookup[checker[i]+1000]==1) printf("%d ",checker[i]);
    }
    free(checker);
    free(lookup);
}