#pragma once
#include <string>
#include <vector>
#include <map>

class Candidat{

private:
	int popularity;
	bool selected = false;
	bool winner = false;
	std::string identity[3];
	std::map<std::string, int> abilities;
	void abilityInit();

public:
	Candidat(std::string nom, int age, std::string description);
	int moyenne();
	Candidat(){};
	//Candidat(const Candidat&);
	void print();
	std::string toString();
	std::map<std::string, int> getAbilities(){ return abilities; };
	void setAbilities(int val, std::string competence){ 
		abilities[competence] = val; 
	};
	void setAbilities(std::map<std::string, int> m){

		abilities = m ; 
	}
	int getPopularity(){ return popularity; };
	bool getWinner(){ return winner; };
	void setWinner(bool win){ winner = win; };
	void setPopularity(int pop){ popularity = pop; };
	bool getSelected(){ return selected; };
	void setSelected(bool select){ selected = select; };
	std::string getName(){ return identity[0]; };
	void operator =(Candidat c);
	bool operator ==(Candidat c);

};
