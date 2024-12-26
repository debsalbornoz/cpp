#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) : type(weaponType){}

Weapon::~Weapon() {}

std::string const &Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string weaponType)
{
	type = weaponType;
}