/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** AComponents.hpp
*/

#pragma once

#include "IComponents.hpp"

namespace nts {
    class AComponent: public virtual nts::IComponent {
        public:
            // AComponent(std::string &gates): _gates(gates) {
            //     _gates = gates;
            // };
            AComponent() {};
            ~AComponent() {};

            void simulate(std::size_t tick) {};
            virtual nts::Tristate compute(std::size_t pin = 1) { return nts::Tristate::UNDEFINED; };
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {};

        protected:
            std::string _gates;
            size_t pin;

    };
};