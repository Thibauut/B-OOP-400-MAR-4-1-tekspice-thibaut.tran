/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** And.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class AndComponent: public nts::AComponent {
        public:
            AndComponent(std::string name): nts::AComponent(name) {};
            ~AndComponent() = default;
            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin) {};

            nts::Tristate _value;
    };
}
