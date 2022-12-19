#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode{
    float val;
    char id[10];
    struct treeNode* p;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode* createNode(){
    struct treeNode* now = (struct treeNode*)malloc(sizeof(struct treeNode));
    float val; char str[10];
    scanf(" %s %f",str,&val);

    now->val=val;
    strcpy(now->id,str);
    now->p=NULL;
    now->left=NULL;
    now->right=NULL;
    return now;
}

void insert(struct treeNode** root, struct treeNode* now){
    struct treeNode* y = NULL;
    struct treeNode* x = *root;
    while(x!=NULL){
        y=x;
        if(now->val < x->val) x=x->left;
        else x=x->right;
    }
    now->p=y;
    if(y==NULL) *root=now;
    else if(now->val < y->val) y->left=now;
    else y->right=now;
}

void transplant(struct treeNode** root, struct treeNode* u, struct treeNode* v){
    if(u->p == NULL) *root=v;
    else if(u==u->p->left) u->p->left=v;
    else u->p->right=v;

    if(v!=NULL) v->p=u->p;
}

struct treeNode* search(struct treeNode* root, float val){
    if((root==NULL)||(root->val == val)) return root;

    if(val < root->val) return search(root->left,val);
    else return search(root->right, val);
}

struct treeNode* treeMin(struct treeNode* root){
    while(root->left) root=root->left;
    return root;
}

struct treeNode* treeMax(struct treeNode* root){
    while(root->right) root=root->right;
    return root;
}

struct treeNode* deleteNode(struct treeNode** root, float val){
    struct treeNode* now = search(*root,val);
    if(now==NULL) return NULL;

    if(now->left == NULL) transplant(root,now,now->right);
    else if(now->right == NULL) transplant(root,now,now->left);
    else{
        struct treeNode* y=treeMin(now->right);
        if(y->p != now){
            transplant(root,y,y->right);
            y->right=now->right;
            y->right->p=y;
        }
        transplant(root,now,y);
        y->left=now->left;
        y->left->p=y;
    }
    return now;
}


int maxDepth(struct treeNode* root){
    if(root==NULL) return -1;
    else{
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);

        if(ld > rd) return ld+1;
        else return rd+1;
    }
}

int isComplete(struct treeNode* root){
    if(root==NULL) return 1;

    int tmp = maxDepth(root->left)-maxDepth(root->right);
    if(tmp==0||tmp==1){
        return (isComplete(root->left)&&isComplete(root->right));
    }
    return 0;
}

void postorder(struct treeNode* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}

void print_tree(struct treeNode* root){
    if(root==NULL) printf("NULL\n");
    else{
        postorder(root);
        printf("\n");
    }
}

void find_cl(struct treeNode* root){
    printf("%d\n", maxDepth(root));
}

void insert_student(struct treeNode** tree1, struct treeNode** tree2, struct treeNode* now){
    insert(tree1,now);
    if(isComplete(*tree1)) return;
    else{
        struct treeNode* tmp = deleteNode(tree1, now->p->val);
        insert(tree2,tmp);
    }
}

void deleteMemory(struct treeNode* root){
    if(root==NULL) return;
    deleteMemory(root->left);
    deleteMemory(root->right);
    delete root;
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    struct treeNode* tree1 = NULL;
    struct treeNode* tree2 = NULL;

    // struct treeNode* now = createNode();
    // printf("%s %f\n",now->id, now->val);
    
    while(1){
        char c; scanf(" %c",&c);
        if(c=='i'){
            struct treeNode* now = createNode();
            insert_student(&tree1,&tree2,now);
        }
        else if(c=='p'){
            int tmp; scanf("%d",&tmp);
            if(tmp==1) print_tree(tree1);
            else print_tree(tree2);    
        }
        else if(c=='c'){
            int tmp; scanf("%d",&tmp);
            if(tmp==1) find_cl(tree1);
            else find_cl(tree2);
        }
        else{
            deleteMemory(tree1);
            deleteMemory(tree2);
            return 0;
        }
    }
}
