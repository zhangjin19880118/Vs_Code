#pragma once
#include"Weapon.h"

class Hero
{
public:
	Hero();
	void equipWeapon(Weapon *weapon);
	void attackMonster(Monster *monster);
	bool isRate(int rate, int rateLimit = 100);
public:
	int mHp;
	int mDefense;
	int mBase;
	int mCritRate;
	int mCritDamage;
	int mDodge;
	Weapon *pWeapon;
	char mName[64];
	static int sDamage;
};
