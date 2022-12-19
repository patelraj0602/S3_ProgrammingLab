#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _GNU_SOURCE

int main()
{
    FILE *ptr = NULL;
    FILE *fptr = NULL;
    char string[64];
    char str[64];
    char st[64];

    // ****** Reading a file ******
    // ptr = fopen(str, "r");
    //Reading till u encounter a white space exactly same as reading from console.
    // fscanf(ptr, "%s", string);
    // fscanf(ptr, "%s", st);

    // printf("%s\n",string);

    

    //This used to read first line in c.
    // fscanf(ptr,"%[^\n]", string);
    // printf("%s\n",string);

    // ****** Writing a file ******
    //Opening file in read mode clears all previous content of the file but it continue to write everthing that is present in fprintf..
    // ptr = fopen("myfile.txt", "w");
    // fprintf(ptr, "%s", string);
    // fprintf(ptr, "%s", " This is me again");

    // //For appending we have to make a new pointer or else appending will not happen..
    // fptr = fopen("myfile.txt", "a");
    // fprintf(fptr, "%s\n", string);
    // fprintf(fptr, "%s\n", string);


    //***** working of fgetc ******
    //Return type of this function is int..
    // ptr = fopen("myfile.txt","r");
    // char c = fgetc(ptr); 
    // printf("This is current char read : %c\n",c);

    // c = fgetc(ptr); 
    // printf("This is current char read : %c\n",c);

    //The coool version of the above line of codes for fgetc function..
    ptr = fopen("myfile.txt","r");
    char c = fgetc(ptr);
    while(c != EOF){
        if(c == '\n') printf(" Just let me know");
        printf("%c",c);
        c = fgetc(ptr);
    }


    //****working of fgets fuction ****

    // char str[100];
    // fgets(str,15,ptr); //here 5 denote the length of the string which you want to read including that null character..
    // printf("%s",str);


    //*****Working of fputc and fputs function *****
    //These function does not clear the previous content if they are used multiple times in consequetive order for example..
    // ptr = fopen("myfile.txt","w");
    // fputc('O',ptr);
    // fputc('\n',ptr);
    // fputs("yaam hae haam haam hae yaam\n", ptr);

    fclose(ptr);

    return 0;
}
