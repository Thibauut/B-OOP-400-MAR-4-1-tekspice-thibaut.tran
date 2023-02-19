/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** output.cpp
*/

#include "OutputComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"

nts::Tristate nts::OutputComponent::compute(std::size_t pin) {
    // AComponent *tmp = dynamic_cast<AComponent*>(this->_pins[1].first);
    // if (typeid(*tmp) == typeid(TrueComponent))
    //     return nts::TRUE;
    // if (typeid(*tmp) == typeid(FalseComponent))
    //     return nts::FALSE;
    return this->_pins[pin].first->compute(this->_pins[pin].second);
}
