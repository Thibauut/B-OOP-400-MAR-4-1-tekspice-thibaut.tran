/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Circuit.hpp
*/

#pragma once

#include "../SpecialComponents/InputComponent.cpp"
#include "../SpecialComponents/OutputComponent.cpp"
#include "../SpecialComponents/ClockComponent.cpp"
#include "../SpecialComponents/TrueComponent.cpp"
#include "../SpecialComponents/FalseComponent.cpp"

#include "../ElementaryComponents/AndComponent.cpp"
#include "../ElementaryComponents/NotComponent.cpp"
#include "../ElementaryComponents/OrComponent.cpp"
#include "../ElementaryComponents/XorComponent.cpp"
#include "../ElementaryComponents/NandComponent.cpp"
#include "../ElementaryComponents/NorComponent.cpp"

#include "../GatesComponents/4001Component.cpp"
#include "../GatesComponents/4011Component.cpp"
#include "../GatesComponents/4069Component.cpp"

#include "../AdvancedComponents/4008Component.cpp"
#include "../AdvancedComponents/4801Component.cpp"
#include "../AdvancedComponents/LoggerComponent.cpp"
#include "../AdvancedComponents/2716Component.cpp"
#include "../AdvancedComponents/4514Component.cpp"

namespace nts {
    class Circuit {
        public:
            Circuit() = default;
            ~Circuit() {
                _components.clear();
            };

            void simulate(std::size_t &tick, bool &isInput, Circuit &circuit, Parser &file, std::vector<std::pair<std::string, std::string>> _valuesToSet) {
                if (isInput == true) {
                    for (auto &x : _valuesToSet) {
                        if (x.second == "1" || x.second == "0") {
                            AComponent *tmp = dynamic_cast<AComponent*>(circuit.getComponent(x.first, file));
                            circuit.getComponent(x.first, file)->setValue(std::stoi(x.second));
                            if (typeid(*tmp) == typeid(ClockComponent)) {
                                if (_valuesToSet.size() > 1)
                                    _valuesToSet.erase(begin(_valuesToSet));
                                tmp->_resetComp = true;
                            }
                        }
                        if (x.second == "U")
                            circuit.getComponent(x.first, file)->setValue(UNDEFINED);
                    }

                }
                tick += 1;
            };

            // Circuit
            void addComponent(std::string name, Parser &component);

            nts::IComponent *getComponent(std::string name, Parser &file) const;

            void display(size_t _tick) const;

            // Variables
            protected:
                std::vector<std::unique_ptr<IComponent>> _components;
    };
};