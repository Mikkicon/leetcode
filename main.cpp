#include <iostream>
#include "Solutions.h"
#include "Interviews.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void for_flatten(){
    auto two = new Solution::Node(2);
    auto three = new Solution::Node(3);
    auto four = new Solution::Node(4);
    auto seven = new Solution::Node(7);
    auto eight = new Solution::Node(8);
    auto nine = new Solution::Node(9);
    auto eleven = new Solution::Node(11);
    auto twelve = new Solution::Node(12);
    two->next = three;
    three->prev = two;
    three->child = seven;
    three->next = four;
    four->prev = three;
    seven->next = eight;
    eight->prev = seven;
    eight->child = eleven;
    eight->next = nine;
    nine->prev = eight;
    eleven->next = twelve;
    twelve->prev = eleven;
    Solution::flatten(two);
}

int main() {
//    string line;
//    const unsigned char * data = (const unsigned char *)"hello";
//
//    unsigned int k = *(unsigned int*)data;
//    vector<int> vector0 = {0,1,0,1,1,0,0,1};
//    vector<int> vector2 = {1,1,1,2,2,3,3,3};
//    vector<int> vector3 = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//    auto tree = new Solution::TreeNode();
//    vector<int> vector5 = {1,2,3,4};
//    Solution::widthOfBinaryTree();
//    vector<vector<int>> grid = {{0,1}};
//    vector<vector<int>> grid0 = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
//    int res = Solution::removeDuplicates(vector1);
//    Solution::rotate(vector2, 2);
//    for(int num : vector2)
//        cout<<num<<" ";
//    cout<<endl;
//    Solution::prisonAfterNDays(vector0,7);
//    Solution::nthUglyNumber(6);
//    Solution::threeSum(vector3);
//    Solution::islandPerimeter(grid0);
//    cout<<two->val;
//    Solution::subsets(vector5);
//    Solution::reverseBits(123);
//    Interviews::code_n_care();
//    Interviews::addBinaryStrings("1101", "111");
//    std::vector<std::vector<char>> board = {{'s', 'o', 's', 'o'},
//                                            {'s', 'o', 'o', 's'},
//                                            {'s', 's', 's', 's'}};
//    Interviews::wordCount(board, "sos");
//    Solution::angleClock(1,57);
    string s = "  fdsa fdsa fdsaf fdsaf f ";
    Solution::reverseWords(s);
    return 0;
}
