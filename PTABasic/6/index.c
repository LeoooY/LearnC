#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data;       /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum(List L);

int main() {
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for (i = 0; i < N; i++) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;
        L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */
int FactorialSum(List L) {
    int sum = 0;        
    while (L){
        sum += FactorL (L->Data);
        L = L->Next;
    };
    return sum;
};

int FactorL(int N) {
    if (N <= 1) {
        return 1;
    }
    return N*FactorL(N - 1);
}

int FactorL(int N) {
    int rs = 1;
    while (N > 1) {
        rs *= N--;
    }
    return rs;
}