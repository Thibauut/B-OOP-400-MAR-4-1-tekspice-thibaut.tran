/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4011Component.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class Component4011 : public AComponent {
        public:
            Component4011(std::string name): nts::AComponent(name) {};
            ~Component4011() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin) {};

            nts::Tristate _value;
    };
}