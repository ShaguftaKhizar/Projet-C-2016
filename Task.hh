#pragma once
#include "Candidat.hh"
#include "Victim.hh"
#include "Jury_Team.hh"
#include "ProductionHouseTeam.hh"
#include "Killer.hh"
#include "ProMember.hh"
#include "Jury.hh"
#include "ProMember.hh"
#include "Team.hh"

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
	int surprise_challenge(Killer<T>& k1, Victim<U>& v1, string abilityTested1, string abilityTested2);

};

template <class T,class U> 
int Task::surprise_challenge(Killer<T>& k1, Victim<U>& v1, string abilityTested1, string abilityTested2){

	Killer<T>& k = k1;
	vector<Candidat> vc = v1.getTeamMember();
	int cand = rand()% vc.size(); 

	if(typeid(k1) == typeid(Jury_Team<T>))
	{

		Jury_Team<T> j = static_cast<Jury_Team<T>>(k);

		if(vc[cand].getAbilities().find(abilityTested1)->second > j.getProAbilities().find(abilityTested2)->second)
			return v1.getTeamNumber();

		else if(vc[cand].getAbilities().find(abilityTested1)->second < j.getProAbilities().find(abilityTested2)->second)
			return j.getTeamNumber();
	}
	if(typeid(k1) == typeid(ProductionHouseTeam<T>))
	{

		ProductionHouseTeam<T> p = static_cast<ProductionHouseTeam<T>>(k);
	
		if(vc[cand].getAbilities().find(abilityTested1)->second >= p.getProAbilities().find(abilityTested2)->second)
			return v1.getTeamNumber();

		else if(vc[cand].getAbilities().find(abilityTested1)->second < p.getProAbilities().find(abilityTested2)->second)
			return p.getTeamNumber();
	}
			
	return 0;

}

template <class T> 
int Task::fashion_show_challenge(Victim<T>& v1, Victim<T>& v2, string abilityTested){


	vector<Candidat> lc1 = v1.getTeamMember();
	vector<Candidat> lc2 = v2.getTeamMember();
	
	int cand_1 = rand()% lc1.size(); 
	int cand_2 = rand()% lc2.size(); 
	
	if(lc1[cand_1].getAbilities().find(abilityTested)->second > lc2[cand_2].getAbilities().find(abilityTested)->second)
		return v1.getTeamNumber();
		
	else if(lc1[cand_1].getAbilities().find(abilityTested)->second < lc2[cand_2].getAbilities().find(abilityTested)->second)
		return v2.getTeamNumber();
	
	return 0;

}

