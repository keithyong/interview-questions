#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> V) {
    for (vector<int>::iterator it = V.begin(); it != V.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}

bool checkSoln(vector<int> A, vector<int> S) {
    vector<int>::iterator it;
    int i = 0;
    int sum = 0;

    for (it = S.begin(); it != S.end(); it++) {
        if (A[i] < *it) {
            return false;
        }
        i += *it;
    }
    if (i == A.size() - 1) {
        return true;
    } else {
        return false;
    }

}

vector<int> makeCandidates(const vector<int> &A, int k) {
    vector<int> candidates;
    vector<int>::const_iterator it;
    if (A.size() <= k) {
        return candidates;
    }
    for (int i = 1; i <= A[k]; i++) {
        candidates.push_back(k + i);
    }

    return candidates;
}
bool solve(const vector<int> &A, vector<int> &S, int pos) {
    printVector(S);
    bool solnFound = checkSoln(A, S);
    if (solnFound) {
        cout << "SOLUTION FOUND : ";
        printVector(S);
        return true;
    } else {
        vector<int> candidates = makeCandidates(A, pos);
        vector<int>::iterator it;
        for (it = candidates.begin(); it != candidates.end(); it++) {
            S.push_back(*it - pos);
            printVector(S);
            solve(A, S, *it);
        }
        S.erase(S.end() - 1);
        printVector(S);
        return false;
    }
}

int main() {
    vector<int> myA;
    myA.push_back(3);
    myA.push_back(3);
    myA.push_back(1);
    myA.push_back(0);
    myA.push_back(2);
    myA.push_back(0);
    myA.push_back(1);
    vector<int> mySoln;
    cout << solve(myA, mySoln, 0);
}
