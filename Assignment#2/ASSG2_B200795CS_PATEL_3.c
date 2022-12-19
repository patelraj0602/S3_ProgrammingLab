#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int helper(char *str, char* substr, int i){
    int sz1 = strlen(str);
    int sz2 = strlen(substr);
    if(sz1-i<sz2) return 0;
    else{
        for(int j=0; j<sz2; j++){
            if(str[i]==substr[j]) i++;
            else return 0;
        }
    }
    return 1;
}

int main(){
    char str[100000]; char substr[100000];
    scanf("%s %s",str,substr);
    int len = strlen(str);    
    int* lookup = (int*)malloc(len*sizeof(int));
    for(int i=0; i<len; i++) lookup[i]=-1;

    int i=0;
    while(i<len){
        if(helper(str,substr,i)==1){
            for(int j=i; j<i+strlen(substr); j++) lookup[j]=0;
        }
        else if(lookup[i]!=0) lookup[i]=1; 
        i++;
    }
    for(int k=0; k<strlen(str);k++){
        if(lookup[k]==1) printf("%c",str[k]);
    }
    free(lookup);
}