//#pragma once
#include <string>
#include "Task.hh"
#include "Candidat.hh"
#include "Mentor.hh"
#include "Publique.hh"
#include "Jury.hh"
#include "Victim.hh"
#include "Jury_Team.hh"
//#include "ProductionHouseTeam.hh"


#include <map>
//#include <vector>
#include <list>


class ProductionHouse{

public:
	ProductionHouse(std:: list<Mentor> men,std:: list<Publique> pub, std:: list<Jury> jur,std:: list<Candidat> can);
     
 private:
 
 void candidatDivision(std::list<Candidat> lc);
 // List
   std:: list<Mentor> _men;
   std:: list<Publique> _pub; 
   std:: list<Jury> _jur;
   std:: list<Candidat> _can;
 // different Team 
   std::list<Jury_Team<Jury>> _juryTeam;
   std::list<Victim<Candidat>> _victimTeam; 
   //std:: list<ProductionHouseTeam> _productionTeam;
   
  // Game
    Task _task;
 //Survey and vote
   std::map<Candidat,int> _resultCandidat;    
   std::map<Candidat,int> _resultSurvey;

 };

