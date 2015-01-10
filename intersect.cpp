#include <vector>
#include <iostream>

#define ARR_1_SIZE  10
#define ARR_2_SIZE  4

using namespace std;

int main() {
    int arr1[ARR_1_SIZE] = {1, 2, 3, 4, 19, 29, 7, 9, 810, 10};
    int arr2[ARR_2_SIZE] = {1, 3, 293, 810};
    vector<int> intersect;

    /* For each element in arr1, compare it to arr 2. If
     * they are equal, then push them to the intersect array */
    for (int i = 0; i < ARR_1_SIZE; i++)
        for (int j = 0; j < ARR_2_SIZE; j++)
            if (arr1[i] == arr2[j])
                intersect.push_back(arr1[i]);

    cout << "Intersection Array: " << endl;
    for (int i = 0; i < intersect.size(); i++)
        cout << intersect[i] << " ";
    cout << endl;
}
