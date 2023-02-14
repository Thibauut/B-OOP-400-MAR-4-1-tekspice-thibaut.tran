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
            FalseComponent() = default;
            ~FalseComponent() = default;

            nts::Tristate compute(std::size_t pin);
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
    };
};