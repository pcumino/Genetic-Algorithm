#include "Individual.h"
#include <string>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void stringBinToInt();

Individual::Individual(){
	// Default constructor
	// Initialization with no input/entry
	chromoLength = pow(2,4);
	setPairs();
}
Individual::Individual(int n){
	chromoLength = pow(2,n);
	setPairs();
}
void Individual::setGenes(){ for(int i = 0; i < chromoLength; i++) chromosome.push_back(rand() % 2);}

// setting values for x and y from the equation
void Individual::setPairs(){
	setGenes();
	ostringstream ossX, ossY;
	if (!chromosome.empty()){
		copy(chromosome.begin(),
				chromosome.end()-(chromoLength/2),
				ostream_iterator<int>(ossX));
		ossX << chromosome.back();
		copy(chromosome.begin()+(chromoLength/2),
				chromosome.end(),
				ostream_iterator<int>(ossY));
		ossY << chromosome.back();
	}

	geneX = ossX.str().erase((chromoLength/2)-1,1);
	geneY = ossY.str().erase((chromoLength/2)-1,1);
}

string Individual::getChromo(){return geneX+geneY;}
string Individual::getXstring(){x = stringBinToInt(geneX);return geneX;}
string Individual::getYstring(){y = stringBinToInt(geneY);return geneY;}

long Individual::stringBinToInt(string str){
    long parsed = strtol(str.c_str(), NULL, 2);
    return parsed;
}
