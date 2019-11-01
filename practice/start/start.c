// /* 
//   #include <stdio.h> 是预处理器指令，
//   告诉 C 编译器在实际编译之前要包含 stdio.h 文件。
// */
// #include <stdio.h>
// #include <stdlib.h>

// // char foo(char bar);


// /* 
//   int main() 是主函数，程序从这里开始执行
//  */

// char *foo(char * bar){
//   printf("call foo, return %s\n",bar);
//   return bar;
// }

// int runner()
// {
//     static int count = 0;
//     count++;
//     return count;
// }

// typedef struct node{
//   int val;
//   struct node * next;
// } listNode;

// listNode * initANode(int value){
//   listNode * node=NULL;
//   node=malloc( sizeof(listNode));
  
//   node -> val=value;
//   node -> next=NULL;
//   return node;
// }

// int main()
// {
//     /* 我的第一个 C 程序 */
//     printf("Hello, World! \n");

//     /* return 0; 终止 main() 函数，并返回值 0 */

//     int num;
//     num=1;

//     printf("I am a simple computer\n");
//     printf("My favorate number is %d, ",num);
//     printf("because it`s the first\n");

//     printf("%d ", runner());
//     printf("%d \n", runner());
//     foo("barbarbar");

//     listNode * head=initANode(2);
//     printf("pointer head,%d,%s\n",head->val,head->next);
//     head->next=initANode(9);    
//     printf("pointer first item,%d,%o,%d,%o\n",head->val,head->next,head->next->val,head->next->next);
    

//     return 0;
// }






#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    // scanf("%d", &N);
    L = NULL;
    // for ( i=0; i<N; i++ ) {
    //     p = (List)malloc(sizeof(struct Node));
    //     scanf("%d", &p->Data);
    //     p->Next = L;  L = p;
    // }
    p = (List)malloc(sizeof(struct Node));
    p->Data=5;
    p->Next = L;  
    L = p;

    p = (List)malloc(sizeof(struct Node));
    p->Data=3;
    p->Next = L;  
    L = p;

    p = (List)malloc(sizeof(struct Node));
    p->Data=6;
    p->Next = L;  
    L = p;

    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */
int factorail(int num){
    if(num==1){
        return num;
    }
    return num*factorail(num-1);
}

int FactorialSum( List L ){
    int rs=0;    
    while(L){                
        rs+=factorail(L->Data);        
        L=L->Next;
        
    };
    return rs;
}