#include <string>
#include <iostream>

using std::string;
using std::cout;

int main() {
    string s = "hello";
    string p = "((())()(()(";
    cout << p.substr(1, 7);
}
