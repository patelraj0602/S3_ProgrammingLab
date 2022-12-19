//There is a bug in this code..
#include <stdio.h>
#include <stdlib.h>

struct node{
    char val;
    struct node* next;
};

struct node* createNode(char ch){
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->val = ch;
    current->next = NULL;
    return current;
}

void insertFront(struct node** head, struct node* cur){
    cur->next=*head;
    *head=cur;
}

void insertTail(struct node* head, struct node* cur){
    struct node* tmp = head;
    while(tmp->next!=NULL) tmp=tmp->next;

    tmp->next=cur;
}

struct node* listSearch(struct node* head, char k){
    struct node* tmp = head;
    while(tmp!=NULL){
        if(tmp->val==k) return tmp;
        tmp=tmp->next;
    }
    return NULL;
}

void listinsertAfter(struct node* head, struct node* cur, struct node* pre){
    cur->next = pre->next;
    pre->next = cur;
}

void listinsertBefore(struct node** head, struct node* cur, struct node* after){
    if(*head==after){
        cur->next=after;
        *head=cur;
    }
    else{
        struct node* tmp = *head;
        while(tmp->next!=after) tmp=tmp->next;
        cur->next = after;
        tmp->next = cur;
    }
}

void listDelete(struct node** head, struct node* del){
    
    if(*head==del){
        if((*head)->next==NULL) printf("-2\n");
        else printf("%c\n",(*head)->next->val);
        *head=(*head)->next;
        free(del);
    }
    else{
        struct node* tmp = *head;
        while(tmp->next!=del) tmp=tmp->next;

        tmp->next=del->next;
        free(del);
        if(tmp->next == NULL) printf("-2\n");
        else printf("%c\n",tmp->next->val);
    }
    
}

void listdeleteFirst(struct node** head){
    printf("%c\n",(*head)->val);
    struct node* del = *head;
    *head=(*head)->next;
    free(del);
}

void listdeleteLast(struct node** head){
    struct node* tmp = *head;
    if(tmp->next==NULL){
        printf("%c\n",(*head)->val);
        *head=(*head)->next;
        free(tmp);
    }
    else{
        while(tmp->next->next!=NULL) tmp=tmp->next;
        printf("%c\n",tmp->next->val);
        struct node* del = tmp->next;
        tmp->next = NULL;
        free(del);
    }
}

void printList(struct node* head){
    if(head==NULL) printf("NULL");
    else{
        struct node* tmp = head;
        while(tmp!=NULL) {
            printf("%c ",tmp->val);
            tmp=tmp->next;
        }
        printf("\n");
    }
}

void clear(struct node* head){
    while(head!=NULL){
        struct node* del = head;
        head=head->next;
        free(del);
    }
}

int main(){
    struct node* head = NULL;
    while(1){
        char c; scanf(" %c",&c);
        //printf("%c this is value of C\n ",c);
        if(c=='f'){
            char ch; scanf(" %c",&ch);
            struct node* cur = createNode(ch);
            insertFront(&head,cur);
        }

        else if(c=='t'){
            char ch; scanf(" %c",&ch);
            struct node* cur = createNode(ch);
            insertTail(head,cur);
        }

        else if(c=='a'){
            char n,o; scanf(" %c %c",&n, &o);
            struct node* cur = createNode(n);
            struct node* pre = listSearch(head,o);
            listinsertAfter(head,cur,pre);
        }

        else if(c=='b'){
            char n,o; scanf(" %c %c",&n, &o);
            struct node* cur = createNode(n);
            struct node* after = listSearch(head,o);
            listinsertBefore(&head,cur,after);
        }

        else if(c=='d'){
            char ch; scanf(" %c",&ch);
            struct node* del = listSearch(head,ch);
            if(del==NULL) printf("-1\n");
            else listDelete(&head,del);
        }

        else if(c=='i') {
            if(head==NULL) printf("-1\n");
            else listdeleteFirst(&head);
        }

        else if(c=='l')  {
            if(head==NULL) printf("-1\n");
            else listdeleteLast(&head);
        }

        else if(c=='p') printList(head);

        else{
            clear(head);
            return 0;
        }
    }
}