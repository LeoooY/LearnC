## 第二章 类型、运算符与表达式
### 2.8 自增运算符与自减运算符
- 前缀 ++ --
- 后缀 ++ --
前缀 ++ -- 会在执行赋值表达式之前进行自增或自减
```
int n=5;
int x=++n;          
//x > 6,  n > 6
```
后缀 ++ -- 会在执行赋值表达式之前进行自增或自减
```
if (c == '\n') {
    s[i++] = c; 
}

# 等同于

if (c == '\n') { 
 s[i] = c; 
 ++i; 
}  

while ((s[i++] = t[j++]){
    ...
}

# 等同于

while ((s = t){
    s++;
    t++;
}
```
### 2.10 赋值运算与表达式
```
while ((c = getchar()) !=EOF)
```
在所有的这类表达式中，赋值表达式的类型是它的左操作数的类型，其值是赋值操作完
成后的值

### 2.12 运算符优先级与求值次序
- [C Operator Precedence](http://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/c/language/operator_precedence.html)

在任何一种编程语言中，如果代码的执行结果与求值顺序相关，则都是不好的程序设计
风格。很自然，有必要了解哪些问题需要避免，但是，如果不知道这些问题在各种机器上是如何解决的，就最好不要尝试运用某种特殊的实现方式。

## 第四章 函数与程序结构
### 4.1 函数的基本知识
函数定义的形式：
```
返回值类型 函数名（参数声明）{
    声明和语句
    return 表达式;
}

# 函数定义中的各构成部分都可以省略，最简单的函数
dunmy() { }
# 该函数不执行任何操作，也不返回任何值（有时很有用，它可以在程序开发(dev)期间用以保留位置）
# 如果省略了返回值类型，则默认是int
# gcc中，定义为void的函数的return值不能赋值给其他变量
# 定义为int但return ；没有表达式的函数，默认return 0
```
不同的系统、编译器中的编译加载机制略有差别
```
unix中：
cc main.c getline.c strindex.c      
// 生成目标代码main.o getline.o strindex.o,
// 然后把这三个文件一起加载到可执行文件a.out

// 重新(只)编译main.c
cc main.c getline.o strindex.o      
```
### 4.2 返回非整形值的函数
```
double
void
...

```
### 4.3 外部变量
```
external: 定义在函数外部的变量，及函数本身就是"外部的"
internal: 指的是定义在函数内部的参数、变量等

external变量可以在文件作用域全局访问，相当于全局变量

```
### 4.4 作用域规则
- 变量、函数必须先定义才可以使用
- 来自其他文件的外部变量需要使用extern关键字来访问
- 函数不需要使用extern访问，直接用函数名调用
- 一个外部变量只在一个文件中定义一次，即可在引用链中所有文件内使用external访问，外部变量的初始化只能出现在其定义的时候，定义外部变量的源文件也可以包含对该外部变量的external申明。
```
// file1主文件
#include <stdio.h>
#include "file2.c"

extern int a;           // 使用external访问到file2定义的外部变量
int main(){
    printf("number is %d",a);
}

// file2
int a=1;
```

### 4.5 头文件
- [gcc include syntax](https://gcc.gnu.org/onlinedocs/gcc-3.0.1/cpp_2.html)
```
#include <stdio.h>      // 引入标准库中的头文件

#include "myh.h"        // 引入自己写的头文件
// #include "myh.c"        // 强烈不建议引入c文件，所有都应该在头文件里面定义然后引入头文件

// myh.h中的定义函数可以直接在此进行调用（因为函数都是外部变量）
// 定义的变量需要使用 external 先申明再调用
```
- 将单个文件通过头文件模块化拆分

`main.c`
```
#include <stdio.h>
#include "util.h"

int main(){
    someutil()
}
```

`util.h`
```
#ifndef test_head           // 使用条件使得头文件只会引入一次
#define test_head           // test_head可以任取为体现头文件特性的名字
void someutil();
#endif

or                          // 多平台兼容的头文件

#if SYSTEM_1
# include "system_1.h"
#elif SYSTEM_2
# include "system_2.h"
#elif SYSTEM_3
...
#endif
```

`util.c`
```
#include <stdio.h>
void someutil(){
    // 头文件中someutil函数的具体实现
}
```
编译
```
# shell中
gcc main.c util.c

# vscode中，将编译task的参数改为:
"command": "/usr/bin/gcc",
"args": [
    "-g",
    "${fileDirname}/*.c",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}",
    "-lm"
]

(总之就是要把所有用到的c文件都编译,且只通过头文件引入util)
```
在编译时，util.c中的函数（作为外部变量）可以被头文件访问到（应该是头文件的机制），而在main.c中因为引入了util.h即可访问到其函数，头文件通过这种方式将各个文件的函数与main.c文件联系起来了(在编译时通过Linker将头文件util.h和util.c链接起来 [**C header files and compilation/linking**](https://stackoverflow.com/questions/18548157/c-header-files-and-compilation-linking)



### 4.6 静态变量
- **函数内部的static变量**，一直存在与内存中，不会随着函数调用完成而销毁
```
int testStatic(){
    int a=1;
    static int sa=1;
    a++
    sa++;
    printf("a: %d, sa: %d",a,sa)
}

int main(){
    for(int i;i<5;i++){
        testStatic();
    }
}

// result:
a: 2, sa: 2 
a: 2, sa: 3 
a: 2, sa: 4 
a: 2, sa: 5 
a: 2, sa: 6 
// a会在每次调用时进行初始化，所以一直输出的是2
// static 静态变量sa的值会存在内存中，只初始化一次，之后读取内存中的值，知道程序结束才销毁（而不是调用结束销毁）
// 函数内部的非static变量称为自动变量(因为其在每次调用时候初始化，调用结束自动销毁)
```
- **函数外部的static**，static变量 static函数，(static使变量)作用域只在定义的源文件中(其他文件不可调用访问源文件的static变量和函数)

使用static关键字申明变量和函数后，对静态变量的操作只在申明的源文件作用域有效
```
static int a=1;
static void hello(){
    printf("Hello Static");
}
```

### 4.7 寄存器变量
`register`
`register`声明告诉编译器，他所声明的变量在程序中使用频率较高。
其思想将register变量放在机器的寄存器中，这样可以使得程序更小，执行速度更快（但编译器可以忽略此选项）
```
register int x=1;
register char c;

# 实际使用中，硬件对寄存器变量的使用会有一些限制。
# 每个函数只有很少的变量可以保存在寄存器中
# 不过过量声明寄存器变量并不会有什么害处，因为编译器可以忽略过量或不支持的寄存器变量声明
# 另外无论寄存器变量是否实际存储在寄存器中（可能被编译器忽略），它的地址都是不可访问的
```
### 4.8 程序块结构（块级作用域）
```
int x；
int y;

f(double x){
    double y;
}
# 函数f内部的变量x引用的是函数的参数，类型为double，
# 而在函数f外，x是int类型的外部变量
# y也如此
# 实际编码中应该避免函数变量名和外部变量重名，因为可能引起混乱和错误
```
### 4.9 （变量的）初始化
外部变量和静态变量：
- 初始化表达式必须是常量表达式
- 且只初始化一次（在程序开始执行前进行初始化）

自动变量和寄存器变量：
- 每次进入函数或程序时候都会初始化
- 初始化表达式可以不是常量，可以是一个计算的值，函数return值等
- （自动变量的初始化等效于简写的赋值语句）

数组和字符的初始化比较特殊：
```
需要结合第五章指针和数组来理解
# 数组初始化两种方式
int arr[]={1,2,3};
int arr[MAXLENGTH];

# 字符串初始化
char pattern[] = "ould";
char pattern[] = { 'o', 'u', 'l', 'd'};
# 都会自动在字符串结尾加上\o
```

### 4.10 递归


### 4.11 C预处理器
- `#include`指令，在编译期间把指定文件内容包含进当前文件中
- `#define`指令，用任意字符序列替代一个标记

`#include`
```
#include <文件名>   //从系统标准库中查找
#include ”文件名“   //从指定路径中查找

#include在编译时该行会被替换为由文件名指定的文件的内容
加载如<stdio.h>等头文件与编译器的实现有关，略有差异
```

`#define`宏替换
```
#define 名字 替换文本

//eg:
#define forerver for(;;)   
//该语句为无限循环定义了一个新名字forever

#define max(A,B) ( (A) > (B) ? (A) : (B))
//宏替换也可以带参数，可以对不同的宏调用使用不同的替换文本

//计算数组长度
#define GETLEN(x) (sizeof(x) / sizeof((x)[0]))

##的嵌套使用规则,比较难以掌握,感觉用的也不多，略
```
`条件包含`
```
#if !defined(宏名字)
#define 宏名字
/* 宏内容 */
#endif

#if SYSTEM == SYSV 
#define HDR "sysv.h" 
#elif SYSTEM == BSD 
#define HDR "bsd.h" 
#elif SYSTEM == MSDOS 
#define HDR "msdos.h" 
#else 
#define HDR "default.h" 
#endif 
#include HDR 

// #ifdeg  #ifndef
#ifndef HDR 
#define EDR 
/* hdr.h 文件的内容放在这里 */ 
#endif 

#ifdef HDR 
#define EDR 
/* hdr.h 文件的内容放在这里 */ 
#endif 
```

## 第五章 指针与数组
### 5.3 指针与数组
通过数组下标所能完成的任何操作都可以通过指针来实现。一般来说，用指针编写的程序比用数组下标编写的程序执行速度快，但另一方面，用指针实现的程序理解起来稍微困难一些。

理解指针与数组
```
int a[10];       # 声明一个10个元素的数组
                 # 实际上定义了10个对象组成的集合，这10个对象存储在相邻的内存区域中，名字分别为a[0]、a[1]...a[9]
                 # a[i]表示该数组的第i个元素

int *pa;         # 申明了一个指向整型对象的指针
pa=&a[0];        # 将指针pa指向了数组a的第0个元素（的内存地址）

int x= *pa;       # 将数组a[0]的内容复制到了变量x中
                
                 # 由于pa指向了数组的第0个元素（的内存地址），而数组中元素在内存中又是相邻存储的
                 # 所以pa+1指向了数组的第一个元素(的内存地址)
                 # 同样的pa+i指向了数组的第i个元素（的内存地址）
                 # *(pa+1)引用的是a[1]的内容，*(pa+i)引用a[i]的内容       
                 # 取数组长度
                 # int a[17];
                 # int n = (int)sizeof(a)/sizeof(a[0]); 
                 # 该表达式不能写成函数，只能写成宏（因为数组作为参数传递的是指针，其return的值则是指针的size）

# 正确的使用姿势： 
#define GETLEN(x)  (sizeof(x) / sizeof((x)[0]))

```
数组下标与指针
>**数组名所代表的就是该数组最开始的一个元素的地址**
```
pa=&a[0];       # 根据定义，数组类型的变量或表达式的值
                # 是该数组第 0 个元素的地址
                # 即a指向a[0]元素（的内存地址）
                # 所以上操作后， pa和a具有相同的地址，
                # 所以赋值操作也可以写成：
pa=a;                
                # 对于数组元素a[i]的引用也可以写成*(a+i)
                # 而且实际上使用a[i]时，C语言会先将其转换为*(a+i)再进行求值
                # 相应地，如果 pa 是个指针，那么，在表达式中也可以在它的后面加下标。 
                # pa[i]与*(pa+i)是等价的。
                
                # 另，注意&a 、a 、&a[0] 的区别
                # a指向了a[0]的地址，和&a[0]是等价的
                # 而&a指向了数组的首地址
                # &a 、a 、&a[0]三者地址等价，但是
                # &a+1 ！= （a+1） == （&a[1]）
                # a+1和&a[1]都是：首地址+sizeof(数组元素类型)
                # 而&a+1： 首地址+数组长度*sizeof(数组元素类型)

                # 结论：a 和 &a[0]可以用，&a慎重用（最好别用）

# 数组名和指针之间有一个不同之处，指针是一个变量，数组名是一个内存地址
# 因此，在 C语言中，语句 pa=a 和 pa++都是合法的。
# 但数组名不是变量，因此，类似于 a=pa 和 a++形式的语句是非法的

# 当把数组名传递给一个函数时，实际上传递的是该数组第一个元索的地址。在被调用函数中，该参数是一个局部变量，
# 因此，数组名参数必须是一个指针，也就是一个存储地址值的变量。
```
### 5.4 地址算术运算
+
-
比较

### 5.5 字符指针与函数
**字符串常量**是一个字符数组，例如："I am a string"
在字符串的内部表示中，字符数组以空字符'\0'结尾。所以，程序可以通过检查空字符找到字符数组的结尾。字符串常量占据的存储单元数也因此比双引号内的字符数大 1。

字符串常量最常见的用法也许是作为函数参数，例如：
princf("hello, world\n"}; 

另一种是和指针相关的：
```
char *pmessage;
pmessage="now is the time";       

# 这个操作会把一个指向该字符串数组（字符串常量）
# 的指针赋值给pmessage指针
```
关于字符串的标准库`<string.h>`

**两种定义字符串的方式**：
```
char amessage[] = "nw is the time"; /* 定义一个数组 */ 
char *pmessage = "now is the time"; /* 定义一个指针。指向一个字符串常量 */ 

上述声明中，
amessage 是一个仅仅足以存放初始化字符串以及空字符'\0'的一维数组。
数组中的单个字符可以进行修改，但 amessage 始终指向同一个存储位置。

另一方面，pmessage是一个指针，其初值指向一个字符串常量，
之后它可以被修改以指向其它地址，
但如果试图修改字符串的内容，结果是没有定义的

思考：字符串常量可以修改吗？ 不可以
"hello world"
这是一个表达式，其值是一个内存地址，程序运行时，就会分配一块内存空间来存储，内容是个常量，（程序生命周期中）不可被更改。
而数组字符串参考数组的定义，是一样的，每一个字符是数组的一个成员

# 数组字符串，只能在初始化时候定义，不可重新赋值，但可以修改数组成员（每个字符为一个成员）
# 字符串常量，可以重新赋值，不可修改（字符串常量中个某个字符，因为其整体是个常量）

一般的
如果需要对字符中的某个字符进行修改，且要用指针去操作
则是先定义一个字符串数组，再用一个指针指向它：

char a[]="hellow pointer";
char *p=a  or char *p=&a[0]    # 根据数组名的定义，这两种操作是等价的
```
![](./assets/charPointerAndArrayInC.png)
**strcpoy**
```
/* strcpy: copy t to s*/ 
void strcpy(char *s, char *t) {
    while(*s++=*t++)
        ;
}
// useage
char s[]="sadasd";
chat t[]="zzadas";
strcpy(&s,&t)
```
**strcmp**
```
/* strcmp: 
    s<t, return <0
    s==t, return 0
    s>t, return >0
*/ 
void strcmp(char *s, char *t) {
    for(;*s==*t;s++,t++;){
        if(*s=="\0"){
            return 0;
        }        
    }
    return *s-*t
}
```
**进栈和出栈的标准用法**
```
*p++ = val; /* 将 val 压入栈 */ 
val = *--p; /* 将栈顶元素弹出到 val 中 */ 
```
**打印字符串的方式**
```
char arr[]="abc";
# 直接打印
printf("%s",arr);                   // 虽然arr指向a[0]
                                    // 但是使用%s打印会取到abc

# 用指针遍历
void printstr(char *str){
    while(*str){        
        printf("%c",*str);          // 注意是%c
        *str++;
    }
}
printstr(arr) or printstr(&arr[0])  // 两者等价
```
**注意！在C中单引号和双引号不是等价的**
```
'a'             # 声明了单个字符a
"a"             # 声明了字符串常量 a\o (自动加上了结尾标志\o)

```

### 5.6 指针数组以及指向指针的数组


```
int swap(char *v[]){

}

# 参数v是一个数组，里面存储的元素是一个个指针
```

### 5.7 多维数组

### 5.8 指针数组的初始化
### 5.9 指针与多维数组
### 5.10 命令行参数
### 5.11 指向函数的指针
### 5.12 复杂声明

## 第六章 结构 (struct)

### 6.1 结构的基本知识
```
# 声明struct
struct point{
    int x;
    int y;
}

# 使用struct定义变量

# 初值表定义，初值表必须是常量
struct point a={1,2}     

# 

# 使用变量
结构名.成员
a.x
a.y
```
### 6.7 typedef

### 6.8 union 联合