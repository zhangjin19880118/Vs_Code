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
	cout << "��ѡ������(1:Сľ�� 2����������):" << endl;
	int chooseID = 1;
	cin >> chooseID;
	if (chooseID == 2)
	{
		cout << "����Ǯ!" << endl;
		hero.equipWeapon(&ds);
	}
	else
	{
		cout << "��ţ�ƣ�" << endl;
		hero.equipWeapon(&ws);
	}
	getchar();
	while (true)
	{
		getchar();
		system("cls");
		cout << "��ǰ��" << round << "�غ�:" << endl;
		hero.attackMonster(&monster);
		if (monster.mHp <= 0)
		{
			cout << "��ϲ����˳��ͨ��!" << endl;
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