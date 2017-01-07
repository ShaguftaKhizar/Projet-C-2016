#pragma once
#include "Candidat.hh"
#include "Victim.hh"
#include "Jury_Team.hh"
#include "Killer.hh"
#include "ProMember.hh"

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

using namespace std;


class Task{

public:
	Task(){};
	/*	Task between 2 victim teams	*/
	template <class T>
	int fashion_show_challenge(Victim<T>& v1, Victim<T>& v2, std::string abilityTested);	
	/*	Task between a victim team and a killer team	*/	
	template <class T , class U>
	int surprise_challenge(Killer<T>& k1, Victim<U>& v1, std::string abilityTested1, std::string abilityTested2);

};

template <class T,class U> 
int Task::surprise_challenge(Killer<T>& k1, Victim<U>& v1, std::string abilityTested1, std::string abilityTested2){

	vector<Candidat> lc1 = v1.getTeamMember();

	for(auto it1 : lc1)
	{
		if((it1.getAbilities().find(abilityTested1)->second) >= 50)
		{
			if((k1.getProAbilities().find(abilityTested2)->second) >= 50)
				return 0;

		}

		if((it1.getAbilities().find(abilityTested1)->second) <= 50)
		{
			if((k1.getProAbilities().find(abilityTested2)->second) >= 50)
				return k1.getTeamNumber();

		}

		if((it1.getAbilities().find(abilityTested1)->second) >= 50)
		{
			if((k1.getProAbilities().find(abilityTested2)->second) <= 50)
				return v1.getTeamNumber();

		}

	}
			
	return 0;

}

template <class T> 
int Task::fashion_show_challenge(Victim<T>& v1, Victim<T>& v2, string abilityTested){

	vector<Candidat> lc1 = v1.getTeamMember();
	vector<Candidat> lc2 = v2.getTeamMember();

	for(auto it1 : lc1)
	{
		for(auto it2 : lc2)
		{
			if((it1.getAbilities().find(abilityTested)->second) >= 50)
			{
				if((it2.getAbilities().find(abilityTested)->second) >= 50)
					return 0;

			}

			if((it1.getAbilities().find(abilityTested)->second) <= 50)
			{
				if((it2.getAbilities().find(abilityTested)->second) >= 50)
					return v2.getTeamNumber();

			}

			if((it1.getAbilities().find(abilityTested)->second) >= 50)
			{
				if((it2.getAbilities().find(abilityTested)->second) <= 50)
					return v1.getTeamNumber();

			}

		}

	}

	return 0;

}

