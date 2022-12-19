#include <stdio.h>
#include <stdlib.h>

void read_customers(int n,char *arr){
    for(int i=0; i<n; i++) scanf("%c",&arr[i]);
}

void print_customers(char* arr, int n){
    for(int i=0; i<n; i++) printf("%c ",arr[i]);
    printf("\n");
}

void arrange_customers(char* arr, int n){
    int* tmp = (int*)malloc(n*sizeof(int));
    int ini = 0;
    for(int i=8; i>=0; i++){
        for(int j=0; j<n; j++){
            if((arr[j]-'A')/3 == i){
                tmp[ini]==arr[j];
                ini++;
            }
        }
    }
    for(int i=0; i<n; i++){
        arr[i]=tmp[i];
    }
    free(tmp);
}

void list_customers(char *arr,int a,int n){
    a--;
    int flag = 0;
    for(int i=0; i<n; i++){
        if((arr[i]-'A')/3 == a){
            printf("%d ",i+1);
            flag=1;
        }
    }
    if(flag==0) printf("-1");
    return;
}

int main(){
    int n; 
    char* arr;
    char ch;
    while(1){
        scanf(" %c",&ch);
        if(ch=='r'){
            scanf("%d",&n);
            arr = (char*)malloc(n*sizeof(char));
            read_customers(n,arr);
        }

        else if(ch=='p') print_customers(arr,n);

        else if(ch=='a') arrange_customers(arr,n);

        else if(ch=='l'){
            int a; scanf("%d",a);
            list_customers(arr,a,n);
        }

        else{
            free(arr);
            return 0;
        }
    }
    return 0;
}