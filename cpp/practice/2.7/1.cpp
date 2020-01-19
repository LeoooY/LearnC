/* 
    编写一个C++程序，它显示您的姓名和地址
 */

#include <iostream>

void printInfo(){
    using namespace std;
    char name[20];
    char addr[20];
    cout << "请输入您的名字：\n";
    cin >> name;
    cout << "请输入您的地址：\n";
    cin >> addr;
    cout << "您好，" << name << ", 您的地址是："  << addr;
}

void printTime(){
    using namespace std;
    int hour;
    int minute;
    cout << "Enter the number of hours:" << endl;
    cin >> hour;
    cout << "Enter the number of minute" << endl;
    cin >> minute;
    cout << "Time:" << hour << ":" << minute << endl;
}

void printPointer(){
    using namespace std;
    int donuts=6;
    double cups=4.5;
    cout << "内存地址: "  << &donuts << " 值：" << donuts << endl;
}

int main(){
    using namespace std;
    // printTime();
    // printInfo();
    printPointer();
    return 0;
}
