#pragma once
#include"Weapon.h"

class DragonSword : public Weapon
{
public:
	DragonSword();
	virtual void addSpecialEffect(Monster *monster);
private:
	int mFreezeRate;
	int mFreezeRound;
};