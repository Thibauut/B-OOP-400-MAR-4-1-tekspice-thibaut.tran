/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::Tristate nts::ClockComponent::compute(std::size_t pin) {
    if (pin != 1)
        throw Error("Clock: Pin " + std::to_string(pin) + " doesn't exist");
    return this->_value;
}
