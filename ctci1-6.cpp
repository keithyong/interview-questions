// Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
#include <iostream>
#include <vector>
#include <sstream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
static const int MAX_LINE_SIZE = 300;

// http://stackoverflow.com/a/236803
vector<string> &split(const string &s, char delim, vector<string> &elements) {
    elements.clear();
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elements.push_back(item);
    }
    return elements;
}

void print2DVector(const vector<vector<string> > &vec) {
    vector<vector<string> >::const_iterator row_it;
    vector<string>::const_iterator col_it;

    for (row_it = vec.begin(); row_it != vec.end(); row_it++) {
        for (col_it = row_it->begin(); col_it != row_it->end(); col_it++) {
            cout << *col_it << " ";
        }
        cout << endl;
    }
}
int main () {
    vector<vector<string> > img;
    string line;
    string c;
    vector<string> split_strings;
    int line_no = 0;
    while (getline(cin, line)) {
        line_no++;
        split_strings = split(line, ' ', split_strings);
        img.push_back(split_strings);
    }

    // Error checking to see if correct input
    vector<vector<string> >::iterator row_it;
    vector<string>::iterator col_it;
    vector<string>::size_type n = img.size();
    for (row_it = img.begin(); row_it != img.end(); row_it++) {
        if (row_it->size() != n) {
            cout << "Invalid matrix!" << endl;
            return 0;
        }
    }

    if (n == 1) {
        cout << img[1][1] << endl;
        return 0;
    } else {
        string tmp;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = i, nmx = n - 1; j < nmx - i; j++) {
                // nmx because array starts at zero, not at one
                // like the matrix does in reality.
                
                // TL - img[i][j]
                // TR - img[j][nmx - i]
                // BR - img[nmx - i][nmx - j] 
                // BL - img[nmx - j][i]
                
                // Save top left corner value
                tmp = img[i][j];

                // Replace TL with BL
                img[i][j] = img[nmx - j][i];

                // Replace BL with BR
                img[nmx - j][i] = img[nmx - i][nmx - j];

                // Replace BR with TR
                img[nmx - i][nmx - j] = img[j][nmx - i];

                // Replace TR with tmp
                img[j][nmx - i] = tmp;
            }
        }
        
        print2DVector(img);
    }
}


adsjfiojads;fljzcxkl;vnoewfnmasdh vihdsla
