/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** LoggerComponent.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class ComponentLogger : public AComponent {
        public:
            ComponentLogger(std::string name): nts::AComponent(name) {};
            ~ComponentLogger() = default;

            nts::Tristate compute(std::size_t pin);
            void setValue(std::size_t pin);

            nts::Tristate _value;
    };
}