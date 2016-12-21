#pragma once
#include "Electeur.hh"

class Publique : public Electeur {

 public:
    Candidat vote(std::list<Candidat> lc) ;
    Publique(int popularity_boundary):Electeur(1) ,_popularity_boundary(popularity_boundary ){};
    
    
    

 private:
    int _popularity_boundary;
};


