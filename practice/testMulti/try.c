#include <stdio.h>
#include "try.h"

extern int a;
extern int b;

int main(){
    printf("Main Hello,%d,%d\n",b);
    // b+=10;
    hello();
    // b=9;
    hello();
    return 0;
}
