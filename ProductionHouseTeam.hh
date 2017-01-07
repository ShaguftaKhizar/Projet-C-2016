#pragma once
#include "Killer.hh"
#include "Victim.hh"
#include <string>
//#include "number.hh"


using namespace std;

template <class T>
class ProductionHouseTeam : public Killer<T>{

public:
	ProductionHouseTeam(int _capacityKill, int _memberNumber, std::vector<T> _teamMember);
	void lowerPopularity(Victim<Candidat>&);
	Candidat candidatKill(Victim<Candidat>&) const;
	std::string toString() const;
};



template <class T> 
ProductionHouseTeam<T>::ProductionHouseTeam(int _capacityKill, int _memberNumber, std::vector<T> _teamMember) : Killer<T>(_capacityKill, _memberNumber,  _teamMember)
{
	Team<T>::teamNumber = val_team();

	Killer<T>::proAbilities["Wild"] = rand()%101; 
	Killer<T>::proAbilities["Nature"] = rand()%101; 
	Killer<T>::proAbilities["Talent"] = rand()%101; 
	Killer<T>::proAbilities["Personality"] = rand()%101; 
	Killer<T>::proAbilities["Swimming"] = rand()%101; 
	Killer<T>::proAbilities["Speed"] = rand()%101; 

}

template <class T> 
void ProductionHouseTeam<T>::lowerPopularity(Victim<Candidat>& t1){

	vector<Candidat> lc = t1.getTeamMember();

	for(auto it : lc){

		int pop = (it.getPopularity() - 10);
		it.setPopularity(pop);

	}	

}
template <class T> 
Candidat ProductionHouseTeam<T>::candidatKill(Victim<Candidat>& v1) const{

	Candidat c("ZERO", 0, "ZERO");
	vector<Candidat> lc = v1.getTeamMember();

	for(auto it : lc){

		if(it.getPopularity() <= (20*Killer<T>::capacityKill))
			return it;

	}

	return c;
}
template <class T> 
string ProductionHouseTeam<T>::toString() const{

	string s;
	
	s += "Capacity kill : " + to_string(Killer<T>::capacityKill) + " %\n";
	s += "Team members : \n";
	
	for(auto it : Team<T>::teamMember)
		s += it.toString(); 
	
	return s;
}
