/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Parser.hpp
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

class Parser {
    public:
        Parser() {};
        ~Parser() {};
        void parseFile(std::string file, Parser &parser);
        void print();

        vector<pair<string, string>> _chipsets;
        vector<pair<string, string>> _links;
};