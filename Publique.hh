#pragma once
#include "Electeur.hh"

class Publique : public Electeur {

 public:
    Candidat vote(std::list<Candidat> lc) const ;
    Publique(int popularity_boundary):Electeur(1) ,_popularity_boundary(popularity_boundary ){};
    std::string toString()const ;
    
    

 private:
    int _popularity_boundary;
};


