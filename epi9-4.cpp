// EPI9-4 Write a function that takes as input a string s made up of the characters '(' and ')', and returns a maximum length substring of s in which the parens are matched.
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
    string::iterator str_it;
    int count = 0;
    for (str_it = s.begin(); str_it != s.end(); str_it++, count++) {
        if (*str_it == '(') {
            st.push(Pair('(', count));
        }
        else if (*str_it == ')') {
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
    deque<string> matches;
    // Grabs all the substrings between every two nonMatches integers
    // and adds it to matches array.
    for (int i = 0; i < nonMatches.size() - 1; i++) {
        int range1 = nonMatches[i] + 1;
        int substr_count = nonMatches[i + 1] - range1;
        matches.push_front(s.substr(range1, substr_count));
    }

    deque<string>::iterator dq_it;
    int maxlen = -1;
    int currlen;
    for (dq_it = matches.begin(); dq_it != matches.end(); dq_it++) {
        currlen = (*dq_it).length();
        if (maxlen < currlen) {
            maxlen = currlen;
            result = *dq_it;
        }
    }

    return result;
}

int main() {
    string test1 = "((())()(()(";
    string test2 = ")()())(())()()(())((";
    cout << longestMatchingSubstring(test1) << endl;
    cout << longestMatchingSubstring(test2) << endl;
}
