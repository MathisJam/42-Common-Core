
#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << BOLD YELLOW << "FragTrap constructor called" << RESET << std::endl;
	_hp = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << BOLD YELLOW << "FragTrap " << BOLD MAGENTA << name << BOLD YELLOW << " constructed!" << RESET << std::endl;
	_hp = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
	*this = cpy;
	std::cout << BOLD YELLOW << "FragTrap constructor by copy called" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << BOLD YELLOW << "FragTrap destructor called for " << BOLD MAGENTA << _name << RESET << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_energy <= 0)
	{
		std::cout << BOLD BLUE << "No energy left, " << BOLD GREEN <<"FragTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << BOLD BLUE << "No HP left, FragTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	std::cout << BOLD GREEN << "🤖 FragTrap " << BOLD MAGENTA << this->_name << RED << " attacks " << BOLD BLUE << target << RED <<" causing " << YELLOW << this->_damage <<  RED <<" points of damage 💥🔫" << RESET << std::endl;
	this->_energy -= 1;
}

FragTrap &FragTrap::operator=(const FragTrap &param)
{
	if (this != &param)
	{
		this->_name = param._name;
		this->_hp = param._hp;
		this->_energy = param._energy;
		this->_damage = param._damage;
	}
	return *this;
}

void FragTrap::HighFives()
{
	if (this->_energy <= 0)
	{
		std::cout << BOLD BLUE << "No energy left, FragTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << BOLD BLUE << "No HP left, FragTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	std::cout << BOLD GREEN << "FragTrap " << BOLD MAGENTA << _name << BOLD RED << " is asking for a high-five 🫸" << RESET << std::endl;
	std::cout << BOLD YELLOW << "		🫸  *SLAPPPP* 🫷" << RESET << std::endl;
}
