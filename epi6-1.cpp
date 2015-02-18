// EPI 6.1 Write a function that takes an array A of length n and an index i into A, and rearranges the elements such that all elements less than A[i] appear first, followed by elements equal to A[i], followed by elements greater than A[i]. Your algorithm should have O(1) space complexity and O(n) time complexity.
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &V) {
    for (vector<int>::iterator it = V.begin(); it != V.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void swap(vector<int> &arr, int a, int b) {
    cout << "Swapping " << arr[a] << " with " << arr[b] << endl;
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    printVector(arr);
}

void reorder(vector<int> &arr, int pivot) {
    vector<int>::iterator it = arr.begin();
    int pivot_val = arr[pivot];
    int pivot_pos;
    int greater_pos;
    int s1, s2, s3;
    s1 = s2 = s3 = 0;

    int arr_size = 0;
    for (; it != arr.end(); it++) {
        if (*it < pivot_val) {
            s1++;
        }
        else if (*it == pivot_val) {
            s2++;
        } else {
            s3++;
        }
        arr_size++;
    }
    
    s2--;
    pivot_pos = s1 + s2;
    greater_pos = pivot_pos + s3;
    swap(arr, pivot_pos, pivot);
    pivot_pos--;

    for (int i = 0; i <= pivot_pos;) {
        if (pivot_val < arr[i]) {
            cout << arr[i] << " is greater than " << pivot_val << " - ";
            swap(arr, i, greater_pos);
            greater_pos--;
        }
        else if (arr[i] == pivot_val) {
            swap(arr, i, pivot_pos);
            pivot_pos--;
        }
        else {
            cout << "Correct position" << endl;
            i++;
        }
    }
}

int main() {
    vector<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(8);
    a.push_back(8);
    a.push_back(5);
    a.push_back(1);
    a.push_back(5);
    a.push_back(7);
    a.push_back(4);
    a.push_back(3);
    a.push_back(7);
    a.push_back(9);
    reorder(a, 6);

}
