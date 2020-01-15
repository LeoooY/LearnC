#include <stdio.h>

int testStatic() {
    int a = 1;
    static int sa = 1;
    a++;
    sa++;
    printf("a: %d, sa: %d \n", a, sa);
}

int main() {
    for (int i; i < 5; i++) {
        testStatic();
    }
}