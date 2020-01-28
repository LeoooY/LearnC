#include <stdio.h>

void Print_Factorial(const int N);

int main() {
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */

// 无法打印过长的int

// void Print_Factorial ( const int N ){
//     unsigned long long rs=1;
//     int n=N;
//     if(N<0){
//         printf("Invalid input");
//         return ;
//     }
//     while(n>0){
//         rs*=n--;
//     }
//     printf("%llu\n",rs);
// }

void Print_Factorial_fork(const int N) {

    int a[200], n, counter, temp, i;
    a[0] = 1;
    counter = 0;
    n = N;    
    /* a[200]存储每次阶乘的数字结果 */
    for (; n >= 2; n--) {
        temp = 0;

        /* 结果数组每位数字与下一个数字相乘 */
        for (i = 0; i <= counter; i++) {
            temp = (a[i] * n) + temp; // 结果数组每位数字与下一个阶乘数字n相乘 + 上一次乘后取最低位后的高一位temp
            a[i] = temp % 10; // 取temp最低位数字,更新对应的i位数字
            temp = temp / 10; // 继续取下一位数字

        }
        /* 每位数字都取完后,temp还大于0，说明相乘的结果的位数增加，剩下的继续取最低位放置到结果数组中，位数counter也随之增加
         */
        while (temp > 0) {
            a[++counter] = temp % 10;
            temp = temp / 10;
        }
    }
    for (i = counter; i >= 0; i--)
        printf("%d", a[i]);
    return;
}

void Print_Factorial(const int N) {
    if (N < 0) {
        printf("Invalid input");
        return;
    }
    if(N<=12 || N==0){
        long rs=1;
        int n=N;
        while(n>0){
            rs*=n--;
        }
        printf("%ld\n",rs);
        return ;
    }

    int rs[3000];          // 结果数组
    rs[0]=1;               // 初始化第一个乘的数字
    int size=0;           // 阶乘结果的位数
    int n=N;
    while(n>0){
        int temp=0;
        for(int i=0;i<=size;i++){
            temp=(rs[i]*n)+temp;
            rs[i]=temp%10; 
            temp=temp/10;
        }
        while(temp>0){
            rs[++size]=temp%10;
            temp=temp/10;
        }
        n--;
    }

    for(int i=size;i>=0;i--){
        printf("%d",rs[i]);
    }
    printf("\n");
}
