#pragma once
#include "Electeur.hh"

class Mentor : public Electeur {

 public:

	 Mentor(string name): Electeur(2),_name(name),_enhancement_level(6){};
      void enhance(Team& team , std::string competence);
     Candidat* vote(list<Candidat> lc)const ;


 private:
    string _name;
    int _team_number;
    int _enhancement_level;
};

