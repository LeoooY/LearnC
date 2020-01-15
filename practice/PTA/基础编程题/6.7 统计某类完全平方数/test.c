#include <stdio.h>
#include <math.h>

int main() {
    int num = 5;
    char *rs = isPerfectSquare(num) ? "yes" : "no";

    printf("%d is perfect square? %s\n", num, rs);
}

int isPerfectSquare(int num) {
    float fsq;
    int isq;

    fsq = sqrt((double)num);
    isq = fsq;

    if (isq == fsq) {
        return 1;
    } else {
        return 0;
    }
}