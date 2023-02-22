/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4514Component.cpp
*/

#include "4514Component.hpp"

nts::Tristate nts::Component4514::compute(std::size_t pin) {
    nts::Tristate inputStrobe = this->_pins[1].first->compute(this->_pins[1].second);
    nts::Tristate input2 = this->_pins[2].first->compute(this->_pins[2].second);
    nts::Tristate input3 = this->_pins[3].first->compute(this->_pins[3].second);
    nts::Tristate input21 = this->_pins[21].first->compute(this->_pins[21].second);
    nts::Tristate input22 = this->_pins[22].first->compute(this->_pins[22].second);
    nts::Tristate inputInhibit = this->_pins[23].first->compute(this->_pins[23].second);

    if (inputStrobe == nts::Tristate::TRUE)
        return this->_value;
    if (inputInhibit == nts::Tristate::TRUE)
        return this->_value;

    nts::Tristate output0 = UNDEFINED;
    nts::Tristate output1 = UNDEFINED;
    nts::Tristate output2 = UNDEFINED;
    nts::Tristate output3 = UNDEFINED;
    nts::Tristate output4 = UNDEFINED;
    nts::Tristate output5 = UNDEFINED;
    nts::Tristate output6 = UNDEFINED;
    nts::Tristate output7 = UNDEFINED;
    nts::Tristate output8 = UNDEFINED;
    nts::Tristate output9 = UNDEFINED;
    nts::Tristate output10 = UNDEFINED;
    nts::Tristate output11 = UNDEFINED;
    nts::Tristate output12 = UNDEFINED;
    nts::Tristate output13 = UNDEFINED;
    nts::Tristate output14 = UNDEFINED;
    nts::Tristate output15 = UNDEFINED;
    nts::Tristate output16 = UNDEFINED;


    if (input22 == nts::Tristate::TRUE) {
        output0 = FALSE;
        output1 = FALSE;
        output2 = FALSE;
        output3 = FALSE;
        output4 = FALSE;
        output5 = FALSE;
        output6 = FALSE;
        output7 = FALSE;
        output8 = FALSE;
        output9 = FALSE;
        output10 = FALSE;
        output11 = FALSE;
        output12 = FALSE;
        output13 = FALSE;
        output14 = FALSE;
        output15 = FALSE;
        output16 = FALSE;
    }

    if (input2 == nts::Tristate::FALSE && input3 == nts::Tristate::FALSE && input21 == nts::Tristate::FALSE && input22 == nts::Tristate::FALSE)
        output0 = TRUE;
    if (input2 == nts::Tristate::FALSE && input3 == nts::Tristate::FALSE && input21 == nts::Tristate::FALSE && input22 == nts::Tristate::TRUE)
        output1 = TRUE;
    if (input2 == nts::Tristate::FALSE && input3 == nts::Tristate::FALSE && input21 == nts::Tristate::TRUE && input22 == nts::Tristate::FALSE)
        output2 = TRUE;
    if (input2 == nts::Tristate::FALSE && input3 == nts::Tristate::FALSE && input21 == nts::Tristate::TRUE && input22 == nts::Tristate::TRUE)
        output3 = TRUE;
    if (input2 == nts::Tristate::FALSE && input3 == nts::Tristate::TRUE && input21 == nts::Tristate::FALSE && input22 == nts::Tristate::FALSE)
        output4 = TRUE;
    if (input2 == nts::Tristate::FALSE && input3 == nts::Tristate::TRUE && input21 == nts::Tristate::FALSE && input22 == nts::Tristate::TRUE)
        output5 = TRUE;
    if (input2 == nts::Tristate::FALSE && input3 == nts::Tristate::TRUE && input21 == nts::Tristate::TRUE && input22 == nts::Tristate::FALSE)
        output6 = TRUE;
    if (input2 == nts::Tristate::FALSE && input3 == nts::Tristate::TRUE && input21 == nts::Tristate::TRUE && input22 == nts::Tristate::TRUE)
        output7 = TRUE;
    if (input2 == nts::Tristate::TRUE && input3 == nts::Tristate::FALSE && input21 == nts::Tristate::FALSE && input22 == nts::Tristate::FALSE)
        output8 = TRUE;
    if (input2 == nts::Tristate::TRUE && input3 == nts::Tristate::FALSE && input21 == nts::Tristate::FALSE && input22 == nts::Tristate::TRUE)
        output9 = TRUE;
    if (input2 == nts::Tristate::TRUE && input3 == nts::Tristate::FALSE && input21 == nts::Tristate::TRUE && input22 == nts::Tristate::FALSE)
        output10 = TRUE;
    if (input2 == nts::Tristate::TRUE && input3 == nts::Tristate::FALSE && input21 == nts::Tristate::TRUE && input22 == nts::Tristate::TRUE)
        output11 = TRUE;
    if (input2 == nts::Tristate::TRUE && input3 == nts::Tristate::TRUE && input21 == nts::Tristate::FALSE && input22 == nts::Tristate::FALSE)
        output12 = TRUE;
    if (input2 == nts::Tristate::TRUE && input3 == nts::Tristate::TRUE && input21 == nts::Tristate::FALSE && input22 == nts::Tristate::TRUE)
        output13 = TRUE;
    if (input2 == nts::Tristate::TRUE && input3 == nts::Tristate::TRUE && input21 == nts::Tristate::TRUE && input22 == nts::Tristate::FALSE)
        output14 = TRUE;
    if (input2 == nts::Tristate::TRUE && input3 == nts::Tristate::TRUE && input21 == nts::Tristate::TRUE && input22 == nts::Tristate::TRUE)
        output15 = TRUE;

    if (pin == 4)
        return this->_value = output7;
    if (pin == 5)
        return this->_value = output6;
    if (pin == 6)
        return this->_value = output5;
    if (pin == 7)
        return this->_value = output4;
    if (pin == 8)
        return this->_value = output3;
    if (pin == 9)
        return this->_value = output1;
    if (pin == 10)
        return this->_value = output2;
    if (pin == 11)
        return this->_value = output0;
    if (pin == 13)
        return this->_value = output13;
    if (pin == 14)
        return this->_value = output12;
    if (pin == 15)
        return this->_value = output15;
    if (pin == 16)
        return this->_value = output14;
    if (pin == 17)
        return this->_value = output9;
    if (pin == 18)
        return this->_value = output8;
    if (pin == 19)
        return this->_value = output11;
    if (pin == 20)
        return this->_value = output10;
    return this->_value;
}

void nts::Component4514::setValue(std::size_t value) {}