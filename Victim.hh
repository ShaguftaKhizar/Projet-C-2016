#pragma once
#include "Team.hh"
#include "Candidat.hh"
#include <iostream>
#include <list>

using namespace std;


template <class T>
class Victim : public Team <T>{

protected:
	bool survive = true;
	bool task = false;

public:
	Victim(int _memberNumber, std::list<T> _teamMember);
	void survivor();
	std::string toString() const;

};


template <class T>
Victim<T>::Victim(int _memberNumber, list<T> _teamMember) : Team<T>(_memberNumber, _teamMember){
		
		Team<T>::teamNumber++;

		uint number = Team<T>::memberNumber;

		if(Team<T>::teamMember.size() != number)
			cerr << "Invalid team member number" << endl;
}

template <class T>
void Victim<T>::survivor(){

	if(survive == false)
		task = true;

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
