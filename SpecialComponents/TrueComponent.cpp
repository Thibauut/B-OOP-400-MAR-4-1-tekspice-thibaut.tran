/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** TrueComponent.cpp
*/

#include "TrueComponent.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin) {
    if (pin != 1)
        throw Error("False: Pin " + std::to_string(pin) + " doesn't exist");
    return _value;
}
