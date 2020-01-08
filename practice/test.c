#include <stdio.h>

int main(){
    char a[]="hello";
    char *pa=&a[0];
    char *p="hello";
    char *pp=p;
    if(pp==p){
        printf("Hello\n");
    }    
 }
