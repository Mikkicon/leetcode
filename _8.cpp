//
// Created by Mikhail Petrenko on 12/31/19.
//
#include <string>
#include <iostream>
#include <cmath>
#include <regex>

using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        if(!len)return 0;

        str.erase(remove_if(str.begin(), str.end(), ::isspace),str.end());
        str.erase(0, min(str.find_first_not_of('0'), str.size()-1));

        char first = str[0];
        int sign = isMinus(first);
        int offset = isMinus(first)==-1 || isPlus(first)?1:0;
        cout<<str.find_first_not_of('0')<<endl<<str.size();
        if(offset && str[1]=='0')
            str.erase(1, min(str.substr(1).find_first_not_of('0'), str.size()-1));

        int result = 0;

        if(!(isNumber(first)|| (sign==-1 || isPlus(first))&& isNumber(str[1]) ))return 0;
        string temp = str.substr(offset);
        int find_letter = fstLetterIdx(temp)+offset;


        string only_numbers;

        only_numbers = find_letter ==-1?
                       str.substr(offset, 10+offset):
                       str.substr(offset, find_letter-offset);


        const int num_len = only_numbers.length();
        if(num_len>10) return -2147483648;
//        for(int i = 0; i < num_len; i++){
//            result += ((int) only_numbers[num_len - 1 - i]-48)* pow(10,i);
//        }
        return result * sign;
    }

    int isMinus(char c){
        return c==45?-1:1;
    }
    bool isPlus(char c){
        return c==43;
    }

    bool isNumber(char c){
        return c>=48 && c<=57;
    }

    int fstLetterIdx(string& s){
//        smatch m;
//        regex e ("[^0-9]");
//        regex_search ( s, m, e );
//        if(m.size())return s.find(m[0]);
        return -1;
    }
};
//int main(){
//    Solution s;
//    string inpt = "  -0012a42";
//    string g = "-42";
//    int result = s.myAtoi(inpt);
//    cout<<result<<endl;
//    cout<<g.erase(1,0)<<endl;
//    const unsigned char * data = (const unsigned char *)"hello";
//
//    unsigned int k = *(unsigned int*)data;
//
//}