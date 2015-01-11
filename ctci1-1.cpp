/* 1.1 Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures? 
 *
 * Soln. For each character, check if it has already been detected. Use a hash map. */

#include <unordered_map>
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: ./a.out [string]" << endl;
    } else {
        char *str = argv[1];

        /* O(1) insert time */
        unordered_map<char, bool> m;
        
        /* Go through each char in the string */
        for (; *str; str++) {
            /* map.find is O(1) in average, O(n) worse case */
            if (m[*str] == 1) {
                cout << "Not all unique characters!" << endl;
                return 0;
            } else {
                m[*str] = true;
            }
        }

        cout << "Yes, all unique characters!" << endl;
        return 1;
    }
}
