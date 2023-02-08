/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

void Parser::parseFile(std::string file, Parser &parser)
{
    ifstream input_file(file);
    if (!input_file.is_open())
        return;
    string line;
    string current_section = "";

    while (getline(input_file, line)) {
        stringstream ss(line);
        string statement;
        ss >> statement;
        if (statement == ".chipsets:")
            current_section = "chipsets";
        else if(statement == ".links:")
            current_section = "links";
        else if (statement[0] != '#') {
            string content, name;
            content = statement;
            ss >> name;
            if (current_section == "chipsets")
                parser._chipsets.push_back(make_pair(content, name));
            if (current_section == "links")
                parser._links.push_back(make_pair(content, name));
        }
    }
}

void Parser::print() {
    cout << "Chipsets:\n";
    for (auto &x : _chipsets)
        cout << x.first << " " << x.second << endl;

    cout << "Links:\n";
    for (auto &x : _links)
        cout << x.first << " " << x.second << endl;
}