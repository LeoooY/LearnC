#include <stdio.h>

int main() {
    // printf("Hello");
    int a = 2;
    int *p = &a;
    printf("value fo a, a: %d\n",a);
    printf("value of p, *p: %d\n",*p);
    printf("address of p, p: %p\n",p);
    printf("address of a, &a: %p\n",&a);
    printf("address of &p, &p: %p\n",&p);
}
