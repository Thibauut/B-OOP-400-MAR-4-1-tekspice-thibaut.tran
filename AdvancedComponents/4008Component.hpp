/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4008Components.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class Component4008 : public AComponent {
        public:
            Component4008(std::string name): nts::AComponent(name) {
                this->_value3 = nts::UNDEFINED;
            };
            ~Component4008() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin) {};
            nts::Tristate Sum(size_t value1, size_t value2, size_t value3);

            nts::Tristate _value;
            size_t _value3;
    };
}