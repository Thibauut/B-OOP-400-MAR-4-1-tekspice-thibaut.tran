/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Circuit.hpp
*/

#pragma once

#include "../IComponents.hpp"
#include "../SpecialComponents/InputComponent.hpp"
#include "../SpecialComponents/OutputComponent.hpp"
#include "../SpecialComponents/ClockComponent.hpp"
#include "../SpecialComponents/TrueComponent.hpp"
#include "../SpecialComponents/FalseComponent.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit() = default;
            ~Circuit() {};

            void simulate(std::size_t &tick, bool &isInput, Circuit &circuit, Parser &file, std::string &_inputName, std::string &_inputValue) {
                if (isInput == true) {
                    if (_inputValue == "1" || _inputValue == "0")
                        circuit.getComponent(_inputName, file)->setValue(std::stoi(_inputValue));
                    if (_inputValue == "U")
                        circuit.getComponent(_inputName, file)->setValue(UNDEFINED);
                    _inputName = "";
                    _inputValue = "";
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