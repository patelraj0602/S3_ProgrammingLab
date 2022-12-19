#include <stdio.h>
#include <stdlib.h>

void read_customers(char* arr, int n){
    for(int i=0; i<n; i++) scanf("%c",&arr[i]);
    return;
}

void print_customers(char* arr, int n){
    for(int i=0; i<n; i++) printf("%c ",arr[i]);
    printf("\n");
}

int divide_customers(char* arr, int n , int ctrnum){
//Remaining to complete
}

void arrange_customers(char* arr, int n, int pos){
    //I am considering the pos when array starts from 0 means for eg 0,1,2,3,4,5,6,..
    char* grp1 = (char*)malloc((pos+1)*(sizeof(char)));
    char* grp2 = (char*)malloc((n-pos-1)*(sizeof(char)));
    for(int i=0; i<=pos; i++) grp1[i]=arr[i];
    for(int i=pos+1; i<n; i++) grp2[i-pos-1]=arr[i];

    int i=0; int j=pos+1; int tmp = 0;
    while((i<=pos) && (j<n)){
        if(tmp%2==0) {arr[tmp]=grp2[j]; j++;}
        else {arr[tmp]=grp1[i]; i++;}
        tmp++;
    }
    if(i<=pos){
        while(i<=pos) {arr[tmp]=grp1[i]; tmp++; i++;}
    }
    else {
        while(j<n){
            arr[tmp]=grp2[j];
            tmp++;
            j++;
        }
    }
    free(grp1);
    free(grp2);
}

void list_customers(char* arr, int n, char c){
    int flag = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==c) {printf("%d ",i+1); flag=1;}
    }
    if(flag==0) printf("-1");
    printf("\n");
}




int main(){
    int n; 
    char *arr;
    char ch;
    int pos;
    while(1){
        scanf("%c",&ch);
        if(ch=='r'){
            scanf("%d",&n);
            arr = (char*)malloc(n*sizeof(char));
            read_customers(arr,n);
        }
        else if(ch=='p') print_customers(arr,n);

        else if(ch=='d'){
            int ctrnum; scanf("%d",&ctrnum);
            pos = divide_customers(arr,n,ctrnum);
        }

        else if(ch=='a'){
            arrange_customers(arr,n,pos);
        }

        else if(ch=='l') {
            char chara;
            scanf("%c", &chara);
            list_customers(arr,n,chara);
        }
        else 
            return 0;

    }

}