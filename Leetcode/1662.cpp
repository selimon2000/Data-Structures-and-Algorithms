class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &wv_1, vector<string> &wv_2) {
        // Using iterator
        vector<string>::iterator w_1 = wv_1.begin(), w_2 = wv_2.begin();
        string::iterator l_1 = w_1->begin(), l_2 = w_2->begin();

        while (true) {

            // IF LETTER ITERATOR REACHES END OF THEIR WORD /////////////////
            bool b1 = false, b2 = false;

            if (l_1 == w_1->end()) {
                w_1++;
                if (w_1 == wv_1.end()) b1 = true;
                else l_1 = w_1->begin();
            }

            if (l_2 == w_2->end()) {
                w_2++;
                if (w_2 == wv_2.end()) b2 = true;
                else l_2 = w_2->begin();
            }

            if (b1 == true && b2 == true) return true;
            if (!(b1 == false && b2 == false)) return false;
            //////////////////////////////////////////////////////////////////
            
            if (*(l_1++) != *(l_2++)) return false;
        }

        return true;
    }
};