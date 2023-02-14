/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** NotComponent.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class NotComponent: public nts::AComponent {
        public:
            NotComponent() = default;
            ~NotComponent() = default;
            nts::Tristate compute(std::size_t pin);
    };
}
