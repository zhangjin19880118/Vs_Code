#define _CRT_SECURE_NO_WARNINGS
#include"Hero.h"
#include"Monster.h"
#include<iostream>
#include<ctime>

int Hero::sDamage = 0;

Hero::Hero()
{
	this->mHp = 500;
	this->mBase = 40;
	this->mDefense = 30;
	this->mCritRate = 20;
	this->mCritDamage = 20;
	this->mDodge = 20;
	this->pWeapon = NULL;
	std::strcpy(this->mName, "�黨��");
}

void Hero::equipWeapon(Weapon *weapon)
{
	if (weapon == this->pWeapon)
		return;
	if (this->pWeapon != NULL)
	{
		this->mBase -= this->pWeapon->getBaseDamage();
		this->mCritRate -= this->pWeapon->getCritRate();
		this->mCritDamage -= this->pWeapon->getCritDamage();
		this->mDodge -= this->pWeapon->getDodge();
		delete this->pWeapon;
		this->pWeapon = NULL;
	}
	this->pWeapon = weapon;
	std::cout << "װ������<<" << this->pWeapon->getName() << ">>,Ӣ�����Ա仯����:" << std::endl;
	std::cout << "������:" << this->mBase << "+" << this->pWeapon->getBaseDamage() << std::endl;
	std::cout << "������:" << this->mCritRate << "+" << this->pWeapon->getCritRate() << std::endl;
	std::cout << "�����˺�:" << this->mCritDamage << "+" << this->pWeapon->getCritDamage() << std::endl;
	std::cout << "������:" << this->mDodge << "+" << this->pWeapon->getDodge() << std::endl;
	this->mBase += this->pWeapon->getBaseDamage();
	this->mCritRate += this->pWeapon->getCritRate();
	this->mCritDamage += this->pWeapon->getCritDamage();
	this->mDodge += this->pWeapon->getDodge();
}

void Hero::attackMonster(Monster *monster)
{
	if (this->pWeapon != NULL)
		this->pWeapon->addSpecialEffect(monster);
	int total = this->mBase;
	if (isRate(this->mCritRate))
	{
		std::cout << "Ӣ��<<" << this->mName << ">>�Թ���<<" << monster->mName << ">>���������һ��!" << std::endl;
		total += total*this->mCritDamage / 100;
	}
	total -= monster->mDefense;
	monster->mHp -= total;
	std::cout << "Ӣ��<<" << this->mName << ">>�Թ���<<" << monster->mName << ">>�����" << total << "���˺�" << std::endl;
	Hero::sDamage += total;
	std::cout << "Ӣ��<<" << this->mName << ">>�Թ���<<" << monster->mName << ">>�ۼ������" << Hero::sDamage << "���˺�" << std::endl;
}

bool Hero::isRate(int rate, int rateLimit)
{
	srand((unsigned int)time(NULL));
	int CritRate = rand() % rateLimit + 1;
	if (CritRate > rate)
		return false;
	return true;
}