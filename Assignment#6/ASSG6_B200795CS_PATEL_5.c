#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int top;
    int *arr;
};

int isEmpty(struct stack* s){
    if(s->top >= 0) return 1;
    else return -1; 
}

void push(struct stack* s, int ch){
    s->top++;
    s->arr[s->top]=ch;
}

int pop(struct stack* s){
    if(isEmpty(s)==-1) return -1;
    int c = s->arr[s->top];
    s->top--;
    return c;
}

int peek(struct stack* s){
    if(isEmpty(s)==-1) return -1;
    return s->arr[s->top];
}

int main(){

    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->arr = (int*)malloc(1000*sizeof(int));

    char postfix[1000];
    fgets (postfix, 1000, stdin);
    int len = strlen(postfix);

    int i=0;
    while(i<len){
        if(postfix[i]=='+'){
            int op2 = pop(s);
            int op1 = pop(s);
            push(s,(op1+op2));
            i=i+2;
        }    
        else if(postfix[i]=='-'){
            int op2 = pop(s);
            int op1 = pop(s);
            push(s,(op1-op2));
            i=i+2;
        } 
        else if(postfix[i]=='*'){
            int op2 = pop(s);
            int op1 = pop(s);
            push(s,(op1*op2));
            i=i+2;
        } 
        else if(postfix[i]=='/'){
            int op2 = pop(s);
            int op1 = pop(s);
            push(s,(op1/op2));
            i=i+2;
        } 
        else{
            char tmp[5]; int p=0;
            while((i<len)&&(postfix[i] != ' ')) tmp[p++]=postfix[i++];
            i++; tmp[p]='\0';

            int val = atoi(tmp);
            push(s,val);
        }
    }

    printf("%d", pop(s));

    free(s->arr);
    free(s);
}