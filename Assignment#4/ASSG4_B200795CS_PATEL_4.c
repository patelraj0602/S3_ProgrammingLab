#include <stdio.h>
#include <stdlib.h>


void insertPatient(int* numbers, int k, int* len){
    numbers[*len] = k;
    *len = *len+1;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
 
void min_heapify(int* num, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int small = i;

    if(l<n && num[l]<num[small]) small = l;
    if(r<n && num[r]<num[small]) small = r;
    if(small!=i){
        swap(&num[small],&num[i]);
        min_heapify(num, n, small);
    }
}

void Build_min_heap(int* numbers, int len){
    for(int i=len/2-1; i>=0; i--){
        min_heapify(numbers,len,i);
    }

}

void heapsort(int* numbers, int len){
    for(int i=len-1; i>=0; i--){
        swap(&numbers[0], &numbers[i]);
        min_heapify(numbers,i,0);
    }
}

void extractNextPatient(int* numbers, int* len){
    if(*len==0){
        printf("-1\n");
        return;
    }
    Build_min_heap(numbers, *len);
    printf("%d\n", numbers[0]);
    *len = *len-1;
    swap(&numbers[0],&numbers[*len]);
}

void getNextPatient(int* numbers, int len){
    if(len==0){
        printf("-1\n");
        return;
    }
    Build_min_heap(numbers, len);
    printf("%d\n", numbers[0]);
}

void changeTokenNumber(int* numbers, int old, int n, int len){
    for(int i=0; i<len; i++){
        if(numbers[i]==old) numbers[i]=n;
    }
}

void displayqueue(int* numbers, int len){
    Build_min_heap(numbers, len);
    heapsort(numbers, len);
    for(int i=len-1; i>=0; i--)  printf("%d ",numbers[i]);
    printf("\n");
}

int main(){
    int numbers[100];
    int len = 0;
    while(1){
        char ch;
        scanf(" %c",&ch);

        if(ch=='i'){
            int k; scanf("%d",&k);
            insertPatient(numbers,k,&len);
        } 
        else if(ch=='e') extractNextPatient(numbers,&len);
        else if(ch=='m') getNextPatient(numbers, len);
        else if(ch=='c') {
            int o,n; scanf("%d %d",&o, &n);
            changeTokenNumber(numbers,o,n,len);
        }
        else if(ch=='d') displayqueue(numbers, len);
        else break;
    }
}