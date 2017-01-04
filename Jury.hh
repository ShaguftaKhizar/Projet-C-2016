#pragma once
#include "Electeur.hh"
#include "Victim.hh"
#include "Candidat.hh"

#include <map>
#include <string>
#include <list>




class Jury : public Electeur {

 public:

    Candidat vote(std::list<Candidat> lc)const ;
    template <class T>
    Candidat vote(Victim<T>& t1)const ;
    Jury(std::string name): Electeur(3),_name(name){abilityInit();}; 
    void abilityInit();
    std::string toString()const ;

 private:
    std::string _name;
    std::map<std::string, int> abilitie_preference;
};


template <class T>
Candidat Jury::vote(Victim<T>& t1)const {
	
	list<Candidat> lc = t1.getTeamMember();
	list <Candidat> ::const_iterator first ,iter; 
		Candidat c = *first;
		int val  = 0 ;
		
		map<string,int>::const_iterator it,it1 ;
		
		it = abilitie_preference.upper_bound("Walk");
		
		iter = lc.begin(); 
		for(first = lc.begin();first!= lc.end(); ++first){
			if (c.getSelected() == true ){	
				
				it1 = c.getAbilities().find(it->first)  ;
				if( it1->second   <   it->second ){
					if (it1->second < val )
						{
							iter = first ; 
							val = it1->second ; 
						}
				}
		}
	}
		
		Candidat c1 = *iter ; 
		return c1 ; 
	
}
