#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Individual{
private:
	int chromoLength;
	vector<int> chromosome;

	string geneX, geneY; //pairs to solve the equation
	long x,y;

	int fitnessRate;
	void setGenes();
	void setPairs();
	int getRealNumber();
	int fitness(int);

	long stringBinToInt(string str);
public:
	Individual();
	Individual(int);
	string getChromo();
	string getXstring();
	string getYstring();
};

#endif