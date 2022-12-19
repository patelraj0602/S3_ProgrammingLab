#include <stdio.h>
#include <stdlib.h>
int main(){
    int c = 2001; int r = 10001;
    int **lookup = (int **)malloc(c*sizeof(int*));
    for(int i=0; i<c; i++) lookup[i]=(int*)malloc(r*sizeof(int));

    int *freq = (int*)calloc(2001,sizeof(int));
    int n; scanf("%d",&n);
    int *elements = (int*)malloc(n*sizeof(int));

    int j=0; int flag=0;
    for(int i=0; i<n; i++){
        int tmp; scanf("%d",&tmp);
        if(freq[tmp+1000]==0) {
            elements[j]=tmp; 
            lookup[tmp+1000][freq[tmp+1000]]=i;
            freq[tmp+1000]++; j++;
        }
        else{
            lookup[tmp+1000][freq[tmp+1000]]=i;
            freq[tmp+1000]++;
            if(freq[tmp+1000]>=2) flag=1;
        }
    }
    if(flag==0){printf("-1"); return 0;}
    for(int i=0; i<j; i++){
        int tmp = elements[i];
        if(freq[tmp+1000]>1){
            printf("%d ",elements[i]);
            for(int p=0; p<freq[tmp+1000]; p++) printf("%d ",lookup[tmp+1000][p]);
            printf("%d",freq[tmp+1000]);
            printf("\n");
        }
    }
    for(int i=0; i<c; i++) free(lookup[i]);
    free(lookup);
}