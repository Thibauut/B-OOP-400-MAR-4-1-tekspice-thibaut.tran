/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Or.hpp
*/

#pragma once

#include "../AComponents.hpp"

class OrComponent : public nts::AComponent {
    public:
        OrComponent() = default;
        ~OrComponent() = default;
        nts::Tristate compute(std::size_t pin);
};