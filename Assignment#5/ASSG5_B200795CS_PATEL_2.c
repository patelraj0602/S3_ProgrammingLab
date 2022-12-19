//There is a bug in this code....
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
    struct node* pre;
};

struct node* createNode(int data){
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->val = data;
    current->next = NULL;
    current->pre = NULL;
    return current;
}

void insertFront(struct node** head, struct node* cur){
    if(*head==NULL){
        *head = cur;
    }
    else{
        cur->next = *head;
        (*head)->pre = cur;
        *head = cur;
    }
}

void clear(struct node* head){
    while(head!=NULL){
        struct node* del = head;
        head=head->next;
        free(del);
    }
}

void printing(struct node* head){
    struct node* tmp = head;
    while(tmp!=NULL){
        printf("%d ",tmp->val);
        tmp=tmp->next;
    }
}

void insertTail(struct node** head,struct node* cur){
    
    if((*head)==NULL) *head=cur;
    else{
        struct node* tmp = *head;
        while(tmp->next!=NULL) tmp=tmp->next;
        tmp->next=cur;
        cur->pre=tmp;    
    }
}

struct node* listSearch(struct node* head, int k){
    struct node* tmp = head;
    while(tmp!=NULL){
        if(tmp->val==k) return tmp;
        tmp=tmp->next;
    }
    return NULL;
}

void insertAfter(struct node* head, struct node* nd, struct node* od){
    nd->next=od->next;
    if(od->next!=NULL) od->next->pre=nd;
    od->next=nd;
    nd->pre=od;
}

void insertBefore(struct node** head, int n, int o){
    struct node* nd = createNode(n);
    if((*head)->val==o) insertFront(head,nd);
    else{
        struct node* tmp = *head;
        while(tmp->next->val!=o) tmp=tmp->next;
        insertAfter(*head, nd, tmp);
    }
}

void listDelete(struct node** head, struct node* nd){
    if(nd->next==NULL){
        nd->pre->next=NULL;
        printf("NULL\n");
        free(nd);
    }
    else if(nd->pre==NULL){
        printf("%d\n",nd->next->val);
        *head = nd->next;
        (*head)->pre=NULL;
        free(nd);
    }
    else{
        struct node* p = nd->pre; struct node* n = nd->next;
        printf("%d\n",n->val);
        p->next=n;
        n->pre=p;
        free(nd);
    }
}

void deleteInitial(struct node** head){
    if(*head==NULL) printf("Not Found\n");
    else{
        struct node* tmp = *head;
        printf("%d\n",(*head)->val);
        *head=(*head)->next;
        (*head)->pre = NULL;
        free(tmp);
    }
}

void deleteLast(struct node** head){
    if(*head==NULL) printf("Not Found\n");
    else{
        struct node* tmp = *head;
        while(tmp->next!=NULL) tmp=tmp->next;
        printf("%d\n",tmp->val);
        if(*head==tmp) *head=NULL;
        else tmp->pre->next=NULL;
        free(tmp);
    }
}

void printReverse(struct node* tmp){
    while(tmp!=NULL){
        printf("%d ",tmp->val);
        tmp=tmp->pre;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    while(1){
        char c; scanf(" %c",&c);
        if(c=='f'){
            int n; scanf("%d",&n);
            struct node* cur = createNode(n);
            insertFront(&head,cur);
        }

        else if(c=='t'){
            int n; scanf("%d",&n);
            struct node* cur = createNode(n);
            insertTail(&head,cur);
        }

        else if(c=='a'){
            int n,o; scanf("%d %d",&n,&o);
            struct node* od = listSearch(head,o);
            struct node* nd = createNode(n);
            insertAfter(head,nd,od);
        }

        else if(c=='b'){
            int n,o; scanf("%d %d",&n,&o);
            insertBefore(&head,n,o);
        }

        else if(c=='d'){
            int n; scanf("%d",&n);
            struct node* nd = listSearch(head,n);
            if(nd==NULL) printf("Not Found\n");
            else listDelete(&head,nd);
        }

        else if(c=='i') deleteInitial(&head);
        
        else if(c=='l') deleteLast(&head);

        else if(c=='r') {
            int k; scanf("%d",&k);
            struct node* tmp = listSearch(head,k);
            if(tmp==NULL) printf("Not Found\n");
            else printReverse(tmp);
        }

        else{
            clear(head);
            return 0;
        } 
    }
}