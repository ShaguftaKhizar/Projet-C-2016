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

Victim Task::fashion_show_challenge(Victim& v1, Victim& v2, string abilityTested){

	list<Candidat> lc1 = v1.getTeamMember();
	list<Candidat> lc2 = v2.getTeamMember();
	list<Candidat> lc3;
	Victim v3(0, lc3);

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

int Task::surprise_challenge(const Team& t1, const Team& t2){

	if((typeid(t1) != typeid(Killer)) || (typeid(t2) != typeid(Killer)))
	{
		cerr << "This is a survival challenge " << endl;
		exit(1);
	}

	switch( typeTeam(t1) ){

		case 1:
		{
			if(typeTeam(t2) == 2)
			{
				//t2.lowerSkills(t1);
				return t2.teamNumber;
			}
			else if(typeTeam(t2) == 3)
			{
				//t2.lowerPopularity(t1);
				return t2.teamNumber;
			}
		}
		break;
		case 2:
		{
			if(typeTeam(t2) == 1)
			{
				//t2.lowerSkills(t1);
				return t2.teamNumber;
			}
			else
				exit(1);

		}
		break;
		case 3:
		{
			if(typeTeam(t2) == 1)
			{
				//t2.lowerPopularity(t1);
				return t2.teamNumber;
			}
			else
				exit(1);

		}
		break;


	};

	return 0;

}

int Task::typeTeam(const Team& t1){

	if(typeid(t1) == typeid(Victim))
		return 1;
	else if(typeid(t1) == typeid(Jury_Team))
		return 2;
	else if(typeid(t1) == typeid(ProductionHouseTeam))
		return 3;

	return 0;
}