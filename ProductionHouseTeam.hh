#pragma once
#include "Killer.hh"
#include "Victim.hh"
#include <string>
#include "number.hh"
#include <iostream>


using namespace std;

template <class T>
class ProductionHouseTeam : public Killer<T>{

public:
	ProductionHouseTeam(int _capacityKill, int _memberNumber, std::vector<T> _teamMember);
	ProductionHouseTeam(Killer<T>& k1);
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
ProductionHouseTeam<T>::ProductionHouseTeam(Killer<T>& k1) : Killer<T>(k1.getCapacityKill(), k1.getMemberNumber(),  k1.getTeamMember())
{
	Team<T>::teamNumber = k1.getTeamNumber();
	Killer<T>::proAbilities = k1.getProAbilities();

}


template <class T> 
void ProductionHouseTeam<T>::lowerPopularity(Victim<Candidat>& t1){

	vector<Candidat> lc = t1.getTeamMember();
	vector<Candidat> :: iterator iter;

	for(iter = lc.begin() ; iter != lc.end()  ; ++ iter){
		//cout << "avant "<< to_string(it.getPopularity()) << endl;
		
		int pop = (iter->getPopularity() - 10);
		if(iter->getPopularity() < 0)
			iter->setPopularity(0);
		iter->setPopularity(pop);
		
		cout << "Pop pendant " << to_string(pop) << endl;
	}	
	t1.setTeamMember(lc);
}
template <class T> 
Candidat ProductionHouseTeam<T>::candidatKill(Victim<Candidat>& v1) const{

	Candidat c("ZERO", 0, "ZERO");
	vector<Candidat> lc = v1.getTeamMember();

	for(auto it : lc){

		if(it.getPopularity() <= Killer<T>::capacityKill)
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
