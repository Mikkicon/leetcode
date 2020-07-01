//
// Created by Mikhail Petrenko on 12/4/19.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
//    "abcabcbb"
    int lengthOfLongestSubstring(string s) {
        string longest;
        string current;
        int local_index=1;
        for (int global_index = 0; global_index < s.length(); ++global_index) {
            current = s[global_index];
            while(current.find(s[global_index+local_index])==string::npos and global_index+local_index<s.length()){
                current += s[global_index+local_index++];
            }
            if(current.length()>longest.length())
                longest = current;
            local_index = 1;
        }
        return longest.length();
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        string s = stringToString(line);
//
//        int ret = Solution().lengthOfLongestSubstring(s);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}