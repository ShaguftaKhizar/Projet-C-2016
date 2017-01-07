#include "Publique.hh"
#include <ctime>

using namespace std ;


/*Le vote du public sert au pronostic et se situe à l'étape final 
l'election.
Au moment où le public vote, la vectore ne doit contenir que deux finavectores*/
 Candidat Publique::vote(std::vector<Candidat> lc)const 
{
	
	  
	vector <Candidat> ::const_iterator first = lc.begin() , second = lc.end(); 
	Candidat c1 = *first ;
	Candidat c2 = *second ; 

		if((c1.getPopularity()>=_popularity_boundary && c2.getPopularity()>= _popularity_boundary ) || (c1.getPopularity()<_popularity_boundary && c2.getPopularity()<_popularity_boundary ))
		
			{ /*on choisit au hasard le gagnant pour le public*/
				if( (rand()% 2) == 0)
					return c1 ;
				else 
					return c2;
			}
		else 
			if (c1.getPopularity() >= _popularity_boundary) 
				return c1;
			else
				return c2 ;
		

}



std::string Publique:: toString()const {
	

	string s ;
	s += "Publique \n";
	s += "popularity_boundary : " +to_string( _popularity_boundary) + "\n";	
	return s;
}
