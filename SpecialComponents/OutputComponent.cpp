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
    return this->_pins[pin].first->compute(this->_pins[pin].second);
}
