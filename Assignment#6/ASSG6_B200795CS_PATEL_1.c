#include <stdio.h>
#include <stdlib.h>

struct node{
    int val; 
    struct node* next;
};

struct node* createNode(int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val=val;
    newNode->next=NULL;
    return newNode;
}

void push(struct node** top, struct node* now){
    now->next = *top;
    *top = now;
}

void pop(struct node** top){
    if(*top == NULL){
        printf("-1\n");
        return;
    }

    else{
        printf("%d\n", (*top)->val);
        struct node* del = *top;
        *top = (*top)->next;
        free(del);
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

int main(){
    struct node* top = NULL;

    while(1){
        char c; scanf(" %c",&c);
        if(c=='i'){
            int i; scanf("%d",&i);
            struct node* now = createNode(i);
            push(&top, now);
        }

        else if(c=='d') pop(&top);
    
        else if(c=='e') isEmpty(top);     

        else{
            freeing(top);
            return 0;
        }
    }
}