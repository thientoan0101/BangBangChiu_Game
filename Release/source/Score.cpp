#include "Score.h"

bool compare(int a, int b) { return a > b; }

void Score::inputHighScoreFromFile() {
	ifstream FileIn;
	FileIn.open("./data/Score.txt");
	if (FileIn.fail()) {
		cout << "\n========================File luu diem khong ton tai, vui long tao file Score.txt========================";
		exit(EXIT_FAILURE);
	}

	int score;
	string str_score;
	while (!FileIn.eof()) {
		getline(FileIn, str_score);
		score = atoi(str_score.c_str());
		_highScore.push_back(score);
	}
	_highScore.resize(10);
	sort(_highScore.begin(), _highScore.end(),compare);

	FileIn.close();
}

void Score::outHighScoreToFile(int score) {
	ofstream FileOut;
	FileOut.open("./data/Score.txt");
	_highScore.push_back(score);
	sort(_highScore.begin(), _highScore.end(),compare);
	//_highScore.resize(10,0);

	for (int i = 0; i < _highScore.size(); i++) {
		FileOut << _highScore.at(i) << endl;
	}

	FileOut.close();
 }