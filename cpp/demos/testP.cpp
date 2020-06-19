#include <iostream>

int main() {
    using namespace std;
    // cout << "Hello Wolrd\n";
    int val = 0;
    int &refVal = val; // 声明并初始化引用
    int *pVal = &val;  // 声明并初始化指针
    int *pVal2 = &refVal;   // 当指针取引用的地址时候，实际上取到的refVal引用的变量，即&refVal 等价于 &val
    cout << *pVal << *pVal2 << refVal << endl;
    return 0;
}
