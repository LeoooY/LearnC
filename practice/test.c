#include <stdio.h>

int main() {
    char a[] = "hello";
    char *pa = &a[0];
    char *p = "hello";
    char *pp = p;
    
    if (&a[0] == a && a==&a ) {
        printf("&a[0] == a == &a\n");
    }

    if ((&a + 1) == (a + 1)) {
        printf("&a+1 == a+1 \n");
    }else{
        printf("&a+1 != a+1 \n");
    }
}
