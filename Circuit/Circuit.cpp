/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"

void addSpecialComponent(std::string name, Parser &component, std::pair<std::string, std::string> x, std::vector<std::unique_ptr<nts::IComponent>> &_components)
{
    if (x.first == "input") {
        std::unique_ptr<nts::IComponent> input = std::make_unique<nts::InputComponent>(name);
        _components.push_back(std::move(input));
        return;
    }
    if (x.first == "output") {
        std::unique_ptr<nts::IComponent> output = std::make_unique<nts::OutputComponent>(name);
        _components.push_back(std::move(output));
        return;
    }
    if (x.first == "false") {
        std::unique_ptr<nts::IComponent> falseComponent = std::make_unique<nts::FalseComponent>(name);
        _components.push_back(std::move(falseComponent));
        return;
    }
    if (x.first == "true") {
        std::unique_ptr<nts::IComponent> trueComponent = std::make_unique<nts::TrueComponent>(name);
        _components.push_back(std::move(trueComponent));
        return;
    }
    if (x.first == "clock") {
        std::unique_ptr<nts::IComponent> clockComponent = std::make_unique<nts::ClockComponent>(name);
        _components.push_back(std::move(clockComponent));
        return;
    }
    return;
}

void nts::Circuit::addComponent(std::string name, Parser &component) {
    for(auto &x: component._chipsets) {
        if (x.second == name) {
            addSpecialComponent(name, component, x, _components);
        }
    }
};

nts::IComponent *nts::Circuit::getComponent(std::string name, Parser &file) const {
    int pos = 0;
    for(auto &x: file._chipsets) {
        if (x.second != name)
            pos++;
        if (x.second == name)
            break;
    }
    auto &component = _components[pos];
    return component.get();
};

std::string displayValue(size_t value)
{
    std::string _value = "";
    if(value == nts::FALSE)
        return _value = "0";
    if(value == nts::TRUE)
        return _value = "1";
    if(value == nts::UNDEFINED)
        return _value = "U";
    return "";
}

void nts::Circuit::display(size_t _tick) const {
    cout << "tick: " << _tick << endl;
    cout << "input(s):" << endl;
    for (auto& component : _components) {
        AComponent* input= dynamic_cast<AComponent*>(component.get());
        if (input != nullptr && typeid(*input) != typeid(OutputComponent)) {
            cout << "  " << input->getName() << ": " << displayValue(input->compute(1)) << endl;
        }
    }
    cout << "output(s):"<< endl;
    for (auto& component : _components) {
        OutputComponent* output= dynamic_cast<OutputComponent*>(component.get());
        if (output != nullptr) {
            cout << "  " << output->getName() << ": " << displayValue(output->compute(1)) << endl;
        }
    }
}