/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4512Component.cpp
*/

#include "4512Component.hpp"

nts::Tristate nts::Component4512::compute(std::size_t pin) {
    nts::Tristate inputA = this->_pins[11].first->compute(this->_pins[11].second);
    nts::Tristate inputB = this->_pins[12].first->compute(this->_pins[12].second);
    nts::Tristate inputC = this->_pins[13].first->compute(this->_pins[13].second);
    nts::Tristate inputEnable = this->_pins[15].first->compute(this->_pins[15].second);
    nts::Tristate inputInhibit = this->_pins[10].first->compute(this->_pins[10].second);
    nts::Tristate output;
    if (inputInhibit == 1) {
        return output = FALSE;
    } else if (inputEnable == 1) {
        return output = UNDEFINED;
    } else {
        if (inputA == 0 && inputB == 0 && inputC == 0)
            return output = this->_pins[1].first->compute(this->_pins[1].second);
        if (inputA == 1 && inputB == 0 && inputC == 0)
            return output = this->_pins[2].first->compute(this->_pins[2].second);
        if (inputA == 0 && inputB == 1 && inputC == 0)
            return output = this->_pins[3].first->compute(this->_pins[3].second);
        if (inputA == 1 && inputB == 1 && inputC == 0)
            return output = this->_pins[4].first->compute(this->_pins[4].second);
        if (inputA == 0 && inputB == 0 && inputC == 1)
            return output = this->_pins[5].first->compute(this->_pins[5].second);
        if (inputA == 1 && inputB == 0 && inputC == 1)
            return output = this->_pins[6].first->compute(this->_pins[6].second);
        if (inputA == 0 && inputB == 1 && inputC == 1)
            return output = this->_pins[7].first->compute(this->_pins[7].second);
        if (inputA == 1 && inputB == 1 && inputC == 1)
            return output = this->_pins[9].first->compute(this->_pins[9].second);
    }
    return this->_value;
}
