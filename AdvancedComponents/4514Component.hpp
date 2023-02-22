/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4514Component.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class Component4514 : public AComponent {
        public:
            Component4514(std::string name): nts::AComponent(name) {};
            ~Component4514() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin);
            nts::Tristate _value;
    };
}