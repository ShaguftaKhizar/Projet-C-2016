#pragma once
#include "Killer.hh"
#include "Candidat.hh"
#include "Victim.hh"

#include <string>
#include <list>

using namespace std;

template <class T>
class Jury_Team : public Killer<T>{

public:
	Jury_Team(int _capacityKill, int _memberNumber, std::list<T> _teamMember);
	void lowerSkills(Victim<Candidat>& t1);
	Candidat candidatKill(Victim<Candidat>& v1)const;
	std::string toString() const;

};


template <class T>
Jury_Team<T>::Jury_Team(int _capacityKill, int _memberNumber, std::list<T> _teamMember) : Killer<T>(_capacityKill, _memberNumber,  _teamMember)
{

	Killer<T>::proAbilities["Wild"] = rand()%101; 
	Killer<T>::proAbilities["Nature"] = rand()%101; 
	Killer<T>::proAbilities["Talent"] = rand()%101; 
	Killer<T>::proAbilities["Personality"] = rand()%101; 
	Killer<T>::proAbilities["Swimming"] = rand()%101; 
	Killer<T>::proAbilities["Speed"] = rand()%101; 

}

template <class T>
void Jury_Team<T>::lowerSkills(Victim<Candidat>& t1){

	list<Candidat> lc = t1.getTeamMember();

	for(auto it : lc){

		map<string, int> abilit = it.getAbilities();

		for(auto it2 : abilit)
		{
			it2.second -= 10;
		}

	}	

}
template <class T>
Candidat Jury_Team<T>::candidatKill(Victim<Candidat>& v1) const {

	Candidat c("ZERO", 0, "ZERO");
		
	list<Candidat> lc = v1.getTeamMember();
	map<string, int>::const_iterator itLow;// itUpper;
//https://www.linuxmint.com/start/rosa/
	for(auto it : lc){

		map<string, int> abilit = it.getAbilities();
		itLow = abilit.lower_bound("Walk");
		//itUpper = Killer::proAbilities.upper_bound("Wild");
		
		if(itLow->second < (10*Killer<T>::capacityKill))
			return it;

	}

	return c;
}

template <class T>
string Jury_Team<T>::toString() const{

	string s;
	
	s += "Capacity kill : " + to_string(Killer<T>::capacityKill) + " %\n";
	s += "Team members : \n";

	for(auto it : Team<T>::teamMember)
		s += it.toString(); 
	
	return s;
}

