#pragma once
#include "Electeur.hh"
#include "Team.hh"
#include <map>

class Team ;
class Jury : public Electeur {

 public:

    Candidat vote(std::list<Candidat> lc)const ;
    Candidat vote(Team& t1)const ;
    Jury(std::string name): Electeur(3),_name(name){abilityInit();}; 
    void abilityInit();
    std::string toString()const ;

 private:
    std::string _name;
    std::map<std::string, int> abilitie_preference;
};
