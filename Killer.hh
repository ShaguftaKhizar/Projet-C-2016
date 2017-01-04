#pragma once
#include <map>
#include <list>

#include "Team.hh"
#include "Victim.hh"
#include "Candidat.hh"

template <class T>
class Killer : public Team<T>{

protected:
	int capacityKill;
	std::map<std::string, int> proAbilities;

public:
    virtual Candidat candidatKill(Victim<Candidat>& v1) const = 0;
	Killer(int _capacityKill, int _memberNumber, std::list<T> _teamMember) : Team<T>(_memberNumber, _teamMember) ,capacityKill(_capacityKill){};
	 ~Killer(){};
};
