#pragma once
#include "Electeur.hh"
#include "Victim.hh"



class Mentor : public Electeur {

 public:

	 Mentor(std::string name): Electeur(2),_name(name),_enhancement_level(6){};
	 template <class T>
     void enhance(Victim<T> & team , std::string competence);
     Candidat vote(std::list<Candidat> lc)const ;
     template <class T>
     Candidat vote(Victim<T>& t1)const ;
     
     //Accesseurs
     void set_team_number(int n ){ _team_number = n ;};
     int get_team_number(){return  _team_number ;};
     std::string toString()const ;


 private:
    std::string _name;
    int _team_number;
    int _enhancement_level;
};

template <class T>
void Mentor::enhance(Victim<T> & team , std::string competence)

{
	 list<Candidat> :: iterator iter;
	 list <Candidat> lc = team.getTeamMember();
	 Candidat c =*iter ;
    for (iter = lc.begin() ; iter != lc.end()  ; ++ iter)
			c.getAbilities().find(competence)->second   += _enhancement_level;  
    
}

template <class T>
Candidat Mentor::vote(Victim<T>& t1)const { //vote sur la moyenne des notes
	
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


