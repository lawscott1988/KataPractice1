#include <iostream>
#include <string>
#include <algorithm>


int longest_palindrome(const std::string& s);
bool checkLongest (const std::string& s);

int main() {
    std::string input{"baablkj12345432133d"};

    int output = longest_palindrome(input);

    std::cout << output << "\n";
}

int longest_palindrome(const std::string& s)
{

    std::string reversed{};
    std::string sRev = s;
    std::reverse(sRev.begin(), sRev.end());

    if(s == sRev) {
        return s.length();
    }

    auto start1 = s.begin() + 1;
    auto end1 = s.end();
    auto start2 = s.begin();
    auto end2 = s.end() - 1;

    std::string s1{};
    std::string s2{};
    int longestSoFar{0};

    for(; start1 != end1 || start2 != end2; ++start2, --end1) {
        for (; start1 < end1 || end2 > start2; ++start1, --end2) {
            s1 = std::string(start1, end1);
            s2 = std::string(start2, end2);
            if(s1.length() > longestSoFar) {
                if(checkLongest(s1)) {
                    longestSoFar = s1.length();
                }
            }
            if(s2.length() > longestSoFar) {
                if (checkLongest(s2)) {
                    longestSoFar = s2.length();
                }
            }
        }
        start1 = s.begin() + 1;
        end2 = s.end() - 1;
    }
    return longestSoFar;
}

bool checkLongest(const std::string& s) {
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    if(reversed == s) {
            return true;
    }
    return false;
}