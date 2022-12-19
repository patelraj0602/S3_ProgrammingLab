#include <stdio.h>
int main(){
    //We have to appraoc this question in this manner only. Because we do know the size of our string..
    //And we cannot use scanf because if stops to read everything after a space bar..
    /*To deal with the above problem we can use get() fuction but if the input exceeds the size of our 
    declared array then it keeps on writing beyound that and we may get segmentation fault..
    */

    int c;
    //In this code getchar() reads the code letter by letter and converts it into "int" according to ascii..
    //We need to stop reading lines when we meet new line or when we reach end of the document..
    while(((c=getchar())!='\n') && (EOF != c)){
        if(c==32) c=32;
        else if((c>=97) && (c<=122)) c-=32;
        else c+=32;
        printf("%c",c);
    }
}