#pragma once
#include "Candidat.hh"
#include <vector>



class Electeur{

 
    
 public:
 	int getDecision_power(){return _decision_power; };
    virtual Candidat vote(std::vector<Candidat> lc) const =0;
    Electeur(int decision_power):_decision_power(decision_power){}; 
protected:
	/* le pouvoir décisionnel du public = 1 , celui du jury = 3 et celui des mentors = 2 */
    int  _decision_power;
    //ToString 
     virtual std::string toString()const = 0;
 
};

