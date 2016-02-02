#include "Individual.cpp"
#include "Population.h"

Population::Population(){
	generation = 0;
	populationSize = 0;
}

void Population::setGeneration(int gen){
	generation = gen;
}

void Population::setPopulationSize(int size){
	populationSize =  size;
	setPopulation();
}

void Population::setPopulation(){
	for(int i = 0; i < populationSize; i++){
		Individual *element = new Individual(6);
		individuals.push_back(*element);
	}
	removeTwins();
}

void Population::removeTwins(){
	for(int i = 0; i < individuals.size(); i++){
		int j;
		for(j = i+1; j < individuals.size(); j++){
			if(individuals[i].getChromo() == individuals[j].getChromo()){
				individuals.erase(individuals.begin()+j);
				i = 0;
				j = i+1;
			}
		}
	}
}

void Population::showPopulation(){
	for(int i = 0; i < individuals.size(); i++){
		if(i < 9) cout << " ";
		if(i < 99) cout << " ";
		cout << i+1 << ") " << individuals[i].getChromo() << endl;
	}
}