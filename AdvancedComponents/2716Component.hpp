/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 2716Component.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class Component2716 : public AComponent {
        public:
            Component2716(std::string name): nts::AComponent(name) {};
            ~Component2716() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin);

            nts::Tristate _value;
    };
}