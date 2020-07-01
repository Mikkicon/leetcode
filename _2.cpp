////
//// Created by Mikhail Petrenko on 12/4/19.
////
//
//#include <iostream>
//#include <vector>
//#include <sstream>
//
//using namespace std;
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x=0) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        int local_sum = 0;
//        int carry = 0;
//        ListNode* result = new ListNode(0);
//        ListNode* position(result);
//        while(l1 || l2){
//            if(!l1){
//                local_sum = l2->val + carry;
//                cout<<" "<<local_sum<<endl;
//
//                position->val = local_sum%10;
//                carry = local_sum/10;
//
//                l2 = l2->next;
//
//                if( l2 || carry){
//                    position->next = new ListNode(carry);
//                    position = position->next;
//                }
//            }else if(!l2){
//                local_sum = l1->val + carry;
//                cout<<" "<<local_sum<<endl;
//
//                position->val = local_sum%10;
//                carry = local_sum/10;
//
//                l1 = l1->next;
//
//                if( l1 || carry){
//                    position->next = new ListNode(carry);
//                    position = position->next;
//                }
//            }else{
//                cout<<l1->val<<" "<<l2->val<<endl;
//
//                local_sum = l1->val + l2->val + carry;
//                position->val = local_sum%10;
//                carry = local_sum/10;
//
//                l1 = l1->next;
//                l2 = l2->next;
//                if(l1 || l2 || carry){
//                    position->next = new ListNode(carry);
//                    position = position->next;
//                }
//            }
//        }
//        return result;
//    }
//};
//
//void trimLeftTrailingSpaces(string &input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//    }));
//}
//
//void trimRightTrailingSpaces(string &input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), input.end());
//}
//
//vector<int> stringToIntegerVector(string input) {
//    vector<int> output;
//    trimLeftTrailingSpaces(input);
//    trimRightTrailingSpaces(input);
//    input = input.substr(1, input.length() - 2);
//    stringstream ss;
//    ss.str(input);
//    string item;
//    char delim = ',';
//    while (getline(ss, item, delim)) {
//        output.push_back(stoi(item));
//    }
//    return output;
//}
//
//ListNode* stringToListNode(string input) {
//    // Generate list from the input
//    vector<int> list = stringToIntegerVector(input);
//
//    // Now convert that list into linked list
//    ListNode* dummyRoot = new ListNode(0);
//    ListNode* ptr = dummyRoot;
//    for(int item : list) {
//        ptr->next = new ListNode(item);
//        ptr = ptr->next;
//    }
//    ptr = dummyRoot->next;
//    delete dummyRoot;
//    return ptr;
//}
//
//string listNodeToString(ListNode* node) {
//    if (node == nullptr) {
//        return "[]";
//    }
//
//    string result;
//    while (node) {
//        result += to_string(node->val) + ", ";
//        node = node->next;
//    }
//    return "[" + result.substr(0, result.length() - 2) + "]";
//}
//
////int main() {
////    string line;
////    while (getline(cin, line)) {
////        ListNode* l1 = stringToListNode(line);
////        getline(cin, line);
////        ListNode* l2 = stringToListNode(line);
////
////        ListNode* ret = Solution().addTwoNumbers(l1, l2);
////
////        string out = listNodeToString(ret);
////        cout << out << endl;
////    }
////    return 0;
////}