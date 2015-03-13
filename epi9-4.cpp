// EPI9-4
#include <iostream>
#include <string>
#include <stack>
#include <deque>

using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::deque;

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
void printStack(stack<Pair> st) {
    while (st.empty() == false) {
        cout << st.top().paren << " ";
        cout << st.top().index << endl;
        st.pop();
    }
}

void printDeque(const deque<int>& dq) {
    deque<int>::const_iterator it;
    for (it = dq.begin(); it != dq.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

// Convert a stack<Pair> to deque<int>.
deque<int> convertToIndexDeque(stack<Pair>& st) {
    deque<int> dq;
    while (st.empty() == false) {
        dq.push_front(st.top().index);
        st.pop();
    }
    printDeque(dq);
    return dq;
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
    deque<int> nonMatches = convertToIndexDeque(st);

    
    return result;
}

int main() {
    string test1 = "((())()(()(";
    string test2 = ")()())(())()()(())((";
    longestMatchingSubstring(test1);
    longestMatchingSubstring(test2);
}
