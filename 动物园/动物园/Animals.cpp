#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak() = 0;
	virtual ~Animal(){}
};

class Tiger : public Animal
{
public:
	virtual void speak()
	{
		cout << "ÀÏ»¢à»à»à»!" << endl;
	}
};

class Cat : public Animal
{
public:
	virtual void speak()
	{
		cout << "Ð¡Ã¨ß÷ß÷ß÷!" << endl;
	}
};

class Dog : public Animal
{
	virtual void speak()
	{
		cout << "Ð¡¹·ÍúÍúÍú!" << endl;
	}
};

class SheepTuo : public Animal
{
	virtual void speak()
	{
		cout << "ÑòÍÕ³ÁÄ¬²»Óï!" << endl;
	}
};

class Park
{
public:
	Park()
	{
		memset(mAnimal, 0, 10 * sizeof(Animal *));
		mSize = 0;
	}
	void addAnimal(Animal *animal)
	{
		mAnimal[mSize++] = animal;
	}
	void startSpeak()
	{
		for (int i = 0; i < mSize; ++i)
			mAnimal[i]->speak();
	}
	~Park()
	{
		for (int i = 0; i < mSize; ++i)
		{
			delete mAnimal[i];
			mAnimal[i] = NULL;
		}
	}
private:
	Animal *mAnimal[10];
	int mSize;
};

int main(void)
{
	Park *park = new Park;
	
	park->addAnimal(new Tiger);
	park->addAnimal(new Cat);
	park->addAnimal(new Dog);
	park->addAnimal(new Cat);
	park->addAnimal(new Tiger);
	park->addAnimal(new SheepTuo);

	park->startSpeak();

	system("pause");
	return 0;
}
