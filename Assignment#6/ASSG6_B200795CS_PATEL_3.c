#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int top;
    char *arr;
};

// void print(struct stack* s){
//     for(int i=0; i<=s->top; i++){
//         printf("%c",s->arr[i]);
//     }
//     printf("\n");
// }


int isEmpty(struct stack* s){
    if(s->top>=0) return 1;
    else return -1; 
}

void push(struct stack* s, char ch){
    s->top++;
    s->arr[s->top]=ch;
}

char pop(struct stack* s){
    if(isEmpty(s)==-1) return -1;
    char c = s->arr[s->top];
    s->top--;
    return c;
}

char peek(struct stack* s){
    if(isEmpty(s)==-1) return -1;
    return s->arr[s->top];
}

int precedence(char now, char top){
    if(top=='(') return 0;

    if((now=='*')||(now=='/')){
        if((top=='+')||(top=='-')) return 0;
        else return 1;
    }
    return 1;
}

int main(){

    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->arr = (char*)malloc(500*sizeof(char));

    char infix[500]; 
    char postfix[500];
    int pos=0;
    scanf("%s",infix);

    int len = strlen(infix);

    for(int i=0; i<len; i++){
        if((infix[i]<123) && (infix[i]>96)) postfix[pos++]=infix[i];
        else if((infix[i]=='(')||(peek(s)=='(')) push(s,infix[i]);
        else if(infix[i]==')'){
            while(peek(s)!='(') postfix[pos++]=pop(s);
            pop(s);
        }
        else{
            char now = infix[i];
            while((isEmpty(s)==1)&&(precedence(now, peek(s)))) postfix[pos++] = pop(s);
            push(s,now);
        }
    }

    while(isEmpty(s)!=-1) postfix[pos++] = pop(s);

    for(int i=0; i<pos; i++) printf("%c",postfix[i]);

    free(s->arr);
    free(s);
}
