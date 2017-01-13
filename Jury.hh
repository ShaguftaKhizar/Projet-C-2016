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

/*
template <class T>
Candidat Jury::vote(Victim<T>& t1)const {
	
	vector<Candidat> lc = t1.getTeamMember();
	vector <Candidat> ::const_iterator first ,iter; 
	Candidat c = *first;
	int val  = 100 ;
	
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
*/
template <class T>
Candidat Jury::vote(Victim<T>& t1)const {
	
	//instruction a problème :
	//it->first; mauvaise utilisation de upper bound

	vector<Candidat> lc = t1.getTeamMember();
	vector <Candidat> ::iterator iter; 
	Candidat c1;
	int val  = 100 ;

	map<string,int>::const_iterator it;
	map<string,int>::iterator it1 ;
	it = abilitie_preference.upper_bound("Walk");

	for(iter = lc.begin(); iter != lc.end(); ++iter){
		if (iter->getSelected() == true ){
			it1 = iter->getAbilities().find(it->first);
			cout << "passe " << endl;
			if( (it1->second   <   it->second) && (it1->second < val )){
				cout << "if " << endl;
				val = it1->second ; 
				return *iter; 
			}
		}
	}
		
	return c1 ; 
	
}
