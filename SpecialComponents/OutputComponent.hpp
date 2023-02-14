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
            OutputComponent() = default;
            ~OutputComponent() = default;
            nts::Tristate compute(std::size_t pin);
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
    };
}