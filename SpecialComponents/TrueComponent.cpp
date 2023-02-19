/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** TrueComponent.cpp
*/

#include "TrueComponent.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin) {
    return this->_value;
}

void nts::TrueComponent::setValue(std::size_t value) {
    this->_value = nts::TRUE;
}