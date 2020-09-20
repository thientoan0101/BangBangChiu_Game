#pragma once
#include<iostream>
#include<ctime>

using namespace std;

class Random {
public:
	int next() { return rand(); }
	int next(const int& ceiling) { return rand() % ceiling; }
	int next(const int& min, const int& max) { return min + rand() % (max + 1 - min); }
};