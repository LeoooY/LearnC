#include <stdio.h>
// #include "try.h"

int test(){
    return ;
}

void printArr(char *arr, int size){
    printf("[");
    // for(int i=0;i<size;*arr++){
    //     if(i==size-1){
    //         printf("%s", *arr);
    //     }else{
    //         printf("%s,", *arr);
    //     }        
    // }
    arr[0]='a';
    while(*arr){        
        printf("%c",*arr);
        *arr++;
    }
    printf("]\n");
}

int main(){
    char arr[]="abc";
    int size=(int)( sizeof(arr) / sizeof(arr[0]));
    printArr(&arr[0],size);
    return 0;
}
