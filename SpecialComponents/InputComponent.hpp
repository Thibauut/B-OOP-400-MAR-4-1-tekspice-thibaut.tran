/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** input.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class InputComponent: public AComponent {
        public:
            InputComponent(std::string name): AComponent(name) {
                _value = UNDEFINED;
            };
            ~InputComponent() = default;
            virtual Tristate compute(std::size_t pin);
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);

        Tristate _value;
    };
}