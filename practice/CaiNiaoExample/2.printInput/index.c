#include <stdio.h>

int main(){
    int number;
    printf("请输入一个整数：");
    
    // 获取输入的函数，和printf同样由stdio.h引入
    // %d 用于将输入格式化为整数
    // &number 用于将输入赋值给number变量
    scanf("%d",&number);

    // %d 在这里用于格式化输出
    printf("你输入的整数是： %d",number);

    return 0;
}