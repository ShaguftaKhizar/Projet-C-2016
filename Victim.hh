#pragma once
#include "Team.hh"
#include "Candidat.hh"
#include <iostream>
#include <vector>
//#include "number.hh"

using namespace std;


template <class T>
class Victim : public Team <T>{

protected:
	bool survive = true;
	bool task = false;

public:
	Victim(int _memberNumber, std::vector<T> _teamMember);
	void survivor();
	std::string toString() const;
	bool getTask(){ return task; };
	void setSurvive(bool survi){ survive = survi; };

};


template <class T>
Victim<T>::Victim(int _memberNumber, vector<T> _teamMember) : Team<T>(_memberNumber, _teamMember){
		
	Team<T>::teamNumber = val_team();

	uint number = Team<T>::memberNumber;

	if(Team<T>::teamMember.size() != number)
		cerr << "Invalid team member number" << endl;
}

template <class T>
void Victim<T>::survivor(){
	static bool already_saved = false;

	if(survive == false && already_saved == false ){

		for(auto it : Team<T>::teamMember){

			if(it.getSelected() == false){

				if(it.moyenne() >= 50){

					task = true;
					already_saved = true;
					
				}
				else 
					task = false;
			}
		}
		
	}

}

template <class T>
string Victim<T>::toString() const{

	string s;

	s += "Team number : ";
	s += to_string(Team<T>::teamNumber);
	s += " Member number : ";
	s += to_string(Team<T>::memberNumber);
	s += "\nMembers : \n";

	for(auto it : Team<T>::teamMember)
		s += it.toString();

	return s;

}
