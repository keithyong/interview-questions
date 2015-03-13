#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

string longestMatchingSubstring(string s) {
    // Resultant substring to return.
    string result;

    // Loop through the string
    string::iterator it;
    int count = 0;
    for (it = s.begin(); it != s.end(); it++, count++) {
        cout << *it << count;
    }

    return result;
}

int main() {
    string test1 = "((())()(()(";
    cout << longestMatchingSubstring(test1);
}
