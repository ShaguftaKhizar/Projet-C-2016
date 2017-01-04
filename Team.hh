#pragma once
#include <list>
#include <string>

template<class T>
class Team
{

protected:
	int memberNumber;
	std::list<T> teamMember;

public:
	static int teamNumber;
	virtual std::string toString() const = 0;
	Team(){};
	Team(int _memberNumber, std::list<T>  _teamMember) : memberNumber(_memberNumber), teamMember(_teamMember){};
	std::list<T> getTeamMember(){ return teamMember;};
	~Team(){};

};

template <class T>
int Team<T>::teamNumber = 0;



