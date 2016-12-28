#pragma once
#include <list>
#include <string>
#include "Candidat.hh"
#include "Victim.hh"
#include "Team.hh"

class Task{

private:
	int typeTeam(const Team& t1);

public:
	/*	Task between 2 victim teams	*/
	Victim fashion_show_challenge(Victim& v1, Victim& v2, std::string abilityTested);	
	/*	Task between a team and a killer team	*/	
	int surprise_challenge(const Team& t1, const Team& t2);

};