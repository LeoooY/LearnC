#define GETLEN(x) (sizeof(x) / sizeof((x)[0]))
#include <stdio.h>

void printArr(int *arr){
    int size=GETLEN(arr);    
    
    printf("[");
    for(int i=0;i<size;i++){
        if(i==size-1){
            printf("%d", arr[i]);
        }else{
            printf("%d,", arr[i]);
        }        
    }
    printf("]\n");
}
