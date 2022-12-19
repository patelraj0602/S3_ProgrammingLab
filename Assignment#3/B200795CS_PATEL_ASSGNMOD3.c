#include <stdio.h>
#include <stdlib.h>

int total_g = 0;
int won[10000];
int curr=0;
int special_g;

void printing(int *arr, int low, int high, int id){

    printf("%d ",id);
    for(int i=low; i<=high; i++){
        if(arr[i]==special_g){
            won[curr]=id;
            curr++;
            total_g++;
        }
        total_g++;
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void iterating(int* arr, int low, int high, int id){
    if(low==high) printing(arr,low,high,id);
    else if(low<high){
        printing(arr,low,high,id);
        int mid = (low+high)/2;
        iterating(arr,low,mid,2*id);
        iterating(arr,mid+1,high,(2*id)+1);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //declaring and initiallizing 
    int n; scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    scanf("%d",&special_g);


    //Recursively iterating
    int id = 1;
    iterating(arr,0,n-1,id);

    //Printing the ids of the people who won special gifts..
    for(int i=0; i<curr; i++) printf("%d ", won[i]);
    printf("\n");

    //Total gifts 
    printf("%d",total_g);

    free(arr);
}