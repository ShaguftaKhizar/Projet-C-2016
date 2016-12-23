#include "Team.hh"
#include "Victim.hh"
#include "Candidat.hh"
#include <iostream>

using namespace std;
int Team::teamNumber = 0;

Victim::Victim(int _memberNumber, list<Candidat> _teamMember) : Team(_memberNumber, _teamMember){
		
		Team::teamNumber++;

		uint number = Team::memberNumber;

		if(Team::teamMember.size() != number)
			cerr << "Invalid team member number" << endl;
}

void Victim::survivor(){

	if(survive == false)
		task = true;

}

string Victim::toString() const{

	string s;

	s += "Team number : ";
	s += to_string(teamNumber);
	s += " Member number : ";
	s += to_string(memberNumber);
	s += "\nMembers : \n";

	for(auto it : teamMember)
		s += it.toString();

	return s;

}

