/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Xor.hpp
*/

#pragma once

#include "../AComponents.hpp"

class XorComponent: public nts::AComponent {
    public:
        XorComponent() = default;
        ~XorComponent() = default;
        nts::Tristate compute(std::size_t pin);
};