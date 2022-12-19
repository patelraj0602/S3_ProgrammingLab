#include <stdio.h>
#include <stdlib.h>

struct member{
    char id[10];
    int no;
    struct member* next;
};

void read_students(struct member** head){
    struct member* now = (struct member*)malloc(sizeof(struct member));
    scanf(" %s %d",now->id, &now->no);
    now->next=NULL;
    printf("%s %d\n", now->id, now->no);
    
    printf("first\n");
    if((*head)==NULL){
        *head=now;
        return;
    }

    printf("second\n");
    if(now->no <= (*head)->no){
        now->next=(*head);
        *head=now;
        return;
    }

    else{
        printf("third\n");
        struct member* tmp = *head;
        while(tmp->next!=NULL){
            if((now->no <= tmp->next->no) && (now->no >= tmp->no)){
                now->next=tmp->next;
                tmp->next=now;
                return;
            }
        }
    }
}

void printstudents(struct member* head){
    if(head==NULL){
        printf("NULL");
        return;
    }
    struct member* tmp = head;
    while(tmp!=NULL){
        printf("%s ",tmp->id);
        tmp=tmp->next;
    }
    printf("\n");
}

void countstudents(struct member* head, int k){
    struct member* tmp = head;
    int ans=0;
    while(tmp!=NULL){
        if(tmp->no == k) ans++;
        tmp=tmp->next;
    }
    printf("%d\n",ans);
}

void currentstatus(struct member* head, int k){
    struct member* tmp = head;
    int low=0; int high=0; int flag=0;
    while(tmp!=NULL){
        if(tmp->no==k) flag=1;
        if(tmp->no <= k) low++;
        else high++;
        tmp=tmp->next;
    }
    if(flag==0) printf("-1\n");
    else printf("%d %d\n",low, high);
}

void receivecertificate(struct member* head){
    struct member* tmp = head;
    while(tmp->next!=NULL){
        if(tmp->no != tmp->next->no){
            printf("%s ",tmp->id);
        }
        tmp=tmp->next;
    }
    printf("%s\n",tmp->id);
} 

int main(){

    struct member* head = NULL;
    while(1){
        char ch; scanf(" %c",&ch);
        if(ch=='r') read_students(&head);
        else if(ch=='p') printstudents(head);
        else if(ch=='c') {
            int k; scanf("%d",&k);
            countstudents(head,k);
        }
        else if(ch=='s') {
            int k; scanf("%d",&k);
            currentstatus(head,k);
        }
        else if(ch=='f') receivecertificate(head);
        else {
            while(head!=NULL){
                struct member* d = head;
                head=head->next;
                free(d);
            }
            return 0;
        }   
    }   
}