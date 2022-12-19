#include <stdio.h>
#include <stdlib.h>

struct node{
    int lock_no;
    int before;
    int after; 
    struct node* next;
};

void push(struct node** top, struct node* now){
    now->next = *top;
    *top = now;
}

struct node* pop(struct node** top){
    if(*top == NULL) return NULL;

    else{
        struct node* re = *top;
        *top = (*top)->next;
        return re;
    }
}

void isEmpty(struct node* top){
    if(top==NULL) printf("-1\n");
    else printf("1\n");
}

void freeing(struct node* head){
    while(head!=NULL){
        struct node* del = head;
        head=head->next;
        free(del);
    }
}

void assign_locker(int* arr, struct node** top){
    int ac,ln;
    scanf("%d %d",&ac,&ln);

    // printf("%d %d\n",ac,ln);

    struct node* now = (struct node*) malloc(sizeof(struct node));
    now->lock_no = ln;
    now->before = arr[ln-1];
    now->after = ac;
    now->next=NULL;
    push(top,now);

    arr[ln-1]=ac;
}

void free_locker(int* arr, struct node** top){
    int f; scanf("%d",&f);
	
	struct node* now = (struct node*) malloc(sizeof(struct node));
    now->lock_no = f;
    now->before = arr[f-1];
    now->after = -1;
    now->next=NULL;

    push(top,now);
	arr[f-1]=-1;
}

void undo(int* arr, struct node** top){
    struct node* now = pop(top);

    int lc = now->lock_no;
    arr[lc-1]=now->before;
    free(now);
}

void print_detail(int* arr, int n){
    int flag=0;
    for(int i=0; i<n; i++){
        if(arr[i]!=-1){
            printf("%d ",arr[i]);
            flag=1;
        }
    }
    if(flag==0) printf("-1");
    printf("\n");
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d",&n);

    struct node* top = NULL;

    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) arr[i]=-1;

    while(1){
        char c; scanf(" %c",&c);
        if(c=='i') assign_locker(arr,&top);
        else if(c=='d') free_locker(arr,&top);
        else if(c=='p') print_detail(arr,n);
        else if(c=='u') undo(arr,&top);
        else{
            free(arr);
            freeing(top);
            return 0;
        }
    }
}