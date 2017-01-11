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

private:
	template <class T, class U>
	int miniChallengeJ(Victim<U>& v1, Jury_Team<T> lj, string abilityTested1, string abilityTested2);
	template <class T, class U>
	int miniChallengeP(Victim<U>& v1, ProductionHouseTeam<T> lp, string abilityTested1, string abilityTested2);

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

	vector<Jury_Team<T>> lj;
	vector<ProductionHouseTeam<T>> lp;
	int win = 0;

	if(typeid(k1) == typeid(Jury_Team<T>)){

		lj[0].setTeamMember(k1.getTeamMember());
		win = miniChallengeJ(v1, lj[0], abilityTested1, abilityTested2);
		cout << "win : " << win << endl;
		return win;
	}
	if(typeid(k1) == typeid(ProductionHouseTeam<T>)){

		lp[0].setTeamMember(k1.getTeamMember());
		win = miniChallengeP(v1, lp[0], abilityTested1, abilityTested2);
		cout << "win : " << win << endl;
		return win;
	}
			
	return 0;

}

template <class T, class U>
int Task::miniChallengeJ(Victim<U>& v1, Jury_Team<T> lj, string abilityTested1, string abilityTested2){

	vector<Candidat> lc1 = v1.getTeamMember();
	for(auto it1 : lc1)
	{
		if((it1.getAbilities().find(abilityTested1)->second) >= 50)
		{
			if((lj.getProAbilities().find(abilityTested2)->second) >= 50)
				return 0;

		}

		if((it1.getAbilities().find(abilityTested1)->second) <= 50)
		{
			if((lj.getProAbilities().find(abilityTested2)->second) >= 50)
				return lj.getTeamNumber();

		}

		if((it1.getAbilities().find(abilityTested1)->second) >= 50)
		{
			if((lj.getProAbilities().find(abilityTested2)->second) <= 50)
				return v1.getTeamNumber();

		}
			
	}
	return 0;

}

template <class T, class U>
int Task::miniChallengeP(Victim<U>& v1, ProductionHouseTeam<T> lp, string abilityTested1, string abilityTested2){

	vector<Candidat> lc1 = v1.getTeamMember();
	for(auto it1 : lc1)
	{

		if((it1.getAbilities().find(abilityTested1)->second) >= 50)
		{
			if((lp.getProAbilities().find(abilityTested2)->second) >= 50)
				return 0;

		}

		if((it1.getAbilities().find(abilityTested1)->second) <= 50)
		{
			if((lp.getProAbilities().find(abilityTested2)->second) >= 50)
				return lp.getTeamNumber();

		}

		if((it1.getAbilities().find(abilityTested1)->second) >= 50)
		{
			if((lp.getProAbilities().find(abilityTested2)->second) <= 50)
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
				if((it2.getAbilities().find(abilityTested)->second) >= 50){
					cout << it1.getAbilities().find(abilityTested)->second << endl;
					cout << it2.getAbilities().find(abilityTested)->second << endl;
					return 0;
				}

			}

			if((it1.getAbilities().find(abilityTested)->second) <= 50)
			{
				if((it2.getAbilities().find(abilityTested)->second) >= 50){
					cout << it1.getAbilities().find(abilityTested)->second << endl;
					cout << it2.getAbilities().find(abilityTested)->second << endl;
					return v2.getTeamNumber();
				}

			}

			if((it1.getAbilities().find(abilityTested)->second) >= 50)
			{
				if((it2.getAbilities().find(abilityTested)->second) <= 50){
					cout << it1.getAbilities().find(abilityTested)->second << endl;
					cout << it2.getAbilities().find(abilityTested)->second << endl;
					return v1.getTeamNumber();
				}
			}

		}

	}

	return 0;

}

