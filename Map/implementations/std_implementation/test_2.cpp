#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, string> m1;
    m1.insert(pair<int, string>(1, "a"));
    m1.insert(pair<int, string>(1, "b"));
    m1.insert(pair<int, string>(2, "ab"));
    m1.insert(pair<int, string>(3, "abc"));
    m1.insert(pair<int, string>(4, "abcd"));

    auto range = m1.equal_range(1);
    if (range.first != range.second) {
        cout << "Elements with key 1:\n";
        for (auto it = range.first; it != range.second; ++it) cout << it->first << " " << it->second << endl;
    }
    else cout << "No elements with key 1 found" << endl;

    //  cout << "Multimap1:\n";
    // for (auto it = m1.cbegin(); it != m1.end(); it++)
    //     cout << it->first << " " << it->second << '\n';
    cout << "\n\n";
    
    cout << m1.lower_bound(1)->first << '\t' << m1.lower_bound(1)->second << '\n';
    cout << m1.upper_bound(1)->first << '\t' << m1.upper_bound(1)->second << '\n';

    // auto it = next(next(m1.find(1)));
    // if (it != m1.end()) cout << "Found element with key 1: " << it->first << " " << it->second << endl;
    // else                cout << "Element with key 1 not found" << endl;



/*     multimap<int, string, greater<int>> m2;
    m2.insert(pair<int, string>(1, "a"));
    m2.insert(pair<int, string>(1, "b"));
    m2.insert(pair<int, string>(2, "ab"));
    m2.insert(pair<int, string>(3, "abc"));
    m2.insert(pair<int, string>(4, "abcd"));

    cout << "Multimap1:\n";
    for (auto it = m2.cbegin(); it != m2.end(); it++)
        cout << it->first << " " << it->second << '\n';
    cout << "\n\n"; */
}