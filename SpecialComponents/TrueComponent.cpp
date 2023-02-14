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
    return nts::TRUE;
}

void nts::TrueComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin != 1)
        throw Error("False: Pin " + std::to_string(pin) + " doesn't exist");
    AComponent *tmp = dynamic_cast<AComponent*>(&other);
    this->_pins[pin] = std::make_pair(&other, otherPin);
    tmp->_pins[otherPin] = std::make_pair(this, pin);
}