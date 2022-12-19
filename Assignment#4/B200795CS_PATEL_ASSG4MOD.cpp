#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int parent(int i){
    return (i-1)/2;
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
void maxHeapify(int A[], int n, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < n and A[l] > A[i])
        largest = l;
    if(r < n and A[r] > A[largest])
        largest = r;
    if(largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}
int ExtractMax(int A[], int &n)
{
    int res = A[0];
    A[0] = A[n-1];
    n--;
    maxHeapify(A, n, 0);
    return res;
}
void IncreaseKey(int A[], int n, int i, int key)
{
    A[i] = key;
    while(i > 0 and A[parent(i)] < A[i])
    {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}
void insert(int A[], int &n, int key)
{
    A[n] = INT_MIN;
    n++;
    IncreaseKey(A, n, n-1, key);
}
int main()
{
	int n1, a, n = 0, m;
    cin>>n1>>m;
    int A[n1];
    for (int i = 0; i < n1; ++i)
    {
        cin>>a;
        insert(A, n, a);
    }
    int res = 0, top;
    while(m--)
    {
        for (int i = 0; i < n; ++i)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        top = ExtractMax(A, n);
        res += top;
        insert(A, n, top/2);
    }
    cout<<res;
    
	return 0;
}






// #include <stdio.h>
// #include <stdlib.h>

// void swap(int*a, int*b){
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// void printer(int* arr, int n){
//     for(int i=0;i<n; i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }

// void max_heapify(int* arr, int n, int i){			
// 	int l = 2*i+1;
// 	int r = 2*i+2;
// 	int large = i;
	
// 	if(l<n && arr[l]>arr[large]) large=l;
// 	if(r<n && arr[r]>arr[large]) large=r;
// 	if(large!=i){
// 		swap(&arr[large],&arr[i]);
// 		max_heapify(arr,n,large);
// 	}
// }	

// void heap_insert(int* ci, int* arr, int k){
//     int len = *ci;
//     arr[len]=k;
//     *ci=*ci+1;

//     int i = (len-1)/2;
//     while(i>=0 && arr[len]>arr[i]){
//         swap(&arr[i], &arr[len]);
//         len=i;
//         i=(len-1)/2;
//     }
// }

// int extract_max_choco(int* arr, int* n){
//     int cho = arr[0];
//     swap(&arr[0], &arr[*n-1]);
//     *n=*n-1;
//     max_heapify(arr,n,0);
//     return cho;
// }

// int main(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     int n,m;
//     scanf("%d %d",&n, &m);
//     int* arr = (int*)malloc(n*sizeof(int));

//     int ci = 0;
//     int maxchoco = 0;
//     for(int i=0; i<n; i++){
//         int k;
//         scanf("%d",&k);
//         heap_insert(&ci, arr, k);
//     }

//     for(int i=0; i<m; i++){
//         maxchoco += extract_max_choco(arr,&n);
//     }
//     printf("%d",maxchoco);
//     free(arr);
// }