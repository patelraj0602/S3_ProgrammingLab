#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int max_heapify(int*arr, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i; 
    int cmp = 0;

    if(l<n){
        cmp++;
        if(arr[l]>arr[largest]) largest = l;
    }

    if(r<n){
        cmp++;
        if(arr[r]>arr[largest]) largest = r;
    }

    if(largest != i){
        swap(&arr[largest],&arr[i]);
        cmp+=max_heapify(arr,n,largest);
    }
    return cmp;
}



int Build_max_heap(int*arr, int n){
    int cmp = 0;
    for(int i=n/2-1; i>=0; i--){
        cmp+=max_heapify(arr,n,i);
    }
    return cmp;
}

int heapsort(int* arr, int n){
    int cmp = 0;
    for(int i=n-1; i>=0; i--){
        swap(&arr[0],&arr[i]);
        cmp+=max_heapify(arr,i,0);
    }
    return cmp;
}

int main(){

    int n; scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));

    for(int i=0; i<n; i++) scanf("%d",&arr[i]);

    int comparision = 0;
    comparision += Build_max_heap(arr,n) + heapsort(arr,n);
    
    //Printing
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
    printf("\n");
    printf("%d",comparision);

    free(arr);
}