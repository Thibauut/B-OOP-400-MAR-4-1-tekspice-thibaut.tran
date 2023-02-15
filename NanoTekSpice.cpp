
/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** nanotekspice.cpp
*/

#include "IComponents.hpp"
#include "AComponents.hpp"
#include "Circuit/Circuit.cpp"

#include "SpecialComponents/FalseComponent.cpp"
#include "SpecialComponents/TrueComponent.cpp"
#include "SpecialComponents/ClockComponent.cpp"
#include "SpecialComponents/InputComponent.cpp"
#include "SpecialComponents/OutputComponent.cpp"

#include "ElementaryComponents/AndComponent.cpp"
#include "ElementaryComponents/NotComponent.cpp"

#include "Parser/Parser.cpp"
#include <memory>

using namespace nts;

void addComponentToCircuit(Circuit &circuit, Parser &file) {
    for (auto &x: file._chipsets) {
        circuit.addComponent(x.second, file);
    }
}

void setLinksInCircuit(Circuit &circuit, Parser &file) {
    for (auto &x: file._links) {
        //noms des composents
        string firstComponent = x.first.substr(0, x.first.find(":"));
        string otherComponent = x.second.substr(0, x.second.find(":"));
        //pins des composants
        size_t _pin = std::stoi(x.first.substr(x.first.find(":") + 1));
        size_t _otherPin = std::stoi(x.second.substr(x.second.find(":") + 1));
        //setlinks
        circuit.getComponent(firstComponent, file)->setLink(_pin, *circuit.getComponent(otherComponent, file), _otherPin);
    }
}

int checkIfComponentIsInput(std::string name, Parser &file) {
    for (auto &x: file._chipsets) {
        if (x.second == name && x.first == "input")
            return 1;
    }
    return 0;
}

int checkIfValueIsValid(std::string value) {
    if (value == "0" || value == "1" || value == "U")
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    // PARSER
    Parser file;
    if (ac != 2)
        return (84);
    file.parseFile(av[1], file);
    //CREATE CIRCUIT
    Circuit *circuit = new Circuit();
    //ADD COMPONENTS TO CIRCUIT
    addComponentToCircuit(*circuit, file);
    //SET LINKS BETWEEN COMPONENTS
    setLinksInCircuit(*circuit, file);
    //EXECUTION
    std::string line;
    std::cout << "> ";
    size_t _tick = 0;
    std::string _inputName = "";
    std::string _inputValue = "";
    bool isInput = false;
    while (std::getline(std::cin, line)) {
        if (line == "exit")
            return 0;
        else if (line == "display")
            circuit->display(_tick);
        else if (line == "simulate")
            circuit->simulate(_tick, isInput, *circuit, file, _inputName, _inputValue);
        else if (line == "loop") {
            std::cout << "loop" << std::endl;
        }
        else {
            std::size_t findEquals = line.find('=');
            if (findEquals != std::string::npos) {
                _inputName = line.substr(0, findEquals);
                _inputValue = line.substr(findEquals + 1);
                if (checkIfComponentIsInput(_inputName, file) == 0)
                    cout << "Invalid input name" << std::endl;
                else if (checkIfValueIsValid(_inputValue) == 0)
                    cout << "Invalid input value" << std::endl;
                else
                    isInput = true;
            }
            else
                cout << "Invalid command" << std::endl;
        }
        cout << "> ";

    }
    return (0);
}