/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Or.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class OrComponent: public nts::AComponent {
        public:
            OrComponent(std::string name): nts::AComponent(name) {};
            ~OrComponent() = default;
            nts::Tristate compute(std::size_t pin);

            nts::Tristate _value;
    };
}