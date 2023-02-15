/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Circuit.hpp
*/

#pragma once

// #include "../IComponents.hpp"
#include "../SpecialComponents/InputComponent.hpp"
#include "../SpecialComponents/OutputComponent.hpp"
#include "../SpecialComponents/ClockComponent.hpp"
#include "../SpecialComponents/TrueComponent.hpp"
#include "../SpecialComponents/FalseComponent.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit() = default;
            ~Circuit() {
                _components.clear();
            };

            void simulate(std::size_t &tick, bool &isInput, Circuit &circuit, Parser &file, std::vector<std::pair<std::string, std::string>> _valuesToSet) {
                if (isInput == true) {
                    for (auto &it : _valuesToSet) {
                        if (it.second == "1" || it.second == "0")
                            circuit.getComponent(it.first, file)->setValue(std::stoi(it.second));
                        if (it.second == "U")
                            circuit.getComponent(it.first, file)->setValue(UNDEFINED);
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