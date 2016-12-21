#include "Mentor.hh"
#include <ctime>

void Mentor::enhance(Team& team , std::string competence)

{
	 map< Candidat , int > :: iterator iter;
    for (iter = team.Team_member.begin() ; iter != team.Team_member.begin()  ; ++ iter)
			(iter->first).abilities.find(competence)->second   += _enhancement_level;  
    
}


Candidat* Mentor::vote(list<Candidat> lc)const 

{
	  srand(time(NULL));
	  
	std::list <Candidat> ::const_iterator first = lc.begin() , second = lc.end(); 
				if( (rand()% 2) == 0)
					return first ;
				else 
					return second ;

}

