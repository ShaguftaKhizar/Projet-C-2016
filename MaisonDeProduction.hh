#ifndef MAISONDEPRODUCTION_H
#define MAISONDEPRODUCTION_H

#include "Task.hh"
#include "Mentor.hh"
#include "Victims.hh"
#include "JuryTeam.hh"
#include "ProdTeam.hh"
#include <map>
#include <vector>
#include <Electeur.hh>
#include <list>



class MaisonDeProduction {

 public:

     void countVote(std::svector<Electeur>  vec); // Fait la délibération  des votes
	 //void updateTeamList(); // met à jour les équipes et la liste globale de candidat.
	 void updateTeamList(Team&  victim , Candidat& cand )
	 void survey(std::vector<Electeur> vec); // Fait la délibération du sondage 
	 //void candidatTwist();//???
	// void updateCandidatSkill(); // Met à jour  les compétences grâces au mentor et aux équipes pro
	 void updateCandidatSkill(Team&  victim , std::string competence);
	 void candidatDivision(std::list<Candidat> lc); // Pour séparer les candidats dans deux équipes 
     void affectation(); //affecter une équipe à un mentor 
     void chooseTask(); // Choisir quelle épreuve va se jouer et quelles seront les équipes.
	 //void division(void  vecteur<Electeur>);
     //void division(void  vecteur<Prod>);
     
     
     void toString_result() ;
     void toString_survey() ;
     


 private:
   std:: vector<Mentor> _mentor;
    Victims _victimTeamA; 
    Victims _victimTeamB;
    Task _task;
    std::vector<Jury> _juryTeam;
   // vector<Prod> prodTeam;???????
    std::map<Candidat,int> _resultCandidat;    
    std::map<Candidat,int> _resultSurvey;

 };

#endif // MaisonDeProduction_h
