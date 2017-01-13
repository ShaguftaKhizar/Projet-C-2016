#pragma once
#include "Electeur.hh"
#include "Victim.hh"
#include <iostream>



class Mentor : public Electeur {

 public:

	 Mentor(std::string name): Electeur(2),_name(name),_enhancement_level(6){};
	 template <class T>
     void enhance(Victim<T>& team , std::string competence);
     Candidat vote(std::vector<Candidat> lc)const ;
     template <class T>
     Candidat vote(Victim<T>& t1)const ;
     
     //Accesseurs
     void set_team_number(int n ){ _team_number = n ;};
     int get_team_number(){return  _team_number ;};
     int get_enhancement_level(){ return _enhancement_level; }; 
     std::string toString()const ;


 private:
    std::string _name;
    int _team_number;
    int _enhancement_level;
};

template <class T>
void Mentor::enhance(Victim<T>& team , std::string competence)
{
	vector<Candidat> :: iterator iter;
	vector <Candidat> lc = team.getTeamMember();
	int val = 0;

	for (iter = lc.begin() ; iter != lc.end()  ; ++ iter){

		val = iter->getAbilities().find(competence)->second; 
		iter->setAbilities(val += _enhancement_level, competence);
		cout << to_string(iter->getAbilities().find(competence)->second) << endl;
	}
	team.setTeamMember(lc);
}

template <class T>
Candidat Mentor::vote(Victim<T>& t1)const { //vote sur la moyenne des notes
	
	vector<Candidat> lc = t1.getTeamMember();
	vector<Candidat>::const_iterator first , iter ;
	Candidat c = *first;
	int moyenne, val = 100 ;
		
	map<string,int>::const_iterator it1 ;
	map<string,int>  m  ;
		
	iter = lc.begin(); 
	for(first = lc.begin();first!= lc.end(); ++first){
		if (c.getSelected() == true ){	
			moyenne = c.moyenne();
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


