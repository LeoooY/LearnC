#include <iostream>

int main() {
    using namespace std;
    // cout << "Hello Wolrd\n";
    int val = 0;
    int &refVal = val; // 声明并初始化引用
    int *pVal = &val;  // 声明并初始化指针
    int *pVal2 = &refVal;   // 当指针取引用的地址时候，实际上取到的refVal引用的变量，即&refVal 等价于 &val
    cout << *pVal << *pVal2 << refVal << endl;


    int i = 42;
    // int &r = i;     // &紧随类型名出现，因此是声明的一部分,r是一个引用
    int *p;         // *紧随类型名出现，因此是声明的一部分,p是一个指针
    p = &i;         // &在表达式中出现，是一个取地址符，指针p指向变量i的地址
    *p = i;         // *出现在表达式中，是一个解引用符，指针p的地址赋值为i的值
    int &r2 = *p;   // &是声明的一部分，*是一个解引用符，引用rs绑定到*p解引用的结果i上，等价于 int &r2=i;
    bool rs= bool(*p == i); // true    
    cout << r2 << " " << rs;
    return 0;
}
