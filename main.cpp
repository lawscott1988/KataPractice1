#include <iostream>
#include <string>
#include <algorithm>

int longest_palindrome(const std::string& s);

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

    for(; start1 != end1 || start2 != end2; ++start2, --end1) {
        for (; start1 < end1 || end2 > start2; ++start1, --end2) {
            s1 = std::string(start1, end1);
            s2 = std::string(start2, end2);
            reversed = s1;
            std::reverse(reversed.begin(), reversed.end());
            std::cout << "String 1: " << s1 << "; " << "Reversed 1: " << reversed << "\n";
            if(reversed == s1) {
                return s1.length();
            }
            reversed = s2;
            std::reverse(reversed.begin(), reversed.end());
            std::cout << "String 2: " << s2 << "; " << "Reversed 2: " << reversed << "\n";
            if(reversed == s2) {
                return s2.length();
            }
        }
        start1 = s.begin() + 1;
        end2 = s.end() - 1;
    }

    return 0;
}