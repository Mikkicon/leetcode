//
// Created by Mikhail Petrenko on 01.07.2020.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    static int removeDuplicates(vector<int>& nums) {
        auto it = nums.begin();
        vector<int>::iterator aux;
        while(it != nums.end()){
            aux = it + 1;
            while(aux != nums.end() && !(*aux - *it)){
                aux = it + 1;
                nums.erase(aux);
            }
            ++it;
        }
        return nums.size();
    }
    static void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int new_begin_idx = nums.size() - k;
        vector<int>::iterator lft = nums.end() - k;
        vector<int> left(lft, nums.end());
        vector<int>::iterator rgt = nums.begin() + new_begin_idx;
        vector<int> right(nums.begin(), rgt);
        nums.clear();
        nums.insert( nums.end(), left.begin(), left.end() );
        nums.insert( nums.end(), right.begin(), right.end() );
    }
    static bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i + 1 < nums.size()){
            if(!(nums[i+1] - nums[i]))
                return true;
            ++i;
        }
        return false;
    }
};

#endif //LEETCODE_SOLUTION_H

