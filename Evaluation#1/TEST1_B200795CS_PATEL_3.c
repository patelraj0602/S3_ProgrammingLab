#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct money{
    char cus_id[10];
    int token_no;
    int amount;
};

void read_details(struct money* details, int cus){
    for(int i=0; i<cus; i++){
        scanf("%s", &details[i].cus_id);
        scanf("%d", &details[i].token_no);
        scanf("%d", &details[i].amount);
    }
}

void print_details(struct money* details, int cus){
    for(int i=0; i<cus; i++){
        printf("%s ", details[i].cus_id);
        printf("%d ", details[i].token_no);
        printf("%d\n", details[i].amount);
    }
}



// void serve_customer(struct money* details, int cus){

// }

int main(){
    int cus;
    int R;
    struct money* details;
    char c;
    while(1){
        scanf("%c",&c);
        if(c=='r'){
            scanf("%d %d", &cus,&R);
            details = (struct money*)malloc(cus*(sizeof(struct money)));
            read_details(details,cus);
        }

        else if(c=='p') print_details(details,cus);

        // else if(c=='s') serve_customer(details,cus);

        else {
            free(details);
            return 0;
        }
    } 

}