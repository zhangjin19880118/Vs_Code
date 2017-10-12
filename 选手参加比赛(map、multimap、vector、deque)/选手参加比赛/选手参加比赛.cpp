#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
using namespace std;

class Player
{
public:
	string mName;
	int score[3];
};

void CreatePlayers(vector<int> &vID, map<int, Player> &mPlayer)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";
	for (int i = 0; i < nameSeed.size(); ++i)
	{
		Player p;
		p.mName = "Ñ¡ÊÖ";
		p.mName += nameSeed[i];
		for (int j = 0; j < 3; ++j)
			p.score[j] = 0;
		int joinID = i + 100;
		vID.push_back(joinID);
		mPlayer.insert(make_pair(joinID, p));
	}
}

void randPlayers(vector<int> &vID)
{
	srand((unsigned int)time(NULL));
	random_shuffle(vID.begin(), vID.end());
}

void printPlayers(int round, vector<int> &vLevelID, map<int, Player> &mPlayer)
{
	for (auto id : vLevelID)
		cout << mPlayer[id].mName << " " << mPlayer[id].score[round - 1] << endl;
	cout << "-------------" << endl;
}

void match(int round, vector<int> &vID,vector<int> &vLevelID, map<int, Player> &mPlayer)
{
	srand((unsigned int)time(NULL));
	multimap <int, int, greater<int>> mRound;
	for (vector<int>::iterator it = vID.begin(); it != vID.end(); ++it)
	{
		deque<int> dScores;
		for (int i = 0; i < 10; ++i)
		{
			int score = rand() % 51 + 50;
			dScores.push_back(score);
		}
		sort(dScores.begin(), dScores.end());
		dScores.pop_back();
		dScores.pop_front();
		int ave = accumulate(dScores.begin(), dScores.end(), 0) / dScores.size();
		mPlayer[*it].score[round-1] = ave;
		mRound.insert(make_pair(ave, *it));
		if (it == vID.end() - 1)
		{
			int countLevel = mRound.size() / 2;
			multimap <int, int, greater<int>>::iterator mit = mRound.begin();
			for (int j = 0; j < countLevel; ++j)
			{
				vLevelID.push_back(mit->second);
				++mit;
			}
			mRound.clear();
		}
	}
	vID = vLevelID;
}

int main(void)
{
	vector<int> vID;
	map<int, Player> mPlayer;

	vector<int> vLevelID;
	vector<int> vLevelID1;
	vector<int> vLevelID2;
	vector<int> vLevelID3;

	CreatePlayers(vID, mPlayer);

	randPlayers(vID);
	match(1, vID, vLevelID1, mPlayer);
	printPlayers(1, vLevelID1, mPlayer);

	randPlayers(vLevelID1);
	match(2, vLevelID1, vLevelID2, mPlayer);
	printPlayers(2, vLevelID2, mPlayer);

	randPlayers(vLevelID2);
	match(3, vLevelID2, vLevelID3, mPlayer);
	printPlayers(3, vLevelID3, mPlayer);

	system("pause");
	return 0;
}
