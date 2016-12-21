#include "Publique.hh"
#include <ctime>

using namespace std ;


/*Le vote du public sert au pronostic et se situe à l'étape final 
l'election.
Au moment où le public vote, la liste ne doit contenir que deux finalistes*/
 Candidat Publique::vote(std::list<Candidat> lc) 
{
	  srand(time(NULL));
	  
	list <Candidat> ::iterator first = lc.begin() , second = lc.end(); 
	Candidat c1 = first ;
	Candidat c2 = second ; 

		if((first->getPopularity()>=_popularity_boundary && second->getPopularity()>= _popularity_boundary ) || (first->getPopularity()<_popularity_boundary && second->getPopularity()<_popularity_boundary ))
		
			{ /*on choisit au hasard le gagnant pour le public*/
				if( (rand()% 2) == 0)
					return c1 ;
				else 
					return c2;
			}
		else 
			if (first->getPopularity() >= _popularity_boundary) 
				return c1;
			else
				return c2 ;
		

}


/*bool operator != (const Candidat cand,const int n );
	
	return cand.getPopularity() == n ; 
	
}*/
