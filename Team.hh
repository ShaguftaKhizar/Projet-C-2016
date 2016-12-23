#pragma once 
#include "ProductionHouse.hh"
#include "Candidat.hh"
#include <list>
#include <string>
#include "Jury.hh"
//class Jury ;

class Team{

protected:
	int memberNumber;
	std::list<Candidat> teamMember;
	int teamNumber;
	std::list<Jury> teamMemberJ;
	std::list<ProductionHouse> teamMemberP;

public:
	//static int teamNumber;
	virtual std::string toString() const = 0;
	Team(int _memberNumber, std::list<Candidat> _teamMember) : memberNumber(_memberNumber), teamMember(_teamMember){};
	Team(int _memberNumber, std::list<Jury> _teamMember) : memberNumber(_memberNumber), teamMemberJ(_teamMember){};
	Team(int _memberNumber, std::list<ProductionHouse> _teamMember) : memberNumber(_memberNumber), teamMemberP(_teamMember){};
	std::list<Candidat> getTeamMember(){ return teamMember; };
	~Team(){};

};
