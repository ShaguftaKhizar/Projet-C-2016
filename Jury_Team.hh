#pragma once
#include "Killer.hh"
#include "Team.hh"
#include <string>
#include <list>

class Jury_Team : public Killer{

	Jury_Team(int _capacityKill, int _memberNumber, std::list<Jury> _teamMember);
	void lowerSkills(Team&);
	Candidat candidatKill(Victim&) const;
	std::string toString() const;

};