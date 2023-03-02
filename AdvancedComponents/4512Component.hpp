/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4512Component.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class Component4512 : public AComponent {
        public:
            Component4512(std::string name): nts::AComponent(name) {
                _value = UNDEFINED;
            };
            ~Component4512() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin) {};

            nts::Tristate _value;
    };
}
