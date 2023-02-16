/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** NotComponent.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class NotComponent: public nts::AComponent {
        public:
            NotComponent(std::string name): nts::AComponent(name) {};
            ~NotComponent() = default;
            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin) {};

            nts::Tristate _value;
    };
}
