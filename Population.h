#ifndef POPULATION_H
#define POPULATION_H

class Population{
private:
	int generation;
	int populationSize;
	vector<Individual> individuals;

	void setGeneration(int);
	void setPopulation();
	void removeTwins();
public:
	Population();
	void setPopulationSize(int);

	void showPopulation();
};

#endif