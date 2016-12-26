#pragma once
#include <map>
#include <list>
#include "Team.hh"
#include "Victim.hh"
#include "Candidat.hh"

class Killer : public Team{

protected:
	int capacityKill;
	std::map<std::string, int> proAbilities;

public:
	virtual Candidat candidatKill(Victim&) const = 0;
	Killer(int _capacityKill, int _memberNumber, std::list<Jury> _teamMember) : Team(_memberNumber, _teamMember) ,capacityKill(_capacityKill){};
	Killer(int _capacityKill, int _memberNumber, std::list<ProductionHouse> _teamMember) : Team(_memberNumber, _teamMember) ,capacityKill(_capacityKill){};
	~Killer(){};
};