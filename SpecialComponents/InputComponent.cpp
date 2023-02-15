/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** input.cpp
*/

#include "InputComponent.hpp"

nts::Tristate nts::InputComponent::compute(std::size_t pin) {
    if (pin != 1)
        Error::myErr("Input: Pin " + std::to_string(pin) + " doesn't exist");
    return this->_value;
};
