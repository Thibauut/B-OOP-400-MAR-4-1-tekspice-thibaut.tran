/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4801Component.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class Component4801 : public AComponent {
        public:
            Component4801(std::string name): nts::AComponent(name) {
                this->_value3 = nts::UNDEFINED;
            };
            ~Component4801() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin) {};

            nts::Tristate _value;
            size_t _value3;
    };
}