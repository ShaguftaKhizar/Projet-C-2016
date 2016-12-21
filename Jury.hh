#pragma once
#include "Electeur.hh"
#include <map>

class Jury : public Electeur {

 public:

    Candidat* vote(list<Candidat> lc)const ;
    Jury(string name): Electeur(3),_name(name){abilityInit();}; 
    void abilityInit();

 private:
    string _name;
    std::map<std::string, int> abilitie_preference;
};

//bool operator==(Candidat candi , std::map<std::string, int> abilitie_preference);
