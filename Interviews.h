//
// Created by Mikkicon on 12.07.2020.
//

#ifndef LEETCODE_INTERVIEWS_H
#define LEETCODE_INTERVIEWS_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
class Interviews{
public:
    static bool is_printable(const std::string& input){
        std::unordered_map<char, int> dict{};
        std::unordered_set<char> excluded{}, twos_indexes{};
        std::unordered_map<char, int>::iterator dt_iter;
        std::unordered_set<char>::iterator ex_iter;
        // bool result = false;
        for (char symbol : input) {
            ex_iter = excluded.find(symbol);
            if (ex_iter == excluded.end()) {
                ++dict[symbol];
                if (dict[symbol] > 2) {
                    excluded.insert(symbol);
                    twos_indexes.erase(symbol);
                } else if (dict[symbol] == 2)
                    twos_indexes.insert(symbol);
            }
        }
        return !twos_indexes.empty();
    }

    static void code_n_care(){
        std::string input;
        bool should_print = false;
        std::cout<<"\nPlease input a string...\n";
        getline(std::cin,input);
        while (!input.empty()) {
            should_print = is_printable(input);
            if (should_print)
                std::cout << input << std::endl;
            std::cout<<"Please input a string...\n";
            getline(std::cin,input);
        }
    }
};
#endif //LEETCODE_INTERVIEWS_H
