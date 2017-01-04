#pragma once
#include "Candidat.hh"
#include "Victim.hh"
#include "Team.hh"
#include "ProductionHouseTeam.hh"
#include "Jury_Team.hh"
#include "Killer.hh"

#include <iostream>
#include <typeinfo>
#include <list>
#include <string>

using namespace std;


class Task{

private:
	template <class T>
	int typeTeam(const Team<T>& t1);

public:
	Task(){};
	/*	Task between 2 victim teams	*/
	template <class T>
	Victim<T> fashion_show_challenge(Victim<T>& v1, Victim<T>& v2, std::string abilityTested);	
	/*	Task between a team and a killer team	*/	
	template <class T , class U>
	int surprise_challenge(const Team<T>& t1, const Team<U>& t2);

};




template <class T,class U> 
int Task::surprise_challenge(const Team<T>& t1, const Team<U>& t2){

	if((typeid(t1) != typeid(Killer<T>)) || (typeid(t2) != typeid(Killer<T>)))
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

template <class T> 
int Task::typeTeam(const Team<T>& t1){

	if(typeid(t1) == typeid(Victim<T>))
		return 1;
	else if(typeid(t1) == typeid(Jury_Team<T>))
		return 2;
	else if(typeid(t1) == typeid(ProductionHouseTeam<T>))
		return 3;

	return 0;
}
