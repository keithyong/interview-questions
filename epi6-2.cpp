// EPI 6-2 Write a function which takes as input an array A of digits encoding a decimal number D and updates A to represent the number D + 1. For example, if A = {1, 2, 9} then you should update A to {1, 3, 0}.
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
vector<int> push_front(vector<int> &A, int newnum) {
    vector<int> newvec;
    newvec.push_back(newnum);
    for (int i = 0; i < A.size(); i++) {
        newvec.push_back(A[i]);
    }
    return newvec;
}
void printVector(const vector<int> &A) {
    vector<int>::const_iterator it = A.begin();
    for (; it != A.end(); it++) {
        cout << *it << " ";
    }
}
void plusOne(vector<int> &A, int end) {
    if (A[end] == 9) {
        if (end == 0) {
            A[end] = 0;
            A = push_front(A, 1);
        } else {
            A[end] = 0;
            plusOne(A, end - 1);
        }
    } else {
        A[end]++;
    }
}

int main() {
    vector<int> my_A;
    for (int i = 0; i < 1; i++) {
        my_A.push_back(1);
    }
    plusOne(my_A, my_A.size() - 1);
    printVector(my_A);
}
