#include <stdio.h>
#include <string.h>
#include <string.h>

struct student
{
    int id;
    char name[20];
    int rank;
};

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}

void swapstr(struct student* c, struct student* d){
    swap(&c->id, &d->id);
    swap(&c->rank, &d->rank);

    char tmp[20];
    strcpy(tmp, c->name);
    strcpy(c->name, d->name);
    strcpy(d->name, tmp);

}

void max_heapify(struct student* s, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;

    if(l<n && s[l].rank<s[smallest].rank) smallest = l;
    if(r<n && s[r].rank<s[smallest].rank) smallest = r;

    if(smallest != i){
        swapstr(&s[smallest],&s[i]);
        max_heapify(s,n,smallest);
    }
}

void Build_max_heap(struct student* students, int len){
    for(int i=len/2-1; i>=0; i--){
        max_heapify(students,len,i);
    }
}

void heapsort(struct student* s, int n){
    for(int i=n-1; i>=0; i--){
        swapstr(&s[0],&s[i]);
        max_heapify(s,i,0);
    }
}

void enter(struct student* students, int* len){
    int sz = *len;
    scanf("%d %s %d", &students[sz].id, students[sz].name, &students[sz].rank);
    *len = *len+1;
}

void interview(struct student* students, int* len){
    if(*len == 0) {
        printf("-1\n");
        return;
    }
    Build_max_heap(students, *len);
    
    printf("%d %s\n",students[0].id, students[0].name);
    for(int i=1; i<*len; i++) swapstr(&students[i-1], &students[i]);
    *len=*len-1;
}

void list(struct student* students, int* len){
    int sz = *len;
    if(*len==0){
        printf("-1\n");
        return;
    }
    Build_max_heap(students,sz);
    heapsort(students,sz);

    for(int i = sz-1; i>=0; i--) printf("%d ",students[i].id);
    printf("\n");
    
}

int main()
{
    //According to question we are not allowed to pass the size of array in the function. But I am passing
    //because there is no other way to find out the size of array other than iterating
    //through the size of the array each and everything which consumes extra time.
    struct student students[1000];
    int len = 0;
    
    while (1)
    {
        char ch;
        scanf(" %c", &ch);
        
        if (ch == 'e') enter(students,&len);
        else if(ch == 'i') interview(students,&len);
        else if(ch=='l') list(students,&len);
        else break;
    }
}