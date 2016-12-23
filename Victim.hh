#pragma once
#include "Team.hh"
#include "Candidat.hh"
#include <list>

class Victim : public Team {

protected:
	bool survive = true;
	bool task = false;

public:
	Victim(int _memberNumber, std::list<Candidat> _teamMember);
	void survivor();
	std::string toString() const;

};
