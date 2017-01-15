#include "Mentor.hh"
#include "Candidat.hh"
#include <ctime>

using namespace std;


Candidat Mentor::vote(vector<Candidat> lc)const 

{  
	std::vector <Candidat> ::const_iterator first = lc.begin() , second = lc.end(); 
	
	Candidat c1 = *first ;
	Candidat c2 = *second ; 
				if( (rand()% 2) == 0)
					return c1 ;
				else 
					return c2 ;

}

std::string Mentor:: toString()const{
	
	string s;
	s += "Nom : " + _name + "\n" ;
	s += "Numero_equipe : " + to_string(_team_number) + "\n";
	s += "Augmente de " + to_string(_enhancement_level) + " les competences de son equipe\n" ;
	
	return s;
}
