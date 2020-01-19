#include <iostream>
#include <climits>

int main(){
    using namespace std;
    int n_int=INT_MAX;              // 从climits中引入的 最大int值
    short n_short=SHRT_MAX;         // 下同
    long n_long=LONG_MIN;           
    long long n_llong =LLONG_MAX; 

    cout << "int is "  << sizeof LONG_MIN << " bytes" << endl;
    cout << "int: "  << CHAR_BIT << endl;
    cout << "Hello Wolrd\n";
    return 0;
}
