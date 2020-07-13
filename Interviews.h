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
};
#endif //LEETCODE_INTERVIEWS_H
