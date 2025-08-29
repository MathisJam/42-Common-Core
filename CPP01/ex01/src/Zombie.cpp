#include "../inc/Zombie.hpp"

Zombie::Zombie()
{
    return;
}

Zombie::Zombie(std::string name) : name(name)
{
    return;
}

Zombie::~Zombie()
{
   std::cout << BOLD GREEN << name << ": " << BOLD RED << "has been destroyed 💣" << RESET << std::endl;
}

void Zombie::announce() const
{
    std::cout << BOLD GREEN << name << ": " << "🧟 BraiiiiiiinnnzzzZ... 🧟" << RESET << std::endl;
}