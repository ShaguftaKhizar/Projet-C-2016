#include "Mentor.hh"
#include "Candidat.hh"
#include <ctime>

using namespace std;
void Mentor::enhance(Team& team , std::string competence)

{
	 list<Candidat> :: iterator iter;
	 list <Candidat> lc = team.getTeamMember();
	 Candidat c =*iter ;
    for (iter = lc.begin() ; iter != lc.end()  ; ++ iter)
			c.getAbilities().find(competence)->second   += _enhancement_level;  
    
}


Candidat Mentor::vote(list<Candidat> lc)const 

{  
	std::list <Candidat> ::const_iterator first = lc.begin() , second = lc.end(); 
	
	Candidat c1 = *first ;
	Candidat c2 = *second ; 
				if( (rand()% 2) == 0)
					return c1 ;
				else 
					return c2 ;

}


Candidat Mentor::vote(Team& t1)const { //vote sur la moyenne des notes
	
	list<Candidat> lc = t1.getTeamMember();
		list<Candidat>::const_iterator first , iter ;
		Candidat c = *first;
		int moyenne  , val = 0 ;
		
		map<string,int>::const_iterator it1 ;
		map<string,int>  m  ;
		
				
		iter = lc.begin(); 
		for(first = lc.begin();first!= lc.end(); ++first){
			if (c.getSelected() == true ){	
				m = c.getAbilities();
				moyenne = 0 ; 
				for(it1 = m.begin() ; it1 != m.end() ; ++it1){
				
					moyenne += it1->second ;
				
			}
			moyenne = moyenne / m.size();
			
			if (moyenne < val )
						{
							iter = first ; 
							val = moyenne; 
						}
		}
	}
		
		Candidat c1 = *iter ; 
		return c1 ; 
	
}


std::string Mentor:: toString()const{
	
	string s;
	s += "Nom : " + _name + "\n" ;
	s += "Numero_equipe :" + to_string(_team_number) + "\n";
	s += "Augmente de " + to_string(_enhancement_level) + "\n" ;
	
	return s;
}
