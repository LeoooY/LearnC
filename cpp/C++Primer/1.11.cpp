#include <iostream>

int main() {
    using namespace std;
    cout << "打印任意两个数字间的数，请输入两个数字:";
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    while (v1 != v2) {
        if (v1 > v2) {
            cout << v1-- << endl;
        } else {
            cout << v2-- << endl;
        }
    };
    cout << v1 << endl; // or v2,两个数字已经相等了
    return 0;
}
