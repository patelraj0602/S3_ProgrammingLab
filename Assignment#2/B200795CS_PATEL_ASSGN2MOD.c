#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char* str1, char* str2){
    int i=0;
    while(str1[i]!='\0' || str2[i]!='\0'){
        if(str1[i]>str2[i]) return 1;
        else if(str1[i]<str2[i]) return -1; 
        i++;
    }
    if(str1[i]=='\0' && str2[i]=='\0') return 0;
    else if(str1[i]=='\0') return -1;
    else return 1;
}

void Insertionsort(char** arr, int n){
    for(int i=1; i<n; i++){
        int j; 
        char tmp[1000]; strcpy(tmp,arr[i]);
        for(j=i-1; ((j>=0) && (compare(arr[j],tmp)>0)); j--){
            strcpy(arr[j+1],arr[j]);
        }
        strcpy(arr[j+1],tmp);
    }
}

int sumASCII(char* str){
    int len = strlen(str); int sum=0;
    for(int i=0; i<len; i++) sum+=str[i];
    return sum;
}

int main(){
    int n; scanf("%d",&n);
    char** arr = (char**)malloc(n*sizeof(char*));
    for(int i=0; i<n; i++){
        char* tmp = (char*)malloc(1000*sizeof(char));
        scanf("%s",tmp);
        arr[i]=tmp;
    }

    Insertionsort(arr,n);

    //Printing passcodes of computers in lexicographic order
    for(int i=0; i<n; i++) printf("%s ",arr[i]);
    printf("\n");

    //Easy to decrypt
    int flag=0;
    for(int i=0; i<n; i++){
        if(sumASCII(arr[i])%n == 0){
            flag=1;
            printf("%d ",i);
        }
    }
    if(flag==0) printf("-1");

    //Freeing memory
    for(int i=0; i<n; i++) free(arr[i]);
    free(arr);

}