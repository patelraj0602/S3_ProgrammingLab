#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cur = 0;
int ans[1000];

int nw = 0;
int n;

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void recursiveCheck(int** tmp, int now, int* visited){
    if(visited[now]) return;
    visited[now]=1;
    int len = tmp[now][99];

    for(int i=0; i<len; i++) recursiveCheck(tmp, tmp[now][i], visited);
    return;
}

int isConnected(int** tmp, int start){

    //Set up an visted array and later check from that visted array that everything got visited or not..
    int *visited = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) visited[i]=0;

    recursiveCheck(tmp,start,visited);

    // printf("This is visited arr : ");
    // for(int i=0; i<n; i++) printf("%d ",visited[i]);
    // printf("\n");

    for(int i=0; i<n; i++){
        if(tmp[i]==NULL) continue;
        else{
            if(!visited[i]){
                free(visited);
                return 0;
            }
        }
    }
    free(visited);
    return 1;
}

int helper(int** edges, int nw){
    //Copying everything in tmp so that I can work on it..
    int** tmp = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        if(edges[i]==NULL) {
            tmp[i]=NULL;
            continue;
        }
        int* arr = (int*)malloc(100*sizeof(int));
        memcpy(arr,edges[i],100*sizeof(int));
        tmp[i]=arr;
    }

    int ll = tmp[nw][99];
    for(int i=0; i<ll; i++){
        int tt = tmp[nw][i];
        int len = tmp[tt][99]; int j=0;
        while(j<len){
            if(tmp[tt][j] == nw){
                tmp[tt][99]--; len--;
                swap(&tmp[tt][j],&tmp[tt][len]);
            }
            else j++;
        }
    }
    free(tmp[nw]); tmp[nw]=NULL;

    //Finding the point from where the recursion to check connectivity starts..
    int start = 0;
    for(int i=0; i<n; i++){
        if(tmp[i]!=NULL){
            start = i;
            break;
        }
    }

    int b = isConnected(tmp,start);
    
    //This is for checking purpose..
    // printf("Kya huwa connected ka : %d\n",b);

    // for(int i=0; i<n; i++){
    //     if(tmp[i]==NULL){
    //         printf("NULL\n");
    //         continue;
    //     }
    //     printf("The length of the array is : %d and the array elements are  ", tmp[i][99]);
    //     int len = tmp[i][99];
    //     for(int j=0; j<len; j++) printf("%d ",tmp[i][j]);
    //     printf("\n");
    // }

    // printf("This is the start %d",start);


    //Freeing memory
    for(int i=0; i<n; i++) 
        if(tmp[i]) free(tmp[i]);
    free(tmp);

    return b;
}

//Insert the element in appropirate postion..
void insert(int first, int second, int in){
    int i=0;
	while(i+1 < cur){
	    if((ans[i]==first && ans[i+1]==second)||(ans[i]==second && ans[i+1]==first)){
	        for(int j = cur; j>=i+2; j--){
	            ans[j]=ans[j-1];
	        }
	        ans[i+1]=in;
	        cur++;
	        break;
	    }
	    i++;
	}
}

void insertSelfLoops(int now, int num){
    int i;
    for(i=0; i<cur; i++)
        if(ans[i]==now) break;

    for(int j=cur-1; j>i; j--) ans[j+num]=ans[j];
    for(int j=1; j<=num; j++) ans[j+i]=now;
    cur+=num;
}

void path(int ** edges, int len){
    if(len==1){
        for(int i=0; i<n; i++){
            if(edges[i]!=NULL){
                int len = (edges[i][99]/2);
                for(int j=0; j<=len; j++) ans[cur++]=i;
                free(edges[i]);
                return;
            }
        }
        // printf("This is returning stuff : ");
        // for(int i=0; i<cur; i++) printf("%d ",ans[i]);
        // printf("\n");
        // return;
    }

    //edges[nw%n]!=NULL wrong but still
    while(1){
        if(edges[nw]==NULL) {
            nw = (nw+1)%n;   
            continue;
        }
        else if(helper(edges,nw)) break;
        nw = (nw+1)%n;
    }
    printf("Break kidhar huwa : %d\n",nw);

    //Now I know that on removing nw the graph is still connected so I will 
    //remove that edge and make G'and call it recursively..
    
    int* lk = (int*)malloc(100*sizeof(int));
    int fnow = nw; 
    memcpy(lk,edges[nw],100*sizeof(int));

    int ll = edges[nw][99];
    for(int i=0; i<ll; i=i+2){
        int first = edges[nw][i];
        int second = edges[nw][i+1];

        int lf = edges[first][99];
        for(int j=0; j<lf; j++){
            if(edges[first][j]==nw) edges[first][j]=second;
        }

        int ls = edges[second][99];
        for(int j=0; j<ls; j++){
            if(edges[second][j]==nw) edges[second][j]=first;
        }
    }
    free(edges[nw]); edges[nw]=NULL;

    //This is my printer for checking purposes..
    // for(int i=0; i<n; i++){
    //     if(edges[i]==NULL){
    //         printf("NULL\n");
    //         continue;
    //     }
    //     printf("The length of the array is : %d and the array elements are  ", edges[i][99]);
    //     int len = edges[i][99];
    //     for(int j=0; j<len; j++) printf("%d ",edges[i][j]);
    //     printf("\n");
    // }

    path(edges, len-1);

    //I am making a path using this logic..
    int flen = lk[99];
    int selfLoops = 0;
    for(int i=0; i<flen; i=i+2){
        int first = lk[i]; int second = lk[i+1];
        if((fnow==first)&&(fnow==second)) selfLoops++;
        else insert(first,second,fnow);
    }

    if(selfLoops > 0) insertSelfLoops(fnow,selfLoops);

    free(lk);

}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int e;
    scanf("%d %d",&n, &e);

    int** edges = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        int* tmp = (int*)malloc(100*sizeof(int));
        tmp[99]=0;
        edges[i]=tmp;
    }

    for(int i=1; i<=e; i++){
        int p,q; scanf("%d %d",&p,&q);
        int val = edges[p][99]; edges[p][99]++;
        edges[p][val]=q; 
        
        val=edges[q][99]; edges[q][99]++;
        edges[q][val]=p;
    }


    for(int i=0; i<n; i++){
        int val = edges[i][99];
        if(val%2) {
            printf("Not Eulerian\n");
            return 0;
        }
    }

    for(int i=0; i<n; i++){
        printf("The length of the array is : %d and the array elements are  ", edges[i][99]);
        int len = edges[i][99];
        for(int j=0; j<len; j++) printf("%d ",edges[i][j]);
        printf("\n");
    }
    printf("\n");
    
    path(edges,n);

    printf("\n");
    printf("Show time : ");
    for(int i=0; i<cur; i++) printf("%d ",ans[i]);

    // helper(edges,0);

    //Freeing memory
    // for(int i=0; i<n; i++) 
    //     if(edges[i]!=NULL) free(edges[i]);
    free(edges);
}















