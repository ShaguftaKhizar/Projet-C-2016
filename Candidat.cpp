#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include "Candidat.hh"

using namespace std;

Candidat::Candidat(string _nom, int _age, string _description){

	identity[0] = _nom;
	identity[1] = to_string(_age);
	identity[2] = _description;

	popularity = rand()%101; 
	abilityInit();
}

Candidat::Candidat (Candidat& c1){

		
	identity[0] = c1.identity[0];
	identity[1] = c1.identity[1];
	identity[2] = c1.identity[2];

	popularity = c1.popularity; 
	abilities = c1.abilities ;
	
}

void Candidat::abilityInit()
{

	abilities["Communication skills"] = rand()%51; 
	abilities["Intelligence"] = rand()%51; 
	abilities["Confidence"] = rand()%51; 
	abilities["Beauty"] = rand()%51; 
	abilities["Talent"] = rand()%51; 
	abilities["Walk"] = rand()%51; 

}

void Candidat::print(){

	map<string, int>::iterator it;

	cout << "Nom : " << identity[0] << " Age : " << identity[1] << " ans " << endl;
	cout << "Description : " << identity[2] << endl;
	cout << endl;
	cout << "Popularity : " << popularity << " %" << endl;
	cout << endl;

	for(auto it : abilities)
	{
		cout << it.first << " : " << to_string(it.second) << " %" << endl;	
	}

}

string Candidat::toString(){

	map<string, int>::iterator it;
	string s;

	s += "Nom : " + identity[0] + " Age : " + identity[1] + " ans\n ";
	s += "Description : " + identity[2] + "\n";
	s += "Popularity : " + to_string(popularity) + " %\n";

	for(auto it : abilities)
	{
		s += it.first + " : " + to_string(it.second) + " %\n";	
	}

	return s;
}
