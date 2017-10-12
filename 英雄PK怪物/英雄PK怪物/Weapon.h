#pragma once

class Monster;

class Weapon
{
public:
	int getBaseDamage();
	int getCritRate();
	int getCritDamage();
	int getDodge();
	char *getName();
	virtual void addSpecialEffect(Monster *monster);
	virtual ~Weapon();
protected:
	int mBaseDamage;
	int mCritRate;
	int mCritDamage;
	int mDodge;
	char mName[64];
};