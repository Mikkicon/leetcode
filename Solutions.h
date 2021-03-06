//
// Created by Mikhail Petrenko on 01.07.2020.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H


#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
        Node():val(0),prev(nullptr), next(nullptr),child(nullptr){};
        Node(int val):val(val),prev(nullptr), next(nullptr),child(nullptr){};
    };
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

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
    static int nthUglyNumber(int n) {
//        1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24
        int counter = 0;
        int local_num = 0;
        vector<int> result = {1};
        while(result.size()<n) {
            local_num = *(result.end()-1);
            result.push_back(min(min(local_num*2, local_num*3), min(local_num*3, local_num*5)));
        }
        // result = vector<int>(result.begin(), result.begin()+n);
        sort(result.begin(), result.end());
//        for(int num : result)
//            cout << num << endl;
        int answer = *(result.end()-1);
        return answer;
    }
    static int hammingDistance(int x, int y) {
        int xorz = x^y;
        int counter = 0;
        while(xorz){
            cout<<xorz<<endl;
            if(xorz%2)
                ++counter;
            xorz = xorz>>1;
        }
        return counter;
    }
    static vector<vector<int>> threeSum(vector<int>& nums) {
//        6-4 -2 -2 -2 0 1 2 2 2 3 3 4 4 6 6
        vector<int> temp = {};
        vector<vector<int>> result = {};
        int left_idx = 0, two_sum = 0, target = 0, right_idx = nums.size()-1;

        if(nums.size()<3) return result;

        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size(); ++i) {
            target = -nums[i];
            while (left_idx < right_idx) {
                two_sum = nums[left_idx] + nums[right_idx];
                if (left_idx == i || two_sum < target) {
                    ++left_idx;
                } else if (right_idx == i || two_sum > target) {
                    --right_idx;
                } else {
                    temp.push_back(nums[left_idx]);
                    temp.push_back(nums[right_idx]);
                    temp.push_back(nums[i]);
                    sort(temp.begin(),temp.end());
                    if(find(result.begin(), result.end(), temp) == result.end())
                        result.push_back(temp);
                    temp = {};
                    if(abs(nums[left_idx]) < abs(nums[right_idx])){
                        --right_idx;
                    }else{
                        ++left_idx;
                    }
                }
            }
            left_idx = 0;
            right_idx = nums.size()-1;
            temp = {};
        }
        return result;
    }
    static int islandPerimeter(vector<vector<int>>& grid) {
        unsigned int perimeter = 0;
        int i = 0, j = 0;
        while(i < grid.size()){
            while(j < grid[i].size() && grid[i][j] == 0){
                ++j;
            }
            while(j < grid[i].size() && grid[i][j] == 1){
                if(i == 0 || grid[i-1][j] == 0)
                    ++perimeter;
                if(i == grid.size()-1 || grid[i+1][j] == 0)
                    ++perimeter;
                if(j == 0 || grid[i][j-1] == 0)
                    ++perimeter;
                if(j == grid[i].size()-1 || grid[i][j+1] == 0)
                    ++perimeter;
                ++j;
            }

            ++i;
            if(i == grid.size())
                break;
            while(j >= 0 && grid[i+1][j] == 0){
                --j;
            }
            while(j >= 0 && grid[i][j] == 1){
                --j;
            }
            ++j;
        }
        return perimeter;
    }
    static int widthOfBinaryTree(TreeNode* root) {
        map<int, vector<int>> m;
        int max_width = 0, max_width_x = 0, current_width = 0;
        Solution::get_coords(root, 0, 0, 0, m);
        for(auto const& coords : m){
            cout<<"l: "<<coords.second[0]<<"; r: "<<coords.second[1]<<endl;
            current_width = abs(coords.second[0]) + abs(coords.second[1]);
            if(max_width < current_width){
                max_width = current_width;
                max_width_x = coords.first;
            }
        }
        return pow(2, max_width_x);
    }

    static void get_coords(TreeNode* node, int offset, int depth, float comparator, map<int, vector<int>> &dict){
        if(node){
            if(!dict[depth].size())
                dict[depth] = {offset, offset};
            else if(offset < dict[depth][0])
                dict[depth][0] = offset;
            else if(offset > dict[depth][1])
                dict[depth][1] = offset;
            ++depth;
            // if(comparator > 0){
            get_coords(node->left, offset + (comparator - 0.5), depth,-0.5, dict);
            get_coords(node->right, offset + (comparator - 0.5), depth, 1.5 , dict);
            // }
            // else if(comparator > 0){
            //     get_coords(node->left, offset, depth,-1, dict);
            //     get_coords(node->right, offset + 1, depth,1 , dict);
            // }else{
            //     get_coords(node->left, offset - 1, depth,-1, dict);
            //     get_coords(node->right, offset , depth,1, dict);
            // }

        }
    }
    static Node* flatten(Node* head) {
        Solution::flatten_dfs(head, nullptr);
        return head;
    }
    static void flatten_dfs(Node* node, Node* parent){
        // Sink while there are children
        if(node->child)
            flatten_dfs(node->child, node);

        // Child that doesn't have a child (lowest)
        Node* temp = new Node();
        if(parent){
            // Stash pointer to parents' next
            temp->next = parent->next;

            // Child becomes next
            parent->next = node;
            parent->child = nullptr;
            // Childs' previous is parent
            node->prev = parent;
        }
        // Seaking final node in the row
        while(node->next){
            node = node->next;
            // Sink while there are children
            if(node->child)
                flatten_dfs(node->child, node);
        }
        // If parent didn't have next -> skip
        if(parent) {
            // Assign stashed parents' next to current next
            node->next = temp->next;
            if(temp->next){
                // Assign "prev" of stashed parents' next to current
                temp->next->prev = node;
            }
        }
        delete temp;
    }
    static vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {};
        // curr vector([1], etc) on lvl, available nums
        vector<int> temp({}), scope(nums);
        // Begin with all the nums in scope,
        // and current = []
        decomposition(temp, scope, result);
        return result;
    }
    static void decomposition(vector<int> current, vector<int> scope, vector<vector<int>>& result){
        // If we don't have available nums to append
        // -> add current to result and exit recursive call
        if(scope.empty()){
            return;
        }
        vector<int> temp(current);
        vector<int> new_scope(scope);
        vector<int>::iterator it = new_scope.begin();
        // Append to current each available number
        // from scope
        for(int num : scope){
            // new current = current + num
            temp.push_back(num);
            // remove used num from scope
            new_scope.erase(remove(new_scope.begin(), new_scope.end(), *it), new_scope.end());
//            // keeping iterator aligned with num
//            ++it;
            // call recursively with current + num,
            // shrank scope and mutual result
            decomposition(temp, new_scope, result);
            result.push_back(temp);
            // remove num to free space for the next one
            temp.pop_back();
        }
    }
    static uint32_t reverseBits(uint32_t n) {
//         00000010100101000001111010011100
//                        \/
//         00111001011110000010100101000000

        uint32_t result = 0;
        uint32_t cmpr = n;
        int temp = 0;

        for(int i = 0; i < 32; ++i){
            temp = cmpr % 2;
            cout<<temp<<' ';
            cmpr = cmpr>>1;
            if(temp)
                ++result;
            result = result<<1;
        }
        result = result>>1;
        result = n % 2 ? result | 2147483648 : result;
        return result;
    }
    static double angleClock(int hour, int minutes) {
//         12:30 ==> sec 0: sec 6 (360 / 12 = 30*)
        double hour_sector =((double) minutes / 60) + hour % 12;
//        cout<<"hour_sector: "<<hour_sector<<endl;
        double min_sector = ((double)minutes / 5);
        cout<<"min_sector: "<<min_sector<<endl;
        double angle = 30 * abs(min_sector - hour_sector);
        double result = angle > 180 ? 360 - angle : angle;
        cout<<result;
        return result;
    }
    static string reverseWords(string& s) {
        int a = s.find_first_not_of(' '),b = 0;
        if(a == string::npos) return "";
        string result, temp;
        while(a != string::npos){
            s = s.substr(a, s.length() - a);
            b = s.find_first_of(' ');
            if(b == s.npos) b = s.length();
            temp = s.substr(0,  b);
            result = temp + " " + result;
            s = s.substr(b,  s.length() - b);
            a = s.find_first_not_of(' ');
        }
        result = result.substr(0, result.length()-1);
        cout<<"S:"<<result<<'.';
        return result;
    }
    static ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* current = new ListNode();
        ListNode* previous = new ListNode();
//        current = head;
        while(head && head->val == val){
            head = head->next;
        }
        current = head;
        while(current){
            if(current->val == val){
                if(previous->next)
                    previous->next = current->next;
                else
                    head->next = current->next;
                current = previous->next;
            }else{
                previous = current;
                current = current->next;
            }
        }
        delete current;
        return head;
    }
};

#endif //LEETCODE_SOLUTION_H

