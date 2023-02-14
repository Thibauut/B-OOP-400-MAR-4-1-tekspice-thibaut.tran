/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Circuit.hpp
*/

#pragma once

#include "../IComponents.hpp"
#include "../SpecialComponents/InputComponent.hpp"
#include "../SpecialComponents/OutputComponent.hpp"

namespace nts {
    class Circuit: public IComponent {
        public:
            Circuit() = default;
            ~Circuit() {};

            // IComponent
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {};
            nts::Tristate compute(std::size_t pin) {};
            void simulate(std::size_t tick) {};
            // void setInput(std::size_t pin, nts::Tristate value);

            // Circuit
            void addComponent(std::string name, Parser &component) {
                for(auto &x: component._chipsets) {
                    if (x.second == name) {
                        if (x.first == "input") {
                            std::unique_ptr<AComponent> input = std::make_unique<nts::InputComponent>(name);
                            _components.push_back(std::move(input));
                            return;
                        }
                    }
                }
                // if (name == "input") {
                //     std::unique_ptr<IComponent> input = std::make_unique<nts::InputComponent>(name);
                //     _components.push_back(input);
                //     return;
                // }
                //  if (name == "output") {
                //     std::unique_ptr<IComponent> output = std::make_unique<nts::OutputComponent>(name);
                //     _components.push_back(output);
                //     return;
                // }
            };


            // nts::IComponent *findComponent(std::string name) const {
            //     for (auto &x: _components) {
            //         if (x->getName() == name)
            //             return x.get();
            //     }
            //     return nullptr;
            // };
            // Getters
            // std::string getName() const { return _name; };
            // std::vector<std::unique_ptr<IComponent>> getComponents() const { return _components; };

            // Setters
            // void setName(std::string name) { _name = name; };
            // void setComponents(std::vector<std::unique_ptr<IComponent>> components) { _components = components; };

            // Variables
            protected:
                std::vector<std::unique_ptr<IComponent>> _components;
    };
};