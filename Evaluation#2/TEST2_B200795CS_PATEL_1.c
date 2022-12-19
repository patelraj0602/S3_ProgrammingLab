#include <stdio.h>
#include <stdlib.h>

int mes[10000];
int c=0;

struct sms{
    char alpha;
    int num;
};

void swap(struct sms* p, struct sms* q){
    char tmp;
    tmp=q->alpha;
    q->alpha=p->alpha;
    p->alpha=tmp;

    int t;
    t=q->num;
    q->num=p->num;
    p->num=t;
}


void minHeapify(struct sms* a, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int small = i;

    if(l<n && (a[l].num<a[small].num)) small=l;
    if(l<n && (a[r].num<a[small].num)) small=r;

    if(small!=i){
        swap(&a[i],&a[small]);
        minHeapify(a,n,small);
    }
}

char* heapsort(struct sms* a, int n){
    char* arr = (char*)malloc(n*sizeof(char));
    for(int i=n-1; i>=0; i--){
        arr[n-1-i]=a[0].alpha;
        swap(&a[0],&a[i]);
        minHeapify(a,i,0);
    }
    return arr;
}

void insert(struct sms* a, struct sms ss, int* l){
    int len = *l;
    a[len].alpha=ss.alpha;
    a[len].num=ss.num;
    while(len>0 && (a[(len-1)/2].num>a[len].num)){
        swap(&a[(len-1)/2], &a[len]);
        len=(len-1)/2;
    }
    *l++;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    struct sms* a = (struct sms*)malloc(1000*sizeof(sms));
    int len=0;
    
    while(1){
        char ch; scanf(" %c",&ch);
        if(ch=='r'){
            struct sms ss; 
            scanf(" %c %d",&ss.alpha, &ss.num);
            insert(a,ss,&len);
            char* arr = heapsort(a,len+1);
            for(int i=0; i<=len; i++){
                printf("%c ",arr[i]);
            }
            printf("\n");
        }

        else if(ch=='d'){
            char* arr = heapsort(a,len+1);
            for(int i=0; i<=len; i++) {
                printf("%c",arr[i]);
                mes[c]=arr[i];
                c++;
            }
            printf("\n");
            mes[c] = ' '; c++;
            len=0;
        }


        else if(ch=='p'){
            for(int i=0; i<c; i++) printf("%c",mes[i]);   
            printf("\n"); 
        }

        else{
            free(a);
            return 0;
        }
    }

}