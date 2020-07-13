//
// Created by Mikkicon on 12.07.2020.
//

#ifndef LEETCODE_INTERVIEWS_H
#define LEETCODE_INTERVIEWS_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

class Interviews{
public:
    static bool is_printable(const std::string& input){
        int count;
        for (char symbol : input) {
            count = std::count(input.begin(), input.end(), symbol);
            if(count == 2) return true;
        }
        return false;
    }

    static void code_n_care(){
        std::string input;
        std::vector<std::string> lines;
        bool should_print = false;
        std::cout<<"\nPlease input strings...\n";
        getline(std::cin,input);
        while (!input.empty()) {
            lines.push_back(input);
            getline(std::cin,input);
        }
        for(const std::string& line : lines){
            should_print = is_printable(line);
            if (should_print)
                std::cout << line << std::endl;
        }
    }
    static std::string addBinaryStrings(std::string a, std::string b) {
        std::string result;
        int biggest = max(a.length(), b. length());
        bool carry = false;
        for(int i = 1; i < biggest + 1; ++i){
            if(a.size() < i){
                if(b[b.size() - i] == '1'){
                    result = carry ?  '0' + result : '1' + result;
                }else{
                    result = carry ?  '1' + result : '0' + result;
                    carry = false;
                }
            }
            else if(b.size() < i){
                if(a[a.size() - i] == '1'){
                    result = carry ?  '0' + result : '1' + result;
                }else{
                    result = carry ?  '1' + result : '0' + result;
                    carry = false;
                }
            }
            else if(a[a.size() - i] == '1' && b[b.size() - i] == '1'){
                result = carry ? '1' + result : '0' + result;
                carry = true;
            }else if (a[a.size() - i] == '1' || b[b.size() - i] == '1') {
                result = carry ? '0' + result : '1' + result ;
            }else if (a[a.size() - i] == '0' || b[b.size() - i] == '0') {
                result = carry ? '1' + result : '0' + result;
                carry = false;
            }
        }
        if(carry) result = '1' + result;
        std::cout<<result;
        return result;
    }

    static int wordCount(std::vector<std::vector<char>> board, std::string word) {
        if(!word.length()) return 0;
        int letter_idx = 0, aux_x = 0, aux_y = 0, result = 0;
        const char head = word[0];
        for(int x = 0; x < board.size(); ++x){
            for(int y = 0; y < board[x].size(); ++y){
                if(board[x][y] == head){
                    letter_idx = 0;
                    aux_x = x;
                    aux_y = y;
                    while(aux_x < board.size() && aux_y < board[aux_x].size() && board[aux_x][aux_y] == word[letter_idx]){
                        ++aux_x;
                        ++aux_y;
                        ++letter_idx;
                    }
                    if(letter_idx == word.length()) ++result;
                    letter_idx = 0;
                    aux_y = y;
                    while(aux_y < board[x].size() && board[x][aux_y] == word[letter_idx]){
                        ++aux_y;
                        ++letter_idx;
                    }
                    if(letter_idx == word.length()) ++result;
                    letter_idx = 0;
                    aux_x = x;
                    while(aux_x < board.size() && board[aux_x][y] == word[letter_idx]){
                        ++aux_x;
                        ++letter_idx;
                    }
                    if(letter_idx == word.length()) ++result;
                }
            }
        }
        std::cout<<result;
        return result;
    }

};
#endif //LEETCODE_INTERVIEWS_H
