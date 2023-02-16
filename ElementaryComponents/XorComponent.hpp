/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Xor.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class XorComponent: public nts::AComponent {
        public:
            XorComponent(std::string name): nts::AComponent(name) {};
            ~XorComponent() = default;
            nts::Tristate compute(std::size_t pin);

            nts::Tristate _value;
    };
}