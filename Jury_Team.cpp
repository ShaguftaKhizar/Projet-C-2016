#include "Killer.hh"
#include "Team.hh"
#include "Jury_Team.hh"
#include "Candidat.hh"
#include <string>
#include <list>

using namespace std;

Jury_Team::Jury_Team(int _capacityKill, int _memberNumber, std::list<Jury> _teamMember) : Killer(_capacityKill, _memberNumber,  _teamMember)
{

	Killer::proAbilities["Wild"] = rand()%101; 
	Killer::proAbilities["Nature"] = rand()%101; 
	Killer::proAbilities["Talent"] = rand()%101; 
	Killer::proAbilities["Personality"] = rand()%101; 
	Killer::proAbilities["Swimming"] = rand()%101; 
	Killer::proAbilities["Speed"] = rand()%101; 

}

void Jury_Team::lowerSkills(Team& t1){

	list<Candidat> lc = t1.getTeamMember();

	for(auto it : lc){

		map<string, int> abilit = it.getAbilities();

		for(auto it2 : abilit)
		{
			it2.second -= 10;
		}

	}	

}

Candidat Jury_Team::candidatKill(Victim& v1) const{

	Candidat c("ZERO", 0, "ZERO");
		
	list<Candidat> lc = v1.getTeamMember();
	map<string, int>::const_iterator itLow;// itUpper;

	for(auto it : lc){

		map<string, int> abilit = it.getAbilities();
		itLow = abilit.lower_bound("Walk");
		//itUpper = Killer::proAbilities.upper_bound("Wild");
		
		if(itLow->second < (10*Killer::capacityKill))
			return it;

	}

	return c;
}

string Jury_Team::toString() const{

	string s;
	
	s += "Capacity kill : " + to_string(Killer::capacityKill) + " %\n";
	s += "Team members : \n";

	for(auto it : Team::teamMemberJ)
		s += it.toString(); 
	
	return s;
}

