#include"Weapon.h"

int Weapon::getBaseDamage()
{
	return this->mBaseDamage;
}

int Weapon::getCritRate()
{
	return this->mCritRate;
}

int Weapon::getCritDamage()
{
	return this->mCritDamage;
}

int Weapon::getDodge()
{
	return this->mDodge;
}

char *Weapon::getName()
{
	return this->mName;
}

void Weapon::addSpecialEffect(Monster *monster)
{

}

Weapon::~Weapon()
{

}