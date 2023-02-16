/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** NandComponent.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class NandComponent: public nts::AComponent {
        public:
            NandComponent(std::string name): nts::AComponent(name) {};
            ~NandComponent() = default;
            nts::Tristate compute(std::size_t pin);

            nts::Tristate _value;
    };
}