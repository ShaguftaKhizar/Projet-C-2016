#pragma once
#include "Candidat.hh"
#include <list>



class Electeur{

 
    
 public:
    virtual Candidat vote(std::list<Candidat> lc) const =0;
    Electeur(int decision_power):_decision_power(decision_power){}; 
protected:
	/* le pouvoir décisionnel du public = 1 , celui du jury = 3 et celui des mentors = 2 */
    int  _decision_power;
    //ToString 
     virtual std::string toString()const ;
 
};

