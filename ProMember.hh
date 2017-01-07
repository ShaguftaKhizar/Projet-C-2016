#pragma once
#include <string>

class ProMember{

private:
	std::string person[2];

public:
	ProMember(std::string name, std::string job){
		person[0] = name; 
		person[1] = job;
	};
	std::string toString() const{	
		string s;
		s += "Name : " + person[0] + " job : " + person[1] + "\n";
		return s; 
	};


};


