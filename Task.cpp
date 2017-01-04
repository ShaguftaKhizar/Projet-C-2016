#include <list>
#include "Candidat.hh"
#include "Victim.hh"
#include "Team.hh"
#include "ProductionHouseTeam.hh"
#include "Jury_Team.hh"
#include "Task.hh"
#include "Killer.hh"
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

template <class T> 
Victim<T> Task::fashion_show_challenge(Victim<T>& v1, Victim<T>& v2, string abilityTested){

	list<Candidat> lc1 = v1.getTeamMember();
	list<Candidat> lc2 = v2.getTeamMember();
	list<Candidat> lc3;
	Victim<Candidat> v3(0, lc3);

	for(auto it1 : lc1)
	{
		for(auto it2 : lc2)
		{
			if((it1.getAbilities().find(abilityTested)->second) >= 50)
			{
				if((it2.getAbilities().find(abilityTested)->second) >= 50)
					return v3;

			}

			if((it1.getAbilities().find(abilityTested)->second) <= 50)
			{
				if((it2.getAbilities().find(abilityTested)->second) >= 50)
					return v2;

			}

			if((it1.getAbilities().find(abilityTested)->second) >= 50)
			{
				if((it2.getAbilities().find(abilityTested)->second) <= 50)
					return v1;

			}

		}

	}

	return v3;

}

