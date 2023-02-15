/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** TrueComponent.hpp
*/

#pragma once

#include "../AComponents.hpp"


namespace nts {
    class TrueComponent: public nts::AComponent {
        public:
            TrueComponent(std::string name): AComponent(name) {
                _value = TRUE;
            };
            ~TrueComponent() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin) {};

            Tristate _value;
    };
};