<!-- TOC -->

- [[learn-c.org](https://www.learn-c.org/)](#learn-corghttpswwwlearn-corg)
        - [模块预处理器](#模块预处理器)
        - [变量申明](#变量申明)
        - [数组 Arrays](#数组-arrays)
        - [多维数组 Multidimensional Arrays](#多维数组-multidimensional-arrays)
        - [条件判断](#条件判断)
        - [字符串 Stings](#字符串-stings)
        - [循环 For Loop](#循环-for-loop)
        - [循环 While Loop](#循环-while-loop)
        - [函数 Functions](#函数-functions)
        - [静态声明 static](#静态声明-static)
        - [指针 Pointer](#指针-pointer)
        - [（对象）结构 Structures](#对象结构-structures)
        - [`按值传递` 和 `按址(引用)传递`函数参数 Function arguments by reference](#按值传递-和-按址引用传递函数参数-function-arguments-by-reference)
        - [动态内存分配 Dynamic allocation](#动态内存分配-dynamic-allocation)
        - [数组与指针](#数组与指针)
        - [字符串指针和字符串　Char pointer and Char](#字符串指针和字符串　char-pointer-and-char)
        - [递归 Recursion](#递归-recursion)
        - [链表 linked list](#链表-linked-list)
        - [二叉树 binary tree](#二叉树-binary-tree)
            - [二叉树的常规操作](#二叉树的常规操作)
        - [二叉平衡树](#二叉平衡树)
        - [集合 Union](#集合-union)
        - [指针运算 Pointer Arithmetics](#指针运算-pointer-arithmetics)
        - [函数指针 Function Pointers](#函数指针-function-pointers)

<!-- /TOC -->
# [learn-c.org](https://www.learn-c.org/)

### 模块预处理器
- `#include <studio.h>` 

### 变量申明
```
K&R: int short long unsigned char float double
C90：signed void
C99：_Bool 布尔型 _Complex 复数 _Imaginary 虚数

常量：#define const

//eg:
int a;
int b=1;
char name[40];
void c;

#define PI 3.14;
const int c=0;

```
### 数组 Arrays
```
// type name[size]
int numbers[10];  // 定义有10个成员的数组numbers, 成员类型为int

numbers[0]=100;
numbers[1]=120;

int array[5]={0,1,2,3,4};
```

### 多维数组 Multidimensional Arrays
```
// type name[size1][size2]...[sizeN]; 定义
//  name[x][y]; 取值

定义一个1行5列的多维数组
char vowels[1][5] = {
    {'a', 'e', 'i', 'o', 'u'}
};

定义一个3行4列的多维数组
int a[3][4] = {  
   {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
   {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
   {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
};

```

### 条件判断 
```
if(){

}else if(){

}else{

}
```

### 字符串 Stings 
定义 Defining strings

```
// Strings in C are actually arrays of characters.

// use pointers to a character array to define simple strings, in the following manner:

char * name ="John Smith"

char name[] = "John Smith"; // 自动计算数组长度

/* is almost the same as */
char name[11] = "John Smith";
```

字符串格式化输出
```
%d
%s
\n

```
### 循环 For Loop
```

int main(){
  int sum;
  for(int i=0;i<10;i++){
    sum+=i;
  }
  return sum;
}

```

### 循环 While Loop
```
int n=0
while(n<10)}{
  n++;
  if(n%2==1){
    printf("This number is odd, %d",n)
    continue;
  }

  if(n==8){
    break;
  }
}

```

### 函数 Functions
```
In C, functions must be first defined before they are used in the code.

在C语言中，函数需要先定义才可以使用

/* function declaration */
/* 函数定义 */
int foo(int bar);
void moo();


int main() {
    /* calling foo from main */
    printf("The value of foo is %d", foo(1));  //调用foo函数，bar为1
}

int foo(int bar) {
    return bar + 1;
}

void moo() {
    /* do something and don't return a value */
}

```

### 静态声明 static
可以用于申明变量`variables`和函数`functions`
将变量和函数的作用域改为当前文件的作用域
```
函数申明的作用域,默认为global,使用static申明可将作用域缩减到file scope.

函数中申明的变量,默认为function scope,使用static申明可将作用域扩大到file scope.

1 在修饰变量的时，static修饰的静态局部变量只执行一次，而且延长了局部变量的生命周期，直到程序运行结束以后才释放。

2 static修饰全局变量的时，这个全局变量只能在本文件中访问，不能在其它文件中访问，即便是extern外部声明也不可以。 

3 static修饰一个函数，则这个函数的只能在本文件中调用，不能被其他文件调用。Static修饰的局部变量存放在全局数据区的静态变量区。

```

### 指针 Pointer
指针是C语言中非常重要的变量，
使用范围：
- 声明字符串 Strings
- 动态内存分配 Dynamic memory allocation
- 按指针传递函数参数 Sending function arguments by reference
- 构建复杂的数据结构 Building complicated data structures
- 指向函数 Pointing to functions
- 构建特殊的数据结构 Building special data structures (i.e. Tree, Tries, etc...)

什么是指针？
指针是一个变量，指向其`value`在内存中的`地址`,而不是直接将值存储在变量中。
（简言之，指针是一个指向内存地址的变量，变量的值存储在其指向的内存地址中，指针变量页存在内存的某个地址中）

操作符
- `*` 定义、使用指针, 间接寻址运算符，返回指针指向的内存地址的值
- `&`  取地址运算符, 返回变量所在的内存地址

```
int p=&x

*p      # 指向地址的值
p       # 指针
&x      # x的地址

```
```
// int xx=1
// int *p = &xx
// *p 使用指针
// %p,打印内存地址 printf("p: %p", p) 


int a=1;
int *p=&a;

printf("a: %d",a);          // a的值1
printf("a: %p",&a);         // a的地址 0x7fffffffddfc

printf("*p: %d",*p);      // 1, p指向的内存地址的值>a=1
printf("p: %p",p);        // p指向的内存地址，即a的内存地址：0x7fffffffddfc
printf("&p: %p",&p);      // 保存p指针的内存地址：0x7fffffffde00
```

```
/* define a local variable a */
int a = 1;

/* define a pointer variable, and point it to a using the & operator */
int * pointer_to_a = &a;

printf("The value a is %d\n", a);
printf("The value of a is also %d\n", *pointer_to_a);
```


```
int a = 1;
int * pointer_to_a = &a;

/* let's change the variable a */
a += 1;

/* we just changed the variable again! */
*pointer_to_a += 1;

/* will print out 3 */
printf("The value of a is now %d\n", a);
```

### （对象）结构 Structures
C structures are special, large variables which contain several named variables inside.

`struct`是C语言中`Objects`对象和`Class`类的基础

可以用`struct`或者`typedef struct`定义，区别在于：
- `struct varname {}`定义结构，使用时还得用`struct varname`申明
- `typedef struct {} varname`定义结构，使用时直接使用定义的变量名`varname`申明
```
// 定义结构
struct point {
    int x;
    int y;
};

// 使用结构
struct point p;
p.x=1;
p.y=10;

printf(p);

// 自定义结构 typedefs

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    char * brand;
    int model;
} vehicle;


// 使用结构
point p;
vehicle mycar;

// mycar.brand = "Ford";
// mycar.model = 2007;

// 指向结构的指针、
# 定义结构
typedef struct {
        int age;
        char * name;
} person;

# 创建一个person结构的变量
person leo;
leo.name="leo";
leo.age=23;

# 创建一个指向person结构变量leo的指针
person *ps=&leo;

# 使用指向结构的指针

printf("leo.age: %d\n", (*ps).age);
printf("leo.age: %s\n", (*ps).name);
# or
printf("leo.age: %d\n", ps->age);
printf("leo.age: %s\n", ps->name);

ps->age=12
ps->name="leoy";
```
### `按值传递` 和 `按址(引用)传递`函数参数 Function arguments by reference


- 按址传递（传递一个指针），会将指针本身改变，（参考Js引用类型，Array,Object,Function...）
- 按值传递，传递了变量值的一个拷贝，不会改变原变量.

- 函数参数为指针，可以通过指针操作变量的值

```
# 参数为普通指针


# 参数为指向struct的指针
void move(point * p) {
    (*p).x++;
    (*p).y++;
}
# 另一中写法shorthand syntax
void move(point * p) {
    p->x++;             # 见->操作符即想到该变量是一个指向struct的指针
    p->y++;             # p-> : 理解为返回指针变量指向的struct的地址中的值 (然而并不能直接这样用，只能用于操作成员属性)
                        # p->y: 操作符右边可以直接访问到struct的成员属性的值
}
```

### 动态内存分配 Dynamic allocation
- ->  访问struct属性
- malloc( sizeof( dataType )) 按需分配内存
- free()  释放malloc分配的内存,只清空了变量指向的内存，并没有清除该变量
```
typedef struct {
    char * name;
    int age;
} person;

person * myperson = malloc(sizeof(person));  // 告诉编译器，根据值动态分配足够person strcut的内存大小

myperson->name = "John";
myperson->age = 27;

free(myperson);

```
### 数组与指针
指向数组的指针
```
char vowels[] = {'A', 'E', 'I', 'O', 'U'};
char *pvowels = &vowels; 
# char *pvowels = vowels; 也可以
# &vowel代表数组首地址，vowels表示vowels[0]的首地址

// Print the addresses
for (i = 0; i < 5; i++) {
    printf("&vowels[%d]: %u, pvowels + %d: %u, vowels + %d: %u\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
}

// Print the values
for (i = 0; i < 5; i++) {
    printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
}
```
数组的动态内存分配
- 一维数组
```
// Allocate memory to store five characters
int n = 5;
char *pvowels = (char *) malloc(n * sizeof(char));
int i;

pvowels[0] = 'A';
pvowels[1] = 'E';
*(pvowels + 2) = 'I';
pvowels[3] = 'O';
*(pvowels + 4) = 'U';

for (i = 0; i < n; i++) {
    printf("%c ", pvowels[i]);
}

printf("\n");

free(pvowels);
```
- 二维数组 需要使用多个指针
```
int nrows = 2;
int ncols = 5;
int i, j;

// Allocate memory for nrows pointers
char **pvowels = (char **) malloc(nrows * sizeof(char *));

// For each row, allocate memory for ncols elements
pvowels[0] = (char *) malloc(ncols * sizeof(char));
pvowels[1] = (char *) malloc(ncols * sizeof(char));

pvowels[0][0] = 'A';
pvowels[0][1] = 'E';
pvowels[0][2] = 'I';
pvowels[0][3] = 'O';
pvowels[0][4] = 'U';

pvowels[1][0] = 'a';
pvowels[1][1] = 'e';
pvowels[1][2] = 'i';
pvowels[1][3] = 'o';
pvowels[1][4] = 'u';

for (i = 0; i < nrows; i++) {
    for(j = 0; j < ncols; j++) {
        printf("%c ", pvowels[i][j]);
    }

    printf("\n");
}

// Free individual rows
free(pvowels[0]);
free(pvowels[1]);

// Free the top-level pointer
free(pvowels);
```
###　字符串指针和字符串　Char pointer and Char
- [Strings as arrays, as pointers, and string.h](https://www.cs.bu.edu/teaching/c/string/intro/) **推荐，可以透彻理解**
```
char amessage[] = "now is the time";
# Defines an array whose members live in the current scope's stack space, whereas:
# 定义了一个数组，成员在当前变量的内存地址中

char *pmessage = "now is the time";
＃　定义了一个指针，指针在当前变量的内存地址，而数据存储在内存的其他某个地址，一般存在string table中
pmessage      // "now is the time"
*pmessage     // n
*(pmessage+1) // o
*(pmessage+2) // w

```

### 递归 Recursion
- 递归实现乘法
```
#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y)
{
    if (x == 1)
    {
        /* Terminating case */
        return y;
    }
    else if (x > 1)
    {
        /* Recursive step */
        return y + multiply(x-1, y);
    }

    /* Catch scenario when x is zero */
    return 0;
}

int main() {
    printf("3 times 5 is %d", multiply(3, 5));
    return 0;
}

```
- 递归阶乘
```
#include <stdio.h>

int factorial(int x){
    if(x==1){
    	return x;
    }
    
    return x*factorial(x-1);
}

int main() {
    /* testing code */
    printf("1! = %i\n", factorial(1));
    printf("3! = %i\n", factorial(3));
    printf("5! = %i\n", factorial(5));
}
```

### 链表 linked list
链表是用指针实现的最好的且最简单的动态数据结构
理解链表的前置知识：指针、struct、动态内存分配

- 链表对于数组的优势
  1 从链表中间插入或者删除元素的开销很小
  2 不需要在申明时定义链表大小（C语言中数组的申明需要定义数组长度大小）
- 劣势
  1 不能像数组一样根据idx随机存取，必须从头指针开始遍历直到idx元素（访问开销大） 
  2 需要动态分配内存和指针来进行申明，增加了代码复杂度进而增加内存泄漏风险和segment faults
  3 链表占用存储空间更大，因为每个节点要多存储一个指针域

Q: 什么是链表？
A: 链表是由一组动态分配内存的节点构成的数据结构，每个节点包含一个`数据域`和一个`指针域`，`指针域`永远指向下一个节点。
如果一个节点的`指针域`指向为`NULL`，那么这个节点为该链表的结束。
如果指向第一个节点的指针指向为`NULL`，那么这个链表为空链表。

定义链表结构
```
typedef struct node {
    int val;
    struct node * next;
} listNode;
```
定义链表
```
listNode * head=NULL;
head=malloc(sizeof(listNode));

if(head == NULL){
  return 1
}

head -> val= '节点数据';
head -> next = NULL; // 指定下一个节点为空

```

### 二叉树 binary tree
- 二叉树是每个结点最多含有两个节点的数据结构
- 二叉树数据结构可以用于实现二叉搜索树、binary heaps(堆)等
- 二叉树是一种特殊的多叉树，其叉为2

#### 二叉树的常规操作
- 插入 insertion
- 删除 deletion
- 遍历 tarverlsal

### 二叉平衡树
二叉平衡树左右子树深度之差小于等于1
二叉平衡树深度=log2(N)，N为元素个数

- 深度优先算法
- 广度优先算法

```
typedef struct node
{
  int val;
  struct node * left;
  struct node * right;
} bTreeNode;
```

### 集合 Union 
C中的集合和C中的struct一样重要,在集合中一个
```
union intParts {
  int theInt;
  char bytes[sizeof(int)];
};
```

### 指针运算 Pointer Arithmetics
- `Incrementing a Pointer with (++)`

- `Decreasing a Pointer with (--)`

- `Adding Pointers with (+)`

- `Subtracting Pointers with (-)`


### 函数指针 Function Pointers
```
void (*pf)(int);

char* (*pf)(int*)
```

```
#include <stdio.h>
void someFunction(int arg)
{
    printf("This is someFunction being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");
}

main()
{
    void (*pf)(int);
    pf = &someFunction;
    printf("We're about to call someFunction() using a pointer!\n");
    (pf)(5);
    printf("Wow that was cool. Back to main now!\n\n");
}
```

```
#include <stdio.h>
#include <stdlib.h> //for qsort()

int compare(const void* left, const void* right)
{
    return (*(int*)right - *(int*)left);
    // go back to ref if this seems complicated: http://www.cplusplus.com/reference/cstdlib/qsort/
}
main()
{
    int (*cmp) (const void* , const void*);
    cmp = &compare;

    int iarray[] = {1,2,3,4,5,6,7,8,9};
    qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp);

    int c = 0;
    while (c < sizeof(iarray)/sizeof(*iarray))
    {
        printf("%d \t", iarray[c]);
        c++;
    }
}
```



