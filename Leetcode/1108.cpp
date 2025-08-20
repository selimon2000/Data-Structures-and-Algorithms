#include <string.h>


class Solution {
public:
    string defangIPaddr(string address) {
        uint8_t size = address.length() + 6;

        for (uint8_t i = 0; i < size;) {
            if(address.at(i) == '.') {
                address.replace(i, 1, "[.]");
                i += 3;
            }
            else
                i++;
        }
    
    return address;
    }
};