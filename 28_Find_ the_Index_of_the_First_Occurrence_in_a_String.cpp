#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    // Use built-in find() function of std::string
    size_t pos = haystack.find(needle);

    // If not found, find() returns string::npos
    if (pos != string::npos)
        return pos;
    else
        return -1;
}

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    cout << strStr(haystack, needle) << endl;   // Output: 0

    haystack = "leetcode";
    needle = "leeto";
    cout << strStr(haystack, needle) << endl;   // Output: -1

    return 0;
}
