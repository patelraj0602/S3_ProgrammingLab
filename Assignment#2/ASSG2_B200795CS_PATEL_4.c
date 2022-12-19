#include <stdio.h>
#include <stdlib.h>

//In c we cannot find the size of dynamically allocated array using sizeof(arr).
//Therefore I also had to pass the size of array along with the array..
void InsertionSortAs(int* even, int sz){
    for(int i=1; i<sz; i++){
        int j; int tmp = even[i];
        for(j=i-1; j>=0 && even[j]>tmp; j--) even[j+1]=even[j];
        even[j+1]=tmp;
    }
}

void InsertionSortDs(int* odd, int sz){
    for(int i=1; i<sz; i++){
        int j; int tmp = odd[i];
        for(j=i-1; j>=0 && odd[j]<tmp; j--) odd[j+1]=odd[j];
        odd[j+1]=tmp;
    }
}

void Print(int *arr,int sz){
    for(int i=0; i<sz; i++) printf("%d ",arr[i]);
}


int main(){
    int n; scanf("%d",&n);
    int sz = n%2 ? (n/2)+1 : n/2;
    int s = n-sz;
    int* even = (int*)malloc(sz*sizeof(int));
    int* odd = (int*)malloc(s*sizeof(int));

    for(int i=0; i<n; i++){
        if(i%2==0) scanf("%d",&even[i/2]);
        else scanf("%d",&odd[i/2]);
    }
    InsertionSortAs(even,sz);
    InsertionSortDs(odd,s);
    Print(even,sz);
    printf("\n");
    Print(odd,s);
    free(even); free(odd);
}