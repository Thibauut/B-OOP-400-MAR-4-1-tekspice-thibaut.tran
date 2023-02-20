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

            void simulate(std::size_t &tick, bool &isInput, Circuit &circuit, Parser &file, std::vector<std::pair<std::string, std::string>> &_valuesToSet) {
                if (isInput == true) {
                    for (auto &x : _valuesToSet) {
                        if (x.second == "1" || x.second == "0") {
                            circuit.getComponent(x.first, file)->setValue(std::stoi(x.second));
                        }
                        if (x.second == "U")
                            circuit.getComponent(x.first, file)->setValue(UNDEFINED);
                    }
                    isInput = false;
                } else {
                    //CLOCK SIMULATION
                    if (!_valuesToSet.empty()) {
                        size_t lastIndex = _valuesToSet.size() - 1;
                        AComponent *component = dynamic_cast<AComponent*>(circuit.getComponent(_valuesToSet.back().first, file));
                         if (typeid(*component) == typeid(ClockComponent)) {
                            if (_valuesToSet[lastIndex].second == "U") {
                                circuit.getComponent(_valuesToSet[lastIndex].first, file)->setValue(UNDEFINED);
                                _valuesToSet[lastIndex].second = "U";
                            }
                            if (_valuesToSet[lastIndex].second == "0") {
                                circuit.getComponent(_valuesToSet[lastIndex].first, file)->setValue(stoi("1"));
                                _valuesToSet.emplace_back(_valuesToSet[lastIndex].first, "1");
                            }
                            if (_valuesToSet[lastIndex].second == "1") {
                                circuit.getComponent(_valuesToSet[lastIndex].first, file)->setValue(stoi("0"));
                                _valuesToSet.emplace_back(_valuesToSet[lastIndex].first, "0");
                            }
                        }
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