#include "Killer.hh"
#include "Team.hh"
#include "ProductionHouseTeam.hh"
#include "Candidat.hh"
#include <string>
#include <list>

using namespace std;

ProductionHouseTeam::ProductionHouseTeam(int _capacityKill, int _memberNumber, std::list<ProductionHouse> _teamMember) : Killer(_capacityKill, _memberNumber,  _teamMember)
{

	Killer::proAbilities["Wild"] = rand()%101; 
	Killer::proAbilities["Nature"] = rand()%101; 
	Killer::proAbilities["Talent"] = rand()%101; 
	Killer::proAbilities["Personality"] = rand()%101; 
	Killer::proAbilities["Swimming"] = rand()%101; 
	Killer::proAbilities["Speed"] = rand()%101; 

}

void ProductionHouseTeam::lowerPopularity(Team& t1){

	list<Candidat> lc = t1.getTeamMember();

	for(auto it : lc){

		int pop = (it.getPopularity() - 10);
		it.setPopularity(pop);

	}	

}

Candidat ProductionHouseTeam::candidatKill(Victim& v1) const{

	Candidat c("ZERO", 0, "ZERO");
	list<Candidat> lc = v1.getTeamMember();

	for(auto it : lc){

		if(it.getPopularity() <= (20*Killer::capacityKill))
			return it;

	}

	return c;
}

string ProductionHouseTeam::toString() const{

	string s;
	
	s += "Capacity kill : " + to_string(Killer::capacityKill) + " %\n";
	s += "Team members : \n";
	/*
	for(auto it : Team::teamMemberP)
		s += it.toString(); 
	*/
	return s;
}

