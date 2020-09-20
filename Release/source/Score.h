#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include<string>
#include<cstdlib>
#include <algorithm>
using namespace std;

class Score
{
private:
	int _score = 0;
	vector<int> _highScore;
public:
	 void setScore(int score = 0) { _score = score; }
	 int getScore() { return _score; }
public:
	void inputHighScoreFromFile();
	void outHighScoreToFile(int score);
public:
	vector<int> getHighScore() {
		return _highScore;
	}
};

