/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** LoggerComponent.cpp
*/

#include "LoggerComponent.hpp"

nts::Tristate nts::ComponentLogger::compute(std::size_t pin) {
    return this->_value;
}

void nts::ComponentLogger::setValue(std::size_t value) {
    this->_value = nts::UNDEFINED;
}