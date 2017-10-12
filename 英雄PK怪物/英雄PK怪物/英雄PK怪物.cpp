#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"WoodenSword.h"
#include"DragonSword.h"
#include"Hero.h"
#include"Monster.h"
using namespace std;

void Battle()
{
	Hero hero;
	Monster monster;
	int round = 1;
	WoodenSword ws;
	DragonSword ds;
	cout << "ÇëÑ¡ÔñÎäÆ÷(1:Ð¡Ä¾½£ 2£ºÍÀÁú±¦µ¶):" << endl;
	int chooseID = 1;
	cin >> chooseID;
	if (chooseID == 2)
	{
		cout << "ÄãÓÐÇ®!" << endl;
		hero.equipWeapon(&ds);
	}
	else
	{
		cout << "ÄãÅ£±Æ£¡" << endl;
		hero.equipWeapon(&ws);
	}
	getchar();
	while (true)
	{
		getchar();
		system("cls");
		cout << "µ±Ç°µÚ" << round << "»ØºÏ:" << endl;
		hero.attackMonster(&monster);
		if (monster.mHp <= 0)
		{
			cout << "¹§Ï²Äú£¬Ë³ÀûÍ¨¹Ø!" << endl;
			break;
		}
		monster.attackHero(&hero);
		if (hero.mHp <= 0)
		{
			cout << "Game Over!" << endl;
			return;
		}
		++round;
	}
}

int main()
{
	Battle();

	system("pause");
	return EXIT_SUCCESS;
}