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
    do{
        rs+=factorail(L->Data);
        L=L->Next;
    }            
    while(L->Next);
    return rs;
}