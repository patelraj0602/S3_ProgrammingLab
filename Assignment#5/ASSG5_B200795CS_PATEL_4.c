#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct queue{
    int head,tail;
    char **arr;
};

int isFull(struct queue* q, int n){
    if((q->tail+1)%n == q->head) return -1;
    return 1;
}

int isEmpty(struct queue* q, int n){
    if(q->tail == q->head) return -1;
    return 1;
}

void enqueue(struct queue* q, char* tmp, int n){
    if(isFull(q,n)==-1) printf("-1\n");
    else{
        strcpy(q->arr[q->tail],tmp);
        q->tail = ((q->tail)+1)%n;
    }
}

void dequeue(struct queue* q, int n){
    if(isEmpty(q,n)==-1) printf("-1\n");
    else{
        printf("%s\n", q->arr[q->head]);
        q->head = (q->head+1)%n;
    }
}

int main(){
    int n; 
    scanf("%d",&n);
    struct queue q;
    q.head = 0;
    q.tail = 0;
    q.arr = (char**)malloc(n*sizeof(char*));

    for(int i=0; i<n; i++){
        char* ar = (char*)malloc(20*sizeof(char));
        q.arr[i]=ar;
    }

    while(1){
        char c;  scanf(" %c",&c);

        if(c=='i'){
            char tmp[20]; scanf(" %s",tmp);
            // cout << "doing enqueue : ";
            enqueue(&q,tmp,n);
        }

        else if(c=='d') {
            // cout << "dequeing :";
            dequeue(&q,n);
        }

        else if(c=='f') {
            // cout << "isFull? : ";
            printf("%d\n",isFull(&q,n));
        }

        else if(c=='e') {
            // cout << "isEmpty? : ";
            printf("%d\n",isEmpty(&q,n));
        }

        else{
            //Freeing memeory;
            for(int i=0; i<n; i++) free(q.arr[i]);
            free(q.arr);
            return 0;
        }
    }
}

