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
	std::strcpy(this->mName, "����");
}

void Monster::attackHero(Hero *hero)
{
	if (this->freezeRound > 0)
	{
		std::cout << "����<<" << this->mName << ">>�����������غ��޷����й���!" << std::endl;
		this->freezeRound--;
		return;
	}
	if (isRate(hero->mDodge))
	{
		std::cout << "Ӣ��<<" << hero->mName << ">>����˹���<<" << this->mName << ">>������һ��!" << std::endl;
		return;
	}
	int damage = this->mBase - hero->mDefense;
	hero->mHp -= damage;
	std::cout << "����<<" << this->mName << ">>��Ӣ��<<" << hero->mName << ">>�����" << damage << "���˺�!" << std::endl;
	Monster::sDamage += damage;
	std::cout << "����<<" << this->mName << ">>��Ӣ��<<" << hero->mName << ">>�ۼ������" << Monster::sDamage << "���˺�!" << std::endl;
}

bool Monster::isRate(int rate, int rateLimit)
{
	srand((unsigned int)time(NULL));
	int CritRate = rand() % rateLimit + 1;
	if (CritRate > rate)
		return false;
	return true;
}