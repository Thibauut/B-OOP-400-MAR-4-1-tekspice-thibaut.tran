/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

int sizeAndComponent = 0;

//HASHES REMOVER
void removeHashes(std::string &str) {
    for (; !str.empty() && str.back() == '#' ;)
        str.pop_back();
}

//CHECK IF CHIPSET TYPE IS VALID
void checkComponentType(Parser &list) {
    for (auto &x : list._chipsets) {
        if (x.first != "input" && x.first != "output" && x.first != "clock" && x.first != "true" && x.first != "false"
        && x.first != "and" && x.first != "or" && x.first != "xor" && x.first != "not" &&
        x.first != "4001" && x.first != "4011" && x.first != "4030" && x.first != "4069" && x.first != "4071" && x.first != "4081" &&
        x.first != "4008" && x.first != "4013" && x.first != "4017" && x.first != "4040" && x.first != "4094" && x.first != "4514" && x.first != "4801" && x.first != "2716" && x.first != "logger" && x.first != "4512")
             Error::myErr("Error: Invalid component");
    }
    return;
}

//CHECK IF CHIPSET SHARE SAME NAME
void checkComponentSameName(Parser &list) {
    for (int i = 0; i < list._chipsets.size(); i++) {
        for (int j = i + 1; j < list._chipsets.size(); j++) {
            if (list._chipsets[i].second == list._chipsets[j].second)
                Error::myErr("Error: Several components share the same name in the chipsets list");
        }
    }
    return;
}


//CHECK IF CHIPSET NAME IS VALID FOR LINKS AND CHIPSETS
void checkComponentValidName(Parser &list) {

    for (auto &x : list._links) {
        string firstComponentName = x.first.substr(0, x.first.find(":"));
        string secondComponentName = x.second.substr(0, x.second.find(":"));
        bool isValidFirst = false, isValidSecond = false;
        for (auto &y : list._chipsets) {
            if (firstComponentName == y.second)
                isValidFirst = true;
            if (secondComponentName == y.second)
                isValidSecond = true;
        }
        if (!isValidFirst)
            Error::myErr("Error: Unknown component name '" + firstComponentName + "'");
        if (!isValidSecond)
            Error::myErr("Error: Unknown component name '" + secondComponentName + "'");
    }
    return;
}

//CHECK IF CHIPSET PIN IS VALID
void checkChipsetsPins(std::string name, std::string pin, Parser &list) {
    std::string _type = "";
    for (auto &x : list._chipsets) {
        if(x.second == name)
            _type = x.first;
    }
    if (_type == "clock" || _type == "false" || _type == "true" || _type == "input" || _type == "output") {
        if (pin != "1")
            Error::myErr("Error: Invalid pin");
    }
    else if (_type == "and" || _type == "or" || _type == "xor" || _type == "not") {
        if (pin != "1" && pin != "2" && pin != "3")
            Error::myErr("Error: Invalid pin");
    }
    else if (_type == "4001" || _type == "4011" || _type == "4030" || _type == "4069" || _type == "4071" || _type == "4081") {
        if (pin != "1" && pin != "2" && pin != "3" && pin != "4" && pin != "5" && pin != "6"  && pin != "8" && pin != "9" && pin != "10" && pin != "11" && pin != "12" && pin != "13")
            Error::myErr("Error: Invalid pin");
    }
    return;
}

//CHECK IF LINKS ARE VALID
void checkIfLinkIsValid(std::string link, Parser &list) {
    if (link.find(":") == std::string::npos)
        Error::myErr("Error: Invalid link");
    else {
        string name = link.substr(0, link.find(":"));
        string pin = link.substr(link.find(":") + 1);
        if (name.empty() || pin.empty())
            Error::myErr("Error: Invalid link");
        else
            checkChipsetsPins(name, pin, list);
    }
    return;
}

//SORT CHIPSETS
bool comparePairs(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
    return a.second < b.second;
}

void sortPairs(std::vector<std::pair<std::string, std::string>>& chipsets) {
    std::sort(chipsets.begin(), chipsets.end(), comparePairs);
}

void Parser::parseFile(std::string file, Parser &list)
{
    //INIT VARIABLES AND OPEN FILE
    ifstream input_file(file);
    if (!input_file.is_open())
        Error::myErr("Error: Invalid file");
    string line, current_statement = "";
    bool foundChipset = false;
    bool foundLinks = false;
    //PARSE FILE
    while (getline(input_file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string statement;
        ss >> statement;
        if (statement == ".chipsets:") {
            foundChipset = true;
            current_statement = "chipsets";
        }
        if(statement == ".links:") {
            foundLinks = true;
            current_statement = "links";
        }
        if (statement[0] != '#') {
            string content, name, parasite;
            content = statement;
            ss >> name;
            ss >> parasite;
            if (current_statement == "chipsets") {
                if (!parasite.empty())
                    Error::myErr("Error: Invalid chipset");
                list._chipsets.push_back(make_pair(content, name));
            }
            if (current_statement == "links") {
                if (!parasite.empty())
                    Error::myErr("Error: Invalid link");
                list._links.push_back(make_pair(content, name));
            }
        }
    }
    if (!foundChipset)
        Error::myErr("Error: \'.chipsets:\' statement not found in the configuration file");
    if (!foundLinks)
        Error::myErr("Error: \'.links:\' statement not found in the configuration file");
    //REMOVE FIRST ELEMENT OF VECTOR (REMOVING: .chipsets: AND .links:)
    list._chipsets.erase(list._chipsets.begin());
    list._links.erase(list._links.begin());
    //CHECK IF CHIPSET LIST IS EMPTY
    if (list._chipsets.empty())
        Error::myErr("Error: No chipset found in the configuration file");

    //REMOVE HASHES
    for (auto &x : list._chipsets)
        removeHashes(x.second);
    for (auto &x : list._links)
        removeHashes(x.second);
    //PARSING ERROR CHECK
    checkComponentType(list);
    checkComponentSameName(list);
    checkComponentValidName(list);
    //CHECK IF LINKS ARE VALID
    for (auto& x: list._links) {
        checkIfLinkIsValid(x.first, list);
        checkIfLinkIsValid(x.second, list);
    }

    //SORT CHIPSETS
    sortPairs(list._chipsets);

    //check if the component is and_or_not advanced if yes the size will be 10
    sizeAndComponent = list._chipsets.size();
    int count = 0;
    int count2 = 0;
    for (auto &x : list._chipsets) {
        if (x.first == "4069" || x.first == "4071" || x.first == "4081")
            count++;
        if (x.first == "4030" || x.first == "4069")
            count2++;
    }
    if (count == 3)
        sizeAndComponent = 75;
    if (count2 == 2) {
        sizeAndComponent = 76;
    }
}

void Parser::print() {
    cout << "Chipsets:" << endl;
    for (auto &x : _chipsets)
        cout << x.first << " " << x.second << endl;
    cout << "Links:" << endl;
    for (auto &x : _links)
        cout << x.first << " "<< x.second << endl;
}