#pragma once
#include "Killer.hh"
#include "Team.hh"
#include <string>

class ProductionHouseTeam : public Killer{

public:
	ProductionHouseTeam(int _capacityKill, int _memberNumber, std::list<ProductionHouse> _teamMember);
	void lowerPopularity(Team&);
	Candidat candidatKill(Victim&) const;
	std::string toString() const;
};