//In the design which I submitted I used getchar() to take input but it
//did not work so I am submitting this code which has sligtly different method
//of taking input..

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function 1 to toggle str1 and str2
void toggle(char* s){
    int len = strlen(s);
    for(int i=0; i<len; i++){
        if((s[i]>=97) && (s[i]<=122)) s[i]-=32;
        else  s[i]+=32;
    }
}

void mergeandprint(char* s, char* t){
    int sz = strlen(s)+strlen(t);

    //Merging the array..
    char* merge = (char*)malloc(sz*sizeof(char*));
    for(int i=0; i<sz; i++){
        if(i<strlen(s)) merge[i]=s[i];
        else merge[i]=t[i-strlen(s)];
    }

    //Printing that merged array
    for(int i=sz-1; i>=0; i--) printf("%c",merge[i]);
    free(merge);
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        char s[100000]; char t[100000];
        scanf("%s %s",s,t);
        toggle(s); toggle(t);
        
        mergeandprint(s,t);
        printf("\n");
    }
}