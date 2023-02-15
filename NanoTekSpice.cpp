
/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** nanotekspice.cpp
*/

#include "IComponents.hpp"
#include "AComponents.hpp"
#include "Circuit/Circuit.hpp"

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

int main(int ac, char **av)
{
    // PARSER
    AComponent *test;
    Parser file;
    if (ac != 2)
        return (84);
    file.parseFile(av[1], file);

    // file.print();

    //BOOSTRAP MAIN
    // std::unique_ptr <nts::IComponent> gate = std::make_unique <nts::AndComponent>();
    // std::unique_ptr <nts::IComponent> input1 = std::make_unique <nts::FalseComponent>();
    // std::unique_ptr <nts::IComponent> input2 = std::make_unique <nts::TrueComponent>();
    // std::unique_ptr <nts::IComponent> inverter = std::make_unique<nts::NotComponent>();
    // gate->setLink(1, *input1, 1);
    // gate->setLink(2, *input2, 1);
    // inverter->setLink (1, *gate, 3);

    // gate->simulate(1);
    // input1->simulate(1);
    // input2->simulate(1);

    // cout << "!(" << input1->compute(1) << " && " << input2->compute(1) << ") -> " << inverter->compute(2) << std::endl;


    // Circuit *circuit = new Circuit();

    // circuit->addComponent("in", file);
    // circuit->addComponent("out", file);


    // IComponent *thibin1 = circuit->getComponent("in", file);
    // IComponent *thibin2 = circuit->getComponent("out", file);



    // cout << "compute1 = " << thib->compute(1) << endl;
    // cout << "compute2 = " << thib2->compute(1) << endl;
    // circuit->display();


    //EXECUTION
    // std::string line;
    // AComponent *component;
    // std::cout << "> ";
    // int _tick = 0;
    // while (std::getline(std::cin, line)) {
    //     if (line == "exit")
    //         return 0;
    //     else if (line == "display") {
    //         cout << "display" << std::endl;
    //         // cout << "tick: " << _tick << std::endl;
    //         // cout << "input(s):" << std::endl;
    //         // // cout << "  " << component->compute() << ":<< << std::endl;
    //         // cout << "output(s):" << std::endl;
    //     }
    //     else if (line == "simulate") {
    //         // component->simulate(_tick);
    //         // _tick += 1;
    //         cout << "Simulate" << std::endl;
    //     }
    //     else if (line == "loop") {
    //         cout << "Loop" << std::endl;
    //     }
    //     else if (line == "dump") {
    //         cout << "Dump" << std::endl;
    //     }
    //     else {
    //         cout << "Invalid command" << std::endl;
    //     }
    //     cout << "> ";

    // }
    // return (0);
}