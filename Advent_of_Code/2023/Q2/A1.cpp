#include <iostream>
#include <fstream>
#include <strstream>
#include <string_view>
#include <string>
#include <math.h>
#include <ctype.h>

using namespace std;


// Instead of converting to a string(which takes more memory and time) to use stoi,
// making my own function to do this with string_view
uint8_t str_view_num(string_view str) {
    uint8_t num = 0;
    uint8_t p = 0; // power

    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        if (isdigit(*it))
            num += (*it - '0') * pow(10, p);
        ++p;
    }
    return num;
}


void counter(string_view str, uint8_t &r, uint8_t &g, uint8_t &b) {
    size_t space_pos = str.find(" "); // finding where space is;
    uint8_t num = str_view_num(str.substr(0, space_pos));

    // RECALL: BALLS ARE PLACED BACK
    if(str.at(space_pos + 1) == 'r')        r = max(r, num);        
    else if (str.at(space_pos + 1) == 'g')  g = max(g, num); 
    else if (str.at(space_pos + 1) == 'b')  b = max(b, num); 
}


void subGameCount(string_view str, uint8_t &r, uint8_t &g, uint8_t &b) {
    // cout << endl << endl << str << endl;
    size_t  pos,
            start = 0;
    string delim{","};
    bool isNum = true; // is between a number; skipping second space

    while((pos = str.find(delim, start)) != string_view::npos) {
        string_view sub_g = str.substr(start, pos - start);
        counter(sub_g, r, g, b);

        start = pos + 2;
        isNum = !isNum;
    }
    std::string_view sub_g = str.substr(start, str.size()); // Last bit
    counter(sub_g, r, g, b);
}


uint8_t isGamePos(string_view str) {       
        const uint8_t   r_m = 12, // red max
                        g_m = 13,
                        b_m = 14;

        uint8_t r = 0,
                g = 0,
                b = 0;

        size_t start = str.find(":") + 2,
               pos = 0;
        string delim{";"};

        while((pos = str.find(delim, start)) != string_view::npos) {
            subGameCount(str.substr(start, pos - start), r, g, b);

            start = pos + 2; // delim.n + 1 extra space == 1
        }
        subGameCount(str.substr(start, str.size()), r, g, b);// Last bit

        if ((r > r_m) ||
            (g > g_m) ||
            (b > b_m))
            return 0;

        string_view game_num_str = str.substr(str.find(" ", 0), (str.find(":", 0) - str.find(" ", 0)));
        uint8_t game_num = str_view_num(game_num_str);

        return game_num;       
}


int main() {
    std::ifstream inFile("data.txt"); if(!inFile) {std::cout << "Error opening file for reading!\n"; return 1;}

    uint16_t count = 0; // number of possible games
    string l; // file line, representing each game

    while(getline(inFile, l))
        count += isGamePos(l);


    std::cout << endl << endl << "Number of Possible Games: " << static_cast<int>(count) << endl;
}