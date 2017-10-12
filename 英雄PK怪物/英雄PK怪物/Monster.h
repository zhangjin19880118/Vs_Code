#pragma once
#include"Hero.h"

class Monster
{
public:
	Monster();
	void attackHero(Hero *hero);
	bool isRate(int rate, int rateLimit = 100);
public:
	int mHp;
	int mDefense;
	int mBase;
	int freezeRound;
	char mName[64];
	static int sDamage;
};