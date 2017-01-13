//#pragma once
#include <string>
#include "Task.hh"
#include "Candidat.hh"
#include "Mentor.hh"
#include "Publique.hh"
#include "Jury.hh"
#include "Victim.hh"
#include "Jury_Team.hh"
#include "ProductionHouseTeam.hh"
#include "ProMember.hh"

#include <map>
#include <vector>


class ProductionHouse{

public:
	ProductionHouse(std:: vector<Mentor> men, std:: vector<Publique> pub, std:: vector<Jury> jur,std:: vector<Candidat> can , std:: vector<ProductionHouseTeam<ProMember>> pro);
  void chooseTask();
  int gameState();
  void final();
 
private:
 void update(int winNumber, std::string abilityTested1);
 void updateFight1(int winNumber, int team);
 void updateFight2(int winNumber, int team);
 void updateList(int team);
 void candidatDivision(std::vector<Candidat> lc);
 void mentorAttribution();
 void updateCandidat();
 int loser(int winNumber);
 void voteCandidat(Candidat c);
 void voteCandidat(Candidat c, int decision_power);
 void eliminationRound(int team);
 void reset();
 string survey();
 void countVote(int team);
 void countVoteFinal();
 std::string stringSelection(string * s);
 std::string s1[6];
 std::string s2[6];
 // vector
   std:: vector<Mentor> _men;
   std:: vector<Publique> _pub; 
   std:: vector<Jury> _jur;
   std:: vector<Candidat> _can;
 // different Team 
   std::vector<Jury_Team<Jury>> _juryTeam;
   std::vector<Victim<Candidat>> _victimTeam; 
   std::vector<ProductionHouseTeam<ProMember>> _productionTeam;
   
  // Game
    Task _task;
  //Survey and vote    
   std::map<string,int> _result;

 };

