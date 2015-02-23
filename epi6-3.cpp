#include <string>
#include <vector>
#include <iostream>
#include <chrono>
using std::string;
using std::vector;
using std::cout;
using std::endl;

/* O(1) */
int getInt(const char &c) {
    return c - '0';
}

void push_front(string &str, char c) {
    str.insert(0, 1, c);
}

void printVector(vector<string> S) {
    vector<string>::iterator it;
    for (it = S.begin(); it != S.end(); it++) {
        cout << *it << " ";
    }
}

/* Grade school multiplication, except it doesn't sum the results,
 * just returns a vector<string> that needs to be summed. */
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
            if (bg_it == bigger.rend() - 1 && carry != 0){
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
            x += getInt((*it)[i]);
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

/* Combining mult + sum */
string multiply(string s1, string s2) {
    string result;
    bool neg;
    vector<string> A;
    A = mult(s1, s2, neg);
    result = sum(A, neg);
    return result;
}


int main() {
    const auto start_time = std::chrono::steady_clock::now();
    cout << multiply("4589438593845983945893485938495893485982934859829348592843958928349582943589284359829438592849582945839127387128378127845832678568745624987435692837465928736459872364957826349587629348756923847569283475692384756927438569278345692876345", "12938912839189489452734857209834750298347502983475736285927460192634017634017250194755108475017894750298374053847503984573328349823948928349289849283409180298417465298374659287436598273465982763495872634756734657637567365763576375637657") << endl;
    double time_in_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() / 1000.0;
    cout << "Executed in " << time_in_seconds << " seconds." << endl;
}
