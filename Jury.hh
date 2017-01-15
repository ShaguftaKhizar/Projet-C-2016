#pragma once
#include "Electeur.hh"
#include "Victim.hh"
#include "Candidat.hh"

#include <map>
#include <string>
#include <vector>




class Jury : public Electeur {

 public:

    Candidat vote(std::vector<Candidat> lc)const ;
    template <class T>
    Candidat vote(Victim<T>& v1)const ;
    Jury(std::string name): Electeur(3),_name(name){abilityInit();}; 
    void abilityInit();
    std::string toString()const ;

 private:
    std::string _name;
    std::map<std::string, int> abilitie_preference;
};

template <class T>
Candidat Jury::vote(Victim<T>& t1)const {
	
	vector<Candidat> lc = t1.getTeamMember();
	vector <Candidat>::iterator iter; 
	Candidat c1;
	int max = 0;
	string s;

	map<string,int>::iterator it1 ;	

	s = upperBounds(abilitie_preference);
	max = upperBound(abilitie_preference);

	for(iter = lc.begin(); iter != lc.end(); ++iter){
		
		if (iter->getSelected() == true ){
			it1 = iter->getAbilities().find(s);
			if(it1->second <  max){
				return *iter; 
			}
		}

	}
		
	return c1 ; 
}
