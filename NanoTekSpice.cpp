
/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** nanotekspice.cpp
*/

#include "IComponents.hpp"
#include "AComponents.hpp"
#include "Circuit/Circuit.cpp"
#include <memory>
#include <csignal>
#include <unistd.h>

using namespace nts;

volatile sig_atomic_t g_signal_status;

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

int checkIfComponentIsValid(std::string name, Parser &file) {
    for (auto &x: file._chipsets) {
        if (x.second == name && (x.first == "input" || x.first == "clock"))
            return 1;
    }
    return 0;
}

int checkIfValueIsValid(std::string value) {
    if (value == "0" || value == "1" || value == "U")
        return 1;
    return 0;
}

void signal_handler(int signal) {
    g_signal_status = signal;
}

void circuitLoop(Circuit &circuit, Parser &file, std::vector<std::pair<std::string, std::string>> _valuesToSet, size_t _tick, bool isInput)
{
    while (1) {
        circuit.simulate(_tick, isInput, circuit, file, _valuesToSet);
        circuit.display(_tick);
        if (g_signal_status == SIGINT) {
            std::cout << "Exiting..." << std::endl;
            exit(0);
        }
        sleep(1);
    }
}

int main(int ac, char **av)
{
    // PARSER
    Parser file;
    if (ac != 2)
        return (84);
    file.parseFile(av[1], file);
    // CREATE CIRCUIT
    Circuit *circuit = new Circuit();
    //ADD COMPONENTS TO CIRCUIT
    addComponentToCircuit(*circuit, file);
    //SET LINKS BETWEEN COMPONENTS
    setLinksInCircuit(*circuit, file);

    // EXECUTION && SIGNAL HANDLER
    signal(SIGINT, signal_handler);
    std::string line;
    std::cout << "> ";
    size_t _tick = 0;
    std::string _componentName = "";
    std::string _componentValue = "";
    std::vector<std::pair<std::string, std::string>> _valuesToSet;
    bool isInput = false;
    while (std::getline(std::cin, line)) {
        if (line == "exit")
            return 0;
        else if (line == "display")
            circuit->display(_tick);
        else if (line == "simulate")
            circuit->simulate(_tick, isInput, *circuit, file, _valuesToSet);
        else if (line == "loop")
            circuitLoop(*circuit, file, _valuesToSet, _tick, isInput);
        else {
            std::size_t findEquals = line.find('=');
            if (findEquals != std::string::npos) {
                _componentName = line.substr(0, findEquals);
                _componentValue = line.substr(findEquals + 1);
                if (checkIfComponentIsValid(_componentName, file) == 0)
                    cout << "Invalid input name" << std::endl;
                else if (checkIfValueIsValid(_componentValue) == 0)
                    cout << "Invalid input value" << std::endl;
                else {
                    isInput = true;
                    _valuesToSet.push_back(std::make_pair(_componentName, _componentValue));
                    AComponent *tmp = dynamic_cast<AComponent*>(circuit->getComponent(_componentName, file));
                }
            }
            else
                cout << "Invalid command" << std::endl;
        }
        cout << "> ";
    }
    return (0);
}