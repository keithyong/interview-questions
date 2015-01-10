#include <stdio.h>

#define ARR_1_SIZE      10
#define ARR_2_SIZE      5

int arr1[ARR_1_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr2[ARR_2_SIZE] = {4, 5, 7, 8, 19};
int *intersection;

int push_back(int *arr, int toAdd) {
    while (*arr++);
    arr = &toAdd;
}
int main() {
    /* For each element in arr1, compare it to every
     * element in arr 2 */
    for (int i = 1; i < ARR_1_SIZE; i++)
        for (int j = 0; j < ARR_2_SIZE; j++)
            if (arr1[i] == arr2[j]) {
                push_back
            }

}
