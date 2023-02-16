/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** FalseComponent.hpp
*/

#pragma once

#include "../AComponents.hpp"


namespace nts {
    class FalseComponent: public nts::AComponent {
        public:
            FalseComponent(std::string name): AComponent(name) {
                _value = UNDEFINED;
            };
            ~FalseComponent() = default;
            nts::Tristate compute(std::size_t pin);

            void setValue(std::size_t pin);
            Tristate _value;
    };
};