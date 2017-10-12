#define _CRT_SECURE_NO_WARNINGS
#include"Monster.h"
#include<iostream>
#include<ctime>

int Monster::sDamage = 0;

Monster::Monster()
{
	this->mHp = 2000;
	this->mBase = 50;
	this->mDefense = 40;
	this->freezeRound = 0;
	std::strcpy(this->mName, "马云");
}

void Monster::attackHero(Hero *hero)
{
	if (this->freezeRound > 0)
	{
		std::cout << "怪物<<" << this->mName << ">>被冰冻，本回合无法进行攻击!" << std::endl;
		this->freezeRound--;
		return;
	}
	if (isRate(hero->mDodge))
	{
		std::cout << "英雄<<" << hero->mName << ">>躲避了怪物<<" << this->mName << ">>的致命一击!" << std::endl;
		return;
	}
	int damage = this->mBase - hero->mDefense;
	hero->mHp -= damage;
	std::cout << "怪物<<" << this->mName << ">>对英雄<<" << hero->mName << ">>造成了" << damage << "点伤害!" << std::endl;
	Monster::sDamage += damage;
	std::cout << "怪物<<" << this->mName << ">>对英雄<<" << hero->mName << ">>累计造成了" << Monster::sDamage << "点伤害!" << std::endl;
}

bool Monster::isRate(int rate, int rateLimit)
{
	srand((unsigned int)time(NULL));
	int CritRate = rand() % rateLimit + 1;
	if (CritRate > rate)
		return false;
	return true;
}