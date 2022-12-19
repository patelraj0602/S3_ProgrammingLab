#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printer(int* arr, int n){
    for(int i=0;i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void max_heapify(int* arr, int n, int i){			
	int l = 2*i+1;
	int r = 2*i+2;
	int large = i;
	
	if(l<n && arr[l]>arr[large]) large=l;
	if(r<n && arr[r]>arr[large]) large=r;
	if(large!=i){
		swap(&arr[large],&arr[i]);
		max_heapify(arr,n,large);
	}
}	

void heap_insert(int* ci, int* arr, int k){
    int len = *ci;
    arr[len]=k;
    *ci=*ci+1;

    int i = (len-1)/2;
    while(i>=0 && arr[len]>arr[i]){
        swap(&arr[i], &arr[len]);
        len=i;
        i=(len-1)/2;
    }
}

int extract_max_choco(int* arr, int n){
    int cho = arr[0];
    printer(arr,n);
    arr[0]=arr[0]/2;

    //=>I added this below line of code. And in the question it was no where mentioned that we should do this.
    //=>What I did was I reduced to half and applied map heapify on first element itself. So order was jumbled.
    swap(&arr[0],&arr[n-1]);

    max_heapify(arr,n,0);
    return cho;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    scanf("%d %d",&n, &m);
    int* arr = (int*)malloc(n*sizeof(int));

    int ci = 0;
    int maxchoco = 0;
    for(int i=0; i<n; i++){
        int k;
        scanf("%d",&k);
        heap_insert(&ci, arr, k);
    }

    for(int i=0; i<m; i++){
        maxchoco += extract_max_choco(arr,n);
    }
    printf("%d",maxchoco);
    free(arr);
}