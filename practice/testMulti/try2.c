#include <stdio.h>

int b=4;
// extern int b;
static void hello(){
    b+=10;
    printf("Hello, %d",b);
}
