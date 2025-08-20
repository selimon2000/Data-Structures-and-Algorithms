#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdint>
#include <array>

using namespace std;


bool isValid(const array<string, 140>& lines, uint8_t l_n, uint8_t l, uint8_t r, const uint8_t& n_lines, const uint8_t& width) {
    // Check all positions from l to r
    for (uint8_t col = l; col <= r; ++col) {
        // Check above
        if (l_n > 0) {
            for (uint8_t i = max(0, col - 1); i <= min(width - 1, col + 1); ++i) {
                if (lines[l_n - 1][i] != '.') return true;
            }
        }
        
        // Check below
        if (l_n < n_lines - 1) {
            for (uint8_t i = max(0, col - 1); i <= min(width - 1, col + 1); ++i) {
                if (lines[l_n + 1][i] != '.') return true;
            }
        }
    }
    
    // Check left
    if (l > 0) {
        if (lines[l_n][l - 1] != '.') return true;
    }
    // Check right
    if (r < width - 1) {
        if (lines[l_n][r + 1] != '.') return true;
    }
    

    return false;
}


uint32_t firstProblem(const array<string, 140>& lines) {
    uint8_t n_lines = lines.size() * 1;
    uint8_t width = lines.at(0).size();
    uint32_t total = 0;

    for (uint8_t i = 0; i < n_lines; ++i) {

        uint32_t num = 0; // Doesn't have to be this big, but might aswell
        bool num_found = false;
        string str_num;

        uint8_t l = 0;

        for (uint8_t j = 0; j < width; ++j) {

            while (isdigit(lines[i][j])) {
                str_num += lines[i][j];
                if(!num_found) {
                    num_found = true;
                    l = j;
                }
                ++j;
            }

            if (num_found) {
                num_found = false;
                if(isValid(lines, i, l, j - 1, n_lines, width))
                    total += stoul(str_num);
                
                str_num.clear();
            }
        }
    }


    return total;
}


int main() {
    ifstream my_file("data.txt");
    if (!my_file) {
        cout << "ERROR!\tFILE CANNOT BE OPENED" << endl;
        return 1;
    }
    
    string line;
    array<string, 140> lines;

    for (uint8_t index = 0; getline(my_file, line) && index < lines.size(); ++index)
        lines[index] = line;

    cout << "First Problem: " << firstProblem(lines) << endl;
}