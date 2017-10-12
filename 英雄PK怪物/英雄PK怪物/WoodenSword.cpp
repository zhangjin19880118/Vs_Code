#define _CRT_SECURE_NO_WARNINGS
#include"WoodenSword.h"
#include<iostream>

WoodenSword::WoodenSword()
{
	this->mBaseDamage = 30;
	this->mCritRate = 20;
	this->mCritDamage = 20;
	this->mDodge = 30;
	std::strcpy(this->mName, "Ð¡Ä¾½£");
}