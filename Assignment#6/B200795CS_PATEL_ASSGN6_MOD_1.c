#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode{
    char val;
    struct treeNode* left;
    struct treeNode* right;
};


//Setup for character Stack...
struct stackc{
    int top;
    char *arr;
};

void print(struct stackc* s){
    for(int i=0; i<=s->top; i++){
        printf("%c",s->arr[i]);
    }
    printf("\n");
}


int isEmptyc(struct stackc* s){
    if(s->top>=0) return 1;
    else return -1; 
}

void pushc(struct stackc* s, char ch){
    s->top++;
    s->arr[s->top]=ch;
}

char popc(struct stackc* s){
    if(isEmptyc(s)==-1) return -1;
    char c = s->arr[s->top];
    s->top--;
    return c;
}

char peekc(struct stackc* s){
    if(isEmptyc(s)==-1) return -1;
    return s->arr[s->top];
}


//Setup for Treenode* stack..
struct stackt{
    int top;
    struct treeNode **arr;
};


int isEmptyt(struct stackt* s){
    if(s->top >= 0) return 1;
    else return -1; 
}

void pusht(struct stackt* s, struct treeNode* ch){
    s->top++;
    s->arr[s->top] = ch;
}

struct treeNode* popt(struct stackt* s){
    if(isEmptyt(s)==-1) return NULL;
    struct treeNode* c = s->arr[s->top];
    s->top--;
    return c;
}

void deleteMemory(struct treeNode* root){
    if(root==NULL) return;
    deleteMemory(root->left);
    deleteMemory(root->right);
    delete root;
}

int priority(char c){
    if((c=='+') || (c=='-')) return 1;
    else if((c=='/') || (c=='*')) return 2;
    else if(c==')') return 0;
    return 0;
}


struct treeNode* createAssignmentTree(char* str){
    //Creating instances of Stackc
    struct stackc* sc = (struct stackc*)malloc(sizeof(struct stackc));
    sc->top = -1;
    sc->arr = (char*)malloc(500*sizeof(char));

    //Creating instance of Stackt
    struct stackt* st = (struct stackt*)malloc(sizeof(struct stackt));
    st->top = -1;
    st->arr = (struct treeNode**)malloc(500*sizeof(struct treeNode*));


    int len = strlen(str);
    if(len==2) return NULL;

    str[1]='('; str[len-1]=')';
    for(int i=1; i<len; i++){
        // printf("The value is %c\n",str[i]);
        if(str[i]=='(') {
            pushc(sc,str[i]);
        }

        else if((str[i]>96)&&(str[i]<123)){
            struct treeNode* tmp = (struct treeNode*)malloc(sizeof(struct treeNode));
            tmp->val = str[i];
            tmp->left=NULL; tmp->right=NULL;
            pusht(st,tmp);
        }

        else if(priority(str[i])>0){
            while((isEmptyc(sc)==1) && (peekc(sc) != '(') && (priority(peekc(sc)) >= priority(str[i]))){
                struct treeNode* tmp = (struct treeNode*)malloc(sizeof(struct treeNode));
                tmp->val = popc(sc);
                tmp->right=popt(st); tmp->left=popt(st);
                pusht(st,tmp);
            }
            pushc(sc,str[i]);
        }
        else if(str[i] == ')'){
            while(isEmptyc(sc)==1 &&(peekc(sc) != '(')){
                struct treeNode* tmp = (struct treeNode*)malloc(sizeof(struct treeNode));
                tmp->val = popc(sc);
                tmp->right=popt(st); tmp->left=popt(st);
                pusht(st,tmp);
            }
            popc(sc);
        }

    }
    struct treeNode* now = popt(st);
    
    free(st->arr);
    free(st);

    free(sc->arr);
    free(sc);
    return now;
}

void postorder(struct treeNode* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%c",root->val);
}

int main(){

    char str[1000];
    scanf("%s",str);

    struct treeNode* root = (struct treeNode*)malloc(sizeof(struct treeNode));
    struct treeNode* lf = (struct treeNode*)malloc(sizeof(struct treeNode));

    lf->val = str[0];
    lf->left=NULL; lf->right=NULL;

    root->val = '=';
    root->left = lf;
    root->right = createAssignmentTree(str);
    
    postorder(root);

    deleteMemory(root);
}