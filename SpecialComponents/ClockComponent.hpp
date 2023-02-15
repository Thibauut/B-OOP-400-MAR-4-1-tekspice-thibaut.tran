/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** ClockComponent.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class ClockComponent: public nts::AComponent {
        public:
            ClockComponent(std::string name): AComponent(name) {
                _value = UNDEFINED;
            };
            ~ClockComponent() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin) {
                // if (pin == 1)
                //     _value = TRUE;
                // else
                //     _value = FALSE;
            };

            Tristate _value;
    };
}