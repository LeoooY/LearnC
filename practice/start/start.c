/* 
  #include <stdio.h> 是预处理器指令，
  告诉 C 编译器在实际编译之前要包含 stdio.h 文件。
*/
#include <stdio.h>
#include <stdlib.h>

// char foo(char bar);


/* 
  int main() 是主函数，程序从这里开始执行
 */

char *foo(char * bar){
  printf("call foo, return %s\n",bar);
  return bar;
}

int runner()
{
    static int count = 0;
    count++;
    return count;
}

typedef struct node{
  int val;
  struct node * next;
} listNode;

listNode * initANode(int value){
  listNode * node=NULL;
  node=malloc( sizeof(listNode));
  
  node -> val=value;
  node -> next=NULL;
  return node;
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

    listNode * head=initANode(2);
    printf("pointer head,%d,%s\n",head->val,head->next);
    head->next=initANode(9);    
    printf("pointer first item,%d,%o,%d,%o\n",head->val,head->next,head->next->val,head->next->next);
    

    return 0;
}