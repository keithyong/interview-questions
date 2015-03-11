// EPI9-3 Test if parens, brackets, and braces are matched.
// Empty string is matched.
#include <string>
#include <stack>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stack;

bool isMatched(string s) {
    bool isMatched = false;
    if (s == "") {
        isMatched = true;
    } else {
        stack<char> parens;
        stack<char> brackets;
        stack<char> braces;
        
        char c;
        string::iterator s_it;
        for (s_it = s.begin(); s_it != s.end(); s_it++) {
            c = *s_it;
            if (c == '(')
                parens.push(0);
            else if (c == ')')
                parens.pop();
            else if (c == '[')
                brackets.push(0);
            else if (c == ']')
                brackets.pop();
            else if (c == '{')
                brackets.push(0);
            else if (c == '}')
                brackets.pop();
        }

        if (parens.empty() && brackets.empty() && braces.empty())
            isMatched = true;
    }
    return isMatched;
}

int main() {
    cout << "Enter a string: ";
    string input_str;
    cin >> input_str;
    cout << isMatched(input_str);
}
