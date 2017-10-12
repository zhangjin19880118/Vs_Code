#include<iostream>
using namespace std;

class Config
{
public:
	static Config *getInstance()
	{
		return pConfig;
	}
	int getCount()
	{
		return mCount;
	}
private:
	Config()
	{
		mCount = 0;
		mCount++;
	}

	Config(const Config &config){}
	
	~Config()
	{
		mCount--;
	}

private:
	static Config *pConfig;
	int mCount;
};

Config *Config::pConfig = new Config;

int main(void)
{
	Config *c1 = Config::getInstance();
	Config *c2 = Config::getInstance();

	cout << c1->getCount() << endl;
	cout << c2->getCount() << endl;

	system("pause");
	return 0;
}
