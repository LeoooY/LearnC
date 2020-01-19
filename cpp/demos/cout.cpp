#include <iostream>

int main() {
    using namespace std;
    int count;
    cout << "How many carrots do you have?" << endl;
    cin >> count;
    cout << "Here are two More." << endl;
    count = count + 2;
    cout << "Now you Have " << count << " carrots." << endl;
    return 0;
}
