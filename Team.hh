#pragma once
#include <vector>
#include <string>

template<class T>
class Team
{

protected:
	int memberNumber;
	int teamNumber;
	std::vector<T> teamMember;

public:
	virtual std::string toString() const = 0;
	Team(){};
	Team(int _memberNumber, std::vector<T>  _teamMember) : memberNumber(_memberNumber), teamMember(_teamMember){};
	std::vector<T> getTeamMember(){ return teamMember;};
	void setTeamNumber(int number){ teamNumber = number; };
	int getTeamNumber(){ return teamNumber; };
	int getMemberNumber(){ return memberNumber; };
	void setMemberNumber( int m ){  memberNumber= m ; };
	void setTeamMember(std::vector<T> teamMem){ teamMember = teamMem; };
	~Team(){};

};



