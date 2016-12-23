#pragma once
#include "Team.hh"
#include "Electeur.hh"

class Mentor : public Electeur {

 public:

	 Mentor(std::string name): Electeur(2),_name(name),_enhancement_level(6){};
     void enhance(Team & team , std::string competence);
     Candidat vote(std::list<Candidat> lc)const ;
     Candidat vote(Team& t1)const ;
     
     //Accesseurs
     void set_team_number(int n ){ _team_number = n ;};
     int get_team_number(){return  _team_number ;};
     std::string toString()const ;


 private:
    std::string _name;
    int _team_number;
    int _enhancement_level;
};

