#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


int main() {
    std::ifstream dataFile("input.txt"); if(!dataFile) {std::cout << "Error opening file for reading!\n"; return 1;}
    
    std::unordered_map<std::string, int> word_map {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };

    const uint8_t min_w = 3; // min_world_length
    const uint8_t max_w = 5; // max_world_length
    
    uint32_t sum = 0;
    std::string line;

    while(std::getline(dataFile, line)) {
        std::vector<int> nums;
        
        uint8_t len = line.size();
        for (uint8_t i = 0; i < len; i++) {
            if(isdigit(line.at(i))) {
                nums.push_back(line.at(i) - '0');
                continue;
            }

            for (uint8_t j = min_w; (i + j) <= len && j <= max_w; j++) {
                if(word_map.find(line.substr(i, j)) != word_map.end()) {
                    nums.push_back(word_map.at(line.substr(i, j)));
                    break;
                }
            }
        }

        sum += nums.front() * 10 + nums.back();
    }

    std::cout << "SUM IS: "<< sum << std::endl;

    dataFile.close();
}