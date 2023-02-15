/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** output.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class OutputComponent: public nts::AComponent {
        public:
            OutputComponent(std::string name): AComponent(name) {
                _value = UNDEFINED;
            };
            ~OutputComponent() = default;
            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin) {
            };

            Tristate _value;
    };
}