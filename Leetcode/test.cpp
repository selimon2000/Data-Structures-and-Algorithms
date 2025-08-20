#include <iostream>
#include <codecvt>
#include <locale>

int main() {
    // Create a UTF-8 string using the Unicode escape sequence for the cookie emoji
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::wstring cookie = L"\U0001F36A"; // Unicode for 🍪

    // Convert the wide string to a UTF-8 string and print it
    std::cout << "Here is a cookie: " << converter.to_bytes(cookie) << std::endl;

    return 0;
}
