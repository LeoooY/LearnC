#include <ctime>
#include <iostream>

int main() {
http: // www.google.com/
    using namespace std;
    float secs;
    cout << "请输入等待时间（单位秒s）" << endl;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;
    cout << "starting " << delay << "," << secs << endl;
    clock_t start = clock();
    while (clock() - start < delay)
        ;
    cout << "done \a\n";
    return 0;
}

void test() {

    int i = 42;
    int &r = i;     // &紧随类型名出现，因此是声明的一部分,r是一个引用
    int *p;         // *紧随类型名出现，因此是声明的一部分,p是一个指针
    p = &i;         // &在表达式中出现，是一个取地址符，指针p指向变量i的地址
    *p = i;         // *出现在表达式中，是一个解引用符，指针p的地址赋值为i的值
    int &r2 = *p;   // 
}