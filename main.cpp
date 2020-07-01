#include <iostream>
#include "Solutions.h"
#include <vector>
#include <sstream>
//#include <map>

using namespace std;

class FindMedianSortedArrays {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int size1 = nums1.size();
        const int size2 = nums2.size();

        const int combined_size = (size1 + size2);
        const bool isOdd = combined_size % 2;
        const int combined_middle_index = (int)combined_size / 2 + 1;

        const int starting_point = is_fst_vec_has_min(nums1, nums2) ? 0 : 1;

        // bool is_nums1_last = ! (bool) starting_point;
        int iterations_num = 0;
        int previous = 0;
        int current = 0;

        cout << "combined_size: " << combined_size << endl;
        cout << "isOdd: " << isOdd << endl;
        cout << "combined_middle_index: " << combined_middle_index << endl;
        // cout << "is_nums1_last: " << is_nums1_last << endl;

        while (iterations_num < combined_middle_index)
        {
            cout << "iterations_num: " << iterations_num << endl;
            cout << "nums1.size(): " << nums1.size() << endl;
            cout << "nums2.size(): " << nums2.size() << endl;

            previous = current;

            if (nums1.empty())
            {
                current = pop_front(nums2);
            }
            else if(nums2.empty())
            {
                current = pop_front(nums1);
            }
            else if(nums1[0] <= nums2[0])
            {
                current = pop_front(nums1);
            }
            else{
                current = pop_front(nums2);
            }
            iterations_num++;
        }
        if (isOdd)
        {
            return current;
        }else{
            return (previous+current)/2.0;
        }

    }
    bool is_fst_vec_has_min(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.empty())
            return false;
        if (nums2.empty())
            return true;
        return nums1[0] < nums2[0];
    }

    int pop_front(std::vector<int>& vec)
    {
        const int vec_front = vec.front();
        vec.erase(vec.begin());
        return vec_front;
    }
};
// int 6/2 = 3; 3-1
// int 5/2 = 2; 2-1
// [-2,3,4,6,8,9]
// [ 0,2,5,7,8,9]

// [-2,-1,1,3]
// [ 2, 5,6,7,8]

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
//    string line;
////    while (getline(cin, line)) {
////        vector<int> nums1 = stringToIntegerVector(line);
////        getline(cin, line);
////        vector<int> nums2 = stringToIntegerVector(line);
////
////        double ret = Solution().findMedianSortedArrays(nums1, nums2);
////
////        string out = to_string(ret);
////        cout << out << endl;
////    }

//    const unsigned char * data = (const unsigned char *)"hello";
//
//    unsigned int k = *(unsigned int*)data;
    vector<int> vector1 = {0,0,1,1,1,2};
    vector<int> vector2 = {1,1,1,2,2,3,3,3};
    int res = Solution::removeDuplicates(vector1);
    Solution::rotate(vector2, 2);
    for(int num : vector2)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}