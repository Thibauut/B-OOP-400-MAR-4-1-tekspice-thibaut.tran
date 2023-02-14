/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** And.hpp
*/

#pragma once

#include "../AComponents.hpp"

namespace nts {
    class AndComponent: public nts::AComponent {
        public:
            // AndComponent(): nts::AComponent("AndComponent", 3) {
            // }
            AndComponent() = default;
            ~AndComponent() = default;
            nts::Tristate compute(std::size_t pin);
    };
}
