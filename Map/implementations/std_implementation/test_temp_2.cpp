#include <utility>
#include <iostream>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int main() {
    std::pair<std::string, std::vector<int>> foo(std::piecewise_construct,
                                                 std::forward_as_tuple("sample"),
                                                 std::forward_as_tuple(2, 100));
    std::

    std::cout << "foo.first: " << foo.first << '\n';
    std::cout << "foo.second:";

    for (int &x : foo.second)
        std::cout << ' ' << x;
    std::cout << '\n';
}