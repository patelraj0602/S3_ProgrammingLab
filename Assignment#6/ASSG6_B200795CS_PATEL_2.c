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

int isEmpty(struct node* head){
    if(head==NULL) return -1;
    else return 1;
}

void enqueue(struct node** head, struct node** tail, struct node* now){
    if (isEmpty(*head) == -1) *head = now;
    else (*tail)->next = now;
    *tail = now;
}

void dequeue(struct node** head, struct node** tail){
    if(*head == NULL) printf("-1\n");
    else{
        struct node* tmp = *head;
        printf("%d\n", tmp->val);
        if(*head == *tail) *tail = NULL;

        *head = (*head)->next;
        free(tmp);
    }
}

void freeing(struct node* head){
    while(head!=NULL){
        struct node* del = head;
        head=head->next;
        free(del);
    }
}

int main(){  
    struct node* head = NULL;
    struct node* tail = NULL;

    while(1){
        char c; scanf(" %c",&c);

        if(c=='i'){
            int v; scanf("%d",&v);
            struct node* now = createNode(v);
            enqueue(&head,&tail,now);
        }

        else if(c=='d') dequeue(&head,&tail);

        else if(c=='e') printf("%d\n",isEmpty(head));

        else{
            freeing(head);
            return 0;
        }
    }
}
