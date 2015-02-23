#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::cout;
using std::endl;

int getInt(const char &c) {
    return c - '0';
}

void printVector(vector<string> S) {
    vector<string>::iterator it;
    for (it = S.begin(); it != S.end(); it++) {
        cout << *it << " ";
    }
}

void push_front(string &str, char c) {
    str.insert(0, 1, c);
}
//=====================================
vector<string> mult(string s1, string s2, bool &isNeg) {
    isNeg = false;
    if (s1[0] == '-' && s2[0] != '-') {
        isNeg = true;
        s1.erase(0, 1);
    }
    else if (s2[0] == '-' && s1[0] != '-') {
        isNeg = true;
        s2.erase(0, 1);
    }
    else if (s1[0] == '-' && s2[0] == '-') {
        s1.erase(0,1);
        s2.erase(0,1);
    }
    vector<string> R;
    string bigger;
    string smaller;
    if (s1.length() > s2.length()){
        bigger = s1;
        smaller = s2;
    }
    else {
        bigger = s2;
        smaller = s1;
    }
    string::reverse_iterator sm_it;
    string::reverse_iterator bg_it;
    int count = 0;
    for (sm_it = smaller.rbegin(); sm_it != smaller.rend(); sm_it++) {
        string result = "";
        result.insert(0, count, '0');
        int carry = 0;
        int x = 0;
        int a = 0;
        for (bg_it = bigger.rbegin(); bg_it != bigger.rend(); bg_it++) {
            x = getInt(*sm_it) * getInt(*bg_it);
            x = x + carry;
            a = x % 10;
            carry = (x - a) / 10;
            push_front(result, a + '0');
            if (bg_it== bigger.rend() - 1 && carry != 0){
                push_front(result, carry + '0');
            } 
        }
        count++;
        R.push_back(result);
    }
    
    return R;
}


/* Sums up all bigint-strings in vector */
string sum(vector<string> &A, bool isNeg) {
    vector<string>::size_type A_size = A.size();
    string::size_type max_strlen = 0;
    vector<string>::iterator A_it;

    /* Find max strlen */
    for (A_it = A.begin(); A_it != A.end(); A_it++) {
        if (max_strlen < (*A_it).length()) {
            max_strlen = (*A_it).length();
        }
    }
    /* Append 0's for each string */
    for (A_it = A.begin(); A_it != A.end(); A_it++) {
        /* push_front zeros to each string until all are same length*/
        (*A_it).insert(0, max_strlen - (*A_it).length(), '0');
    }

    int carry, x, a;
    carry = x = a = 0;
    string result = "";

    for (int i = max_strlen - 1; i >= 0; i--) {
        vector<string>::iterator it;
        x = 0;
        x += carry;
        for (it =A.begin(); it != A.end();it++ ){
            x+= getInt((*it)[i]);
        } 
        a = x % 10;
        carry = (x - a) / 10;
        push_front(result, a + '0');
        if (i == 0 && carry != 0) {
            push_front(result, carry + '0');
        }
    }
    
    if (isNeg) 
        push_front(result, '-');
    return result;
}


int main() {
    vector<string> my_A;
    bool neg;
    my_A = mult("211333333333333333333333333333333311111111111", "2133333333333333312222222222444444444444444444444422222222222222233333333333333333333333333377777777777777777777777777", neg);
    cout << sum(my_A, neg) << endl;
}
