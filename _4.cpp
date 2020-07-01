//
// Created by Mikhail Petrenko on 12/12/19.
//

#include <string>
#include <vector>
#include <iostream>
//1861463
using  namespace std;

class Solution {
public:
/*
        PAYPALISHIRING > PAHNAPLSIIGYIR

        P > AYP < A > LIS < H > IRI < N > G
        0         1         2         3
            4 5       6 7       8 9       10
             11        12        13

        P > AYPAL < I > SHIRI < N > G
        0           1           2
            3   4       5   6       7
             8 9         0 1

        descend & put char at according offset
        ascend & put char at according offset

        1: 0, 4, 8, 12
        2: 0, 6, 12
*/

string convert(string s, int numRows) {

        if(!numRows)
            return "";
        if(numRows ==1)
            return s;
        int len = s.length();
        if(!len) return "";
        string res;
        int index=1;
        int stride = numRows+numRows-2;
        int aux_chars = 1;
        while(s.length()%stride >0){
            s.push_back(' ');
            aux_chars++;
        }
        s.push_back(' ');
        vector<int> top_idx = find_top_line(s,stride);

        for (int i = 0; i < top_idx.size(); ++i) {
            res += s[top_idx[i]];
        }

        while(index<numRows-1){
                next_line_indexes(top_idx,s,res,index);
                index++;
        }
        last_line_indexes(top_idx,s,res,index);
        index = res.length();
        while(index < len){
            res.push_back(s[index++]);
        }
        remove_if(res.begin(), res.end(), ::isspace);
        while(aux_chars-->0)
            res.pop_back();
        return res;
        }
    vector<int> find_top_line(string& s,const int stride){
        vector<int> res = {};
        cout<<s.length()<<endl;
        for(size_t i=0;i<s.length();i+=stride){
            res.push_back(i);
        }
        return res;
    }
    void next_line_indexes(vector<int> top_line, const string& s,string& res,const int offset){
        int local_sum = 0;
        const unsigned int len = s.length();
        const unsigned int row_limit = top_line.size();

        if(offset<len)res += s[offset];

        for(size_t i=1;i<row_limit;i++){

            local_sum = top_line[i] - offset;
            if(local_sum > 0 && local_sum < len)
                res+=s[local_sum];

            local_sum = top_line[i] + offset;
            if(local_sum > 0 && local_sum < len)
                res+=s[local_sum];

        }
    }
    void last_line_indexes(vector<int> top_line, const string& s,string& res,const int offset){
        int local_sum = 0;
        const unsigned int len = s.length();
        const unsigned int row_limit = top_line.size();

        if(offset<len)res += s[offset];

        for(size_t i=1;i<row_limit;i++){

            local_sum = top_line[i] + offset;
            if(local_sum > 0 && local_sum < len)
                res+=s[local_sum];
        }
    }
};

//int main(){
//    Solution s;
//    string inpt = "PAYPALISHIRING";
////    string inpt = "ABCD";
//
//    int numRows = 3;
//    string result = s.convert(inpt, numRows);
//    cout<<result<<endl;
//}