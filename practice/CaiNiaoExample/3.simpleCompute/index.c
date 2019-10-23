#include <stdio.h>

// 题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
/*
    //
   完全平方指用一个整数乘以自己例如1*1，2*2，3*3等，依此类推。若一个数能表示成【某个整数的平方的形式】，则称这个数为【完全平方数】。完全平方数是【非负数】

    1：
    设该数为x，
    x+100=n^2     （1）
    x+100+168=m^2  （2）

    2：
    （2）-（1）得到：
    n^2-m^2=(n+m)(n-m)=168

    3：
    设  m+n=i    （3）
        m-n=j，  （4）
    则  i*j=168  （5）

    得i, j中至少有一个为偶数

    4：
    由（3）、（4）可得
        m=i+j/2
        n=i-j/2
    （m,n为整数，2m 和 2n就必为偶数，即 i+j 且 i-j 皆为偶数，即：）
    得 i 和 j 要么都是偶数，要么都是奇数（同偶异奇）

    5：结合3，4，可得，i,j皆为偶数。 （6）
    又m,n为非负整数,
    得 i+j=2m>=0 （7）
       i-j=2n>=0  (8)
    结合（5）（6）（7）（8），
    得 i,j皆为 ：[2, 168/2]，且满足（5）（6）（7）（8）

 */

int main() {
    int j;
    int m, n;
    int x;
    for (int i = 2; i <= (168 / 2); i++) {
        if (168 % i == 0) {
            j = 168 / i;
            if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0) {
                m = (i + j) / 2;
                n = (i - j) / 2;
                x = n * n - 100;
                printf("%d + 100 = %d * %d\n", x, n, n);
                printf("%d + 268 = %d * %d\n\n", x, m, m);
            }
        }
    }
}