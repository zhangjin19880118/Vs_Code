#define _CRT_SECURE_NO_WARNINGS
#include"DragonSword.h"
#include"Monster.h"
#include<iostream>
#include<ctime>

DragonSword::DragonSword()
{
	this->mBaseDamage = 50;
	this->mCritRate = 40;
	this->mCritDamage = 30;
	this->mDodge = 50;
	this->mFreezeRate = 30;
	this->mFreezeRound = 1;
	std::strcpy(this->mName, "ÍÀÁú±¦µ¶");
}

void DragonSword::addSpecialEffect(Monster *monster)
{
	srand((unsigned int)std::time(NULL));
	int randRate = rand() % 100 + 1;
	if (randRate > this->mFreezeRate)
		return;
	monster->freezeRound = this->mFreezeRound;
}