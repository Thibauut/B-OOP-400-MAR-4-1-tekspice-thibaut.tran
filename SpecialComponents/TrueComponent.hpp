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
            TrueComponent() = default;
            ~TrueComponent() = default;

            nts::Tristate compute(std::size_t pin);
    };
};