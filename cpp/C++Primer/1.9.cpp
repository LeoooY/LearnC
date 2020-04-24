#include <iostream>

int main() {
    using namespace std;
    int i = 50, sum = 0;
    while (i <= 100) {
        sum += i;
        i++;
    }
    cout << "sum of 50 to 100: " << sum << endl;
    return 0;
}
