/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4017Component.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class Component4017 : public AComponent {
        public:
            Component4017(std::string name): nts::AComponent(name) {};
            ~Component4017() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin);

            nts::Tristate _value;
    };
}