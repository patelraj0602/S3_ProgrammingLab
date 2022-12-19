#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    char *arr;
};

int isFull(struct stack*s, int n){
    if(s->top<n-1) return 1;
    else return -1;
}

int isEmpty(struct stack* s){
    if(s->top>=0) return 1;
    else return -1; 
}

void push(struct stack* s, char ch, int n){
    if(isFull(s,n)==-1) printf("-1\n");
    else {
        s->top++;
        s->arr[s->top]=ch;
    }
}

// void print(struct stack* s){
//     for(int i=s->top; i>=0; i--){
//         printf("%c ",s->arr[i]);
//     }
//     printf("\n");
// }

void pop(struct stack* s){
    if(isEmpty(s)==-1) printf("-1\n");
    else {
        printf("%c\n",s->arr[s->top]);
        s->top--;
    }   
}

void peek(struct stack* s){
    if(isEmpty(s)==-1) printf("-1\n");
    else printf("%c\n",s->arr[s->top]);
}

int main(){

    int n; scanf("%d",&n);
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->arr = (char*)malloc(n*sizeof(char));

    while(1){
        char c; scanf(" %c",&c);
        if(c=='i'){
            char ch; scanf(" %c",&ch);
            //The question does not allow to pass n but I am taking it becasue it is impossible to determine
            //whether the stack is full or not without the value of n..
            push(s,ch,n);
        }

        else if(c=='d') pop(s);

        else if(c=='p') peek(s);

        else{
            free(s->arr);
            free(s);
            return 0;
        }
    }
}