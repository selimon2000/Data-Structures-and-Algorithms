#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    cout << lower_bound(v.begin(), v.end(), 35) - v.begin();
}