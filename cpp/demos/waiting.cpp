#include <iostream>
#include <ctime>

int main(){
    http://www.google.com/
    using namespace std;
    float secs;
    cout << "请输入等待时间（单位秒s）"<< endl;
    cin >> secs;
    clock_t delay=secs* CLOCKS_PER_SEC;
    cout << "starting " << delay << "," << secs << endl;
    clock_t start =clock();
    while(clock()-start<delay)
        ;
    cout << "done \a\n";
    return 0;
}
