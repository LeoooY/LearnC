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
const c=0;

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

### 循环 Fhile Loop
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
指针是一个int 类型的变量，指向其`value`在内存中的`地址`,而不是直接将值存储在变量中。
（简言之，指针是一个指向内存地址的变量，变量的值存储在其指向的内存地址中）

操作符
- `*` 定义指针
- `&` 指向变量
- `*varName` 使用指针

### （对象）结构 Structures
C structures are special, large variables which contain several named variables inside.

结构是C语言中`Objects`对象和`Class`类的基础

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
```
### `按值传递` 和 `按址(引用)传递`函数参数 Function arguments by reference


- 按址传递（传递一个指针），会将指针本身改变，（参考Js引用类型，Array,Object,Function...）
- 按值传递，传递了变量值的一个拷贝，不会改变原变量.

```
void move(point * p) {
    (*p).x++;
    (*p).y++;
}

// is equal to

void move(point * p) {
    p->x++;
    p->y++;
}
```

### 动态内存分配 Dynamic allocation
- ->  访问struct属性
- malloc() 按需分配内存
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

