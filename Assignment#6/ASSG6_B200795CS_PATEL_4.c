#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int top;
    struct treeNode **arr;
};

struct treeNode{
    char val;
    struct treeNode* left;
    struct treeNode* right;
};

int isEmpty(struct stack* s){
    if(s->top >= 0) return 1;
    else return -1; 
}

void push(struct stack* s, struct treeNode* ch){
    s->top++;
    s->arr[s->top] = ch;
}

struct treeNode* pop(struct stack* s){
    if(isEmpty(s)==-1) return NULL;
    struct treeNode* c = s->arr[s->top];
    s->top--;
    return c;
}

struct treeNode* constructTree(char* postfix){

    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->arr = (struct treeNode**)malloc(500*sizeof(struct treeNode*));


    int len = strlen(postfix);
    for(int i=0; i<len; i++){
        if((postfix[i]>96)&&(postfix[i]<123)){
            struct treeNode* nd = (struct treeNode*)malloc(sizeof(struct treeNode));
            nd->val=postfix[i];
            nd->left=NULL; nd->right=NULL;
            push(s,nd);
        }
        else{
            struct treeNode* nd = (struct treeNode*)malloc(sizeof(struct treeNode));
            nd->val = postfix[i];
            nd->right=pop(s);
            nd->left=pop(s);
            push(s,nd);
        }
    }
    struct treeNode* root = pop(s);
    free(s->arr);
    free(s);
    return root;
}

void inorder(struct treeNode* root){
    if(root == NULL) return;

    inorder(root->left);
    printf("%c",root->val);
    inorder(root->right);
}

void postorder(struct treeNode* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%c",root->val);
}

void preorder(struct treeNode* root){
    if(root == NULL) return;

    printf("%c",root->val);
    preorder(root->left);
    preorder(root->right);
}

void deleteMemory(struct treeNode* root){
    if(root==NULL) return;
    deleteMemory(root->left);
    deleteMemory(root->right);
    delete root;
}



int main(){
    struct treeNode* root = NULL;

    while(1){
        char ch; scanf(" %c",&ch);
        if(ch=='e'){
            char postfix[1000];
            scanf(" %s",postfix);
            root = constructTree(postfix);
        }
        else if(ch=='i'){
            inorder(root);
            printf("\n");
        }
        else if(ch=='p'){
            preorder(root);
            printf("\n");
        }
        else if(ch=='s'){
            postorder(root);
            printf("\n");
        }
        else{
            deleteMemory(root);
            return 0;
        }
    }
}
