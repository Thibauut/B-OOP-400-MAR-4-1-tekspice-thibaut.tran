/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** false.cpp
*/


#include "FalseComponent.hpp"

nts::Tristate nts::FalseComponent::compute(std::size_t pin) {
    if (pin != 1)
        throw Error("False: Pin " + std::to_string(pin) + " doesn't exist");
    return this->_value;
}
