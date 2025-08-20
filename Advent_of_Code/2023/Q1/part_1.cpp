#include <iostream>
#include <fstream>
#include <map>
#include <string>

#define LOG(x) cout << x << endl


int main() {
    std::ifstream dataFile("input.txt"); if(!dataFile) {std::cout << "Error opening file for reading!\n"; return 1;}
    
    uint16_t sum = 0;

    std::string line;
    while(std::getline(dataFile, line)) {
        // Find first number
        for (auto it = line.cbegin(); it != line.cend(); ++it)
            if(isdigit(*it)) {sum += (*it - '0') * 10; break;}
        
        // Find last number
        for (auto it = line.crbegin(); it != line.crend(); ++it)
            if(isdigit(*it)) {sum += (*it - '0'); break;}
    }

    std::cout << "SUM IS: "<< sum << std::endl;

    dataFile.close();
}