/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** NorComponent.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class NorComponent: public nts::AComponent {
        public:
            NorComponent(std::string name): nts::AComponent(name) {};
            ~NorComponent() = default;
            nts::Tristate compute(std::size_t pin);

            nts::Tristate _value;
    };
}
