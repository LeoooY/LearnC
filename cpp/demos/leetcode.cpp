// regex_replace example
#include <iostream>
#include <iterator>
#include <regex>
#include <string>

int main() {
    using namespace std;
    string s("A man, a plan, a canal: Panama");
    regex e("\\W");
    string s_trim = regex_replace(s, e, "");

    if (s_trim.size() % 2 != 1) {
        return false;
    }

    int midIdx = s_trim.size() > 0 ? (s_trim.size() - 1) / 2 : s_trim.size();
    stack<string> strStack;
    for (int i = 0; i < midIdx; i++) {
        // cout << s_trim[i];
        strStack.push(to_string(s_trim[i]));
        // cout << s_trim[i];
    }
    for (int i = 0; i < midIdx; i++) {
        cout << strStack.pop();
    }
    // count << strStack;

    // cout << s_trim << s_trim.size();
    // cout << stack;

    return 0;
}