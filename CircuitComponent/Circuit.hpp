/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Circuit.hpp
*/

#include "../IComponents.hpp"

namespace nts {
    class Circuit: public IComponent {
        public:
            Circuit() {};
            Circuit(std::string name) : _name(name) {};
            ~Circuit() {};

            // IComponent
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void setInput(std::size_t pin, nts::Tristate value);
            nts::Tristate compute(std::size_t pin);

            // Circuit
            void addComponent(std::string name);
            nts::IComponent findComponent(std::string name) const;
            void simulate() const;

            // Getters
            std::string getName() const { return _name; };
            std::vector<std::unique_ptr<IComponent>> getComponents() const { return _components; };

            // Setters
            void setName(std::string name) { _name = name; };
            void setComponents(std::vector<std::unique_ptr<IComponent>> components) { _components = components; };

            // Variables
            protected:
                std::string _name;
                std::vector<std::unique_ptr<IComponent>> _components;
    };
};