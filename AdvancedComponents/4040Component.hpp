/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4040Component.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class Component4040 : public AComponent {
        public:
            Component4040(std::string name): nts::AComponent(name) {};
            ~Component4040() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin);

            nts::Tristate _value;
    };
}