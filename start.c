/* 
  #include <stdio.h> 是预处理器指令，
  告诉 C 编译器在实际编译之前要包含 stdio.h 文件。
*/
#include <stdio.h>

// char foo(char bar);


/* 
  int main() 是主函数，程序从这里开始执行
 */

char foo(char bar){
  printf("call foo, return %d",bar);
  return bar;
}

int runner()
{
    static int count = 0;
    count++;
    return count;
}


int main()
{
    /* 我的第一个 C 程序 */
    printf("Hello, World! \n");

    /* return 0; 终止 main() 函数，并返回值 0 */

    int num;
    num=1;

    printf("I am a simple computer\n");
    printf("My favorate number is %d, ",num);
    printf("because it`s the first\n");

    printf("%d ", runner());
    printf("%d \n", runner());
    foo("barbarbar");
    return 0;
}