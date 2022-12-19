//There is some bug in this code...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct amoeba{
    char name[20];
    int size;
};

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b; 
    *b = tmp;
}

void swapstr(struct amoeba* c, struct amoeba* d){
    swap(&c->size, &d->size);

    char tmp[20];
    strcpy(tmp, c->name);
    strcpy(c->name, d->name);
    strcpy(d->name, tmp);
}

void min_heapify(struct amoeba* amoebas, int len, int i){
    int s = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<len){
        if(amoebas[s].size>amoebas[l].size) s=l;
        else if(amoebas[s].size==amoebas[l].size){
            if(strcmp(amoebas[s].name, amoebas[l].name)>0) s = l;
        }
    }

    if(r<len){
        if(amoebas[s].size>amoebas[r].size) s=r;
        else if(amoebas[s].size==amoebas[r].size){
            if(strcmp(amoebas[s].name, amoebas[r].name)>0) s = r;
        }
    }

    if(s != i){
        swapstr(&amoebas[s],&amoebas[i]);
        min_heapify(amoebas,len,s);
    }
}

void Build_min_heapify(struct amoeba* amoebas, int len){
    for(int i=len/2-1; i>=0; i--){
        min_heapify(amoebas,len,i);
    }
}


void heapsort(struct amoeba* amoebas, int n){
    for(int i=n-1; i>=n-2; i--){
        swapstr(&amoebas[0],&amoebas[i]);
        min_heapify(amoebas,i,0);
    }
}

void read(struct amoeba* current){
    scanf("%s %d", &current->name, &current->size);
    return;
}

void insert(struct amoeba* amoebas, struct amoeba* current, int i){
    strcpy(amoebas[i].name, current->name);
    amoebas[i].size = current->size;
}

void combine(struct amoeba* amoebas, int len){
    for(int i=0; i<len-1; i++){
        Build_min_heapify(amoebas, len-i);
        heapsort(amoebas, len-i);

        printf("%s %s %d\n",amoebas[len-i-1].name,amoebas[len-i-2].name,amoebas[len-i-1].size+amoebas[len-i-2].size);
        amoebas[len-i-2].size += amoebas[len-i-1].size;
        strcpy(amoebas[len-i-2].name, amoebas[len-i-1].name);
    }
    printf("%s %d\n",amoebas[0].name,amoebas[0].size);
}

int main(){
    int len;
    scanf("%d",&len);
    struct amoeba* amoebas = (struct amoeba*)malloc(len*sizeof(struct amoeba));
    for(int i=0; i<len; i++){
        struct amoeba current;
        read(&current);
        insert(amoebas,&current,i);
    }
    combine(amoebas,len);
	free(amoebas);
}

