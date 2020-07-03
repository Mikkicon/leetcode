//
// Created by Mikhail Petrenko on 01.07.2020.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H


#include <iostream>
#include <vector>
#include <cmath>
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

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    static vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result = {};
        if(!root)
            return result;
        dfs_levelOrderBottom(root, result, 0);
        reverse(result.begin(), result.end());
        return result;
    }
    static void dfs_levelOrderBottom(TreeNode* root, vector<vector<int>>& result, int level) {
        if(result.size() <= level){
            vector<int> local = {root->val};
            result.push_back(local);
        }else{
            result[level].push_back(root->val);
        }
        if(root->left)
            dfs_levelOrderBottom(root->left, result, level+1);
        if(root->right)
            dfs_levelOrderBottom(root->right, result, level+1);
    }
    static vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        const int length = cells.size();
        if(!length || !N)
            return cells;

        // Vector to number
        unsigned int number = 0;
        reverse(cells.begin(), cells.end());
        for(int i = 0; i < length; ++i){
            number += (cells[i] * pow(2, i));
        }
//        cout<<"Number: "<<number<<endl;
        reverse(cells.begin(), cells.end());


        // Shift left + shift right = neighbors on the place of subject
        int a = (number << 1);
        int b = (number >> 1);
        // XOR marks as "1" bits that need to be "0"
        // so we will work with bitwise inverse number
        int c = a ^ b;
        // Adding leftmost and rightmost bits
        int num = c|129;
        
//        After some research I found out that
//        the values change in cycles of 14
//        for(int i = 0; i < N-1; ++i){
        if(!(N % 14)){
            for(int i = 0; i < 13; ++i) {
                a = (num << 1) % 128;
                b = (num >> 1) % 128;
                c = a ^ b;
                num = c | 129;
//            cout<<"Answer: "<<num<<endl;
            }
        }else{
            for(int i = 0; i < (N % 14)-1; ++i) {
                a = (num << 1) % 128;
                b = (num >> 1) % 128;
                c = a ^ b;
                num = c | 129;
//            cout<<"Answer: "<<num<<endl;
            }
        }

        // Now we have a result but bits are inverted
        vector<int> result = {};
        int bit = 0;
        for(int i = 0; i < 8; ++i) {
            // Get leftmost bit and add it to vector
            bit = num%2;
            result.push_back(!bit);
            // Get shift a number right for the next bit
            num = num>>1;
        }
        reverse(result.begin(), result.end());
//        cout<<"Answer: "<<num<<endl;
        return result;
    }
};

#endif //LEETCODE_SOLUTION_H

