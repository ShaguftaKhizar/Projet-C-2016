#pragma once
#include <string>
#include <vector>
#include <map>

class Candidat{

private:
	int popularity;
	bool selected = false;
	std::string identity[3];
	std::map<std::string, int> abilities;
	void abilityInit();

public:
	Candidat(std::string nom, int age, std::string description);
	Candidat(){};
	//Candidat(const Candidat&);
	void print();
	std::string toString();
	std::map<std::string, int> getAbilities(){ return abilities; };
	int getPopularity(){ return popularity; };
	void setPopularity(int pop){ popularity = pop; };
	bool getSelected(){ return selected; };

};