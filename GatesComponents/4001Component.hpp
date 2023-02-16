/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4001Component.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class Component4001 : public AComponent {
        public:
            Component4001(std::string name): nts::AComponent(name) {};
            ~Component4001() override = default;

            nts::Tristate compute(std::size_t pin);
    };
}