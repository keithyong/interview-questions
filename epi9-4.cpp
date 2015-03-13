#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

class Pair {
    public:
        Pair(char, int);
        char paren;
        int index;
};

Pair::Pair(char p, int i) {
    paren = p;
    index = i;
}

// Copy by value
void printStack(stack<Pair> s) {
    while (s.empty() == false) {
        cout << s.top().paren << " ";
        cout << s.top().index << endl;
        s.pop();
    }
}

string longestMatchingSubstring(string s) {
    // Resultant substring to return.
    string result;
    
    // Stack for paren completion
    stack<Pair> st;

    // Loop through the string
    string::iterator it;
    int count = 0;
    for (it = s.begin(); it != s.end(); it++, count++) {
        if (*it == '(') {
            st.push(Pair('(', count));
        }
        else if (*it == ')') {
            // If stack is not empty and the top is a '('...
            if (st.empty() == false && st.top().paren == '(') {
                st.pop();
            } else {
                st.push(Pair(')', count));
            }
        }
    }

    printStack(st);

    return result;
}

int main() {
    string test1 = "((())()(()(";
    string test2 = ")()())(())()()(())((";
    longestMatchingSubstring(test1);
    longestMatchingSubstring(test2);
}
