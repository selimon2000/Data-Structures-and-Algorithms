#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> vector_, int target, int start, int end)
{
    if (start > end)
    {
        return -1;
    }

    int middle = (start + end) / 2;
    // cout << "Middle: " << middle << endl;

    if (vector_.at(middle) == target)
    {
        return middle;
    }

    if (vector_.at(middle) < target)
    {
        return binarySearch(vector_, target, middle + 1, end);
    }

    return binarySearch(vector_, target, start, middle - 1);

}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 9};
    int target = 0;
    int result = binarySearch(a, target, 0, a.size() - 1);

    (result == -1)
        ? cout << "Element " << target << " not present in array" << endl
               << endl
        : cout << "Element " << target << " is present at index " << result << endl
               << endl;


    vector<int> b = {-11, 2, 3, 4, 5, 99, 126, 55, 1109};
    target = 1109;
    result = binarySearch(b, target, 0, b.size() - 1);

    (result == -1)
        ? cout << "Element " << target << " not present in array" << endl
               << endl
        : cout << "Element " << target << " is present at index " << result << endl
               << endl;
}