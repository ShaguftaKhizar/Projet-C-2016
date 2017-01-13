#pragma once
#include "Killer.hh"
#include "Candidat.hh"
#include "Victim.hh"
#include "number.hh"

#include <string>
#include <vector>

using namespace std;

template <class T>
class Jury_Team : public Killer<T>{

public:
	Jury_Team(int _capacityKill, int _memberNumber, std::vector<T> _teamMember);
	Jury_Team(Killer<T>& k1);
	void lowerSkills(Victim<Candidat>& t1);
	Candidat candidatKill(Victim<Candidat>& v1)const;
	std::string toString() const;

};


template <class T>
Jury_Team<T>::Jury_Team(int _capacityKill, int _memberNumber, std::vector<T> _teamMember) : Killer<T>(_capacityKill, _memberNumber,  _teamMember)
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
Jury_Team<T>::Jury_Team(Killer<T>& k1) : Killer<T>(k1.getCapacityKill(), k1.getMemberNumber(),  k1.getTeamMember())
{
	Team<T>::teamNumber = k1.getTeamNumber();
	Killer<T>::proAbilities = k1.getProAbilities();

}

template <class T>
void Jury_Team<T>::lowerSkills(Victim<Candidat>& t1){

	vector<Candidat> lc = t1.getTeamMember();
	vector<Candidat> :: iterator iter;
	map<std::string, int> m ;
	map<std::string, int> :: iterator it2;
	

	for(iter = lc.begin() ; iter != lc.end()  ; ++ iter){

		m = iter->getAbilities();
		for(it2 = m.begin(); it2 != m.end(); it2++)
		{
			it2->second -= 10;
			if(it2->second < 0){
				it2->second = 0;
			}
		}
		iter->setAbilities(m);

	}	
	t1.setTeamMember(lc);

}
template <class T>
Candidat Jury_Team<T>::candidatKill(Victim<Candidat>& v1) const {

	Candidat c("ZERO", 0, "ZERO");
		
	vector<Candidat> lc = v1.getTeamMember();
	map<string, int>::const_iterator itLow;

	for(auto it : lc){

		map<string, int> abilit = it.getAbilities();
		itLow = abilit.lower_bound("Walk");
			
		if(itLow->second < (10*Killer<T>::capacityKill))
			return it;
	}

	return c;
}

template <class T>
string Jury_Team<T>::toString() const{

	string s;
	
	s += "Team number : " + to_string(Team<T>::teamNumber) + " \n";
	s += "Capacity kill : " + to_string(Killer<T>::capacityKill) + " %\n";
	s += "Team members : \n";
	
	for(auto it : Team<T>::teamMember)
		s += it.toString(); 
	
	return s;
}

