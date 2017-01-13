#include "ProductionHouse.hh"
#include <iostream>
#include <typeinfo>
#include <ctime>
#include <list>

using namespace std ;


 ProductionHouse :: ProductionHouse(vector<Mentor> men, vector<Publique> pub, vector<Jury> jur, vector<Candidat> can, vector<ProductionHouseTeam<ProMember>> pro) : _men(men), _pub(pub),_jur(jur),_can(can), _productionTeam(pro)
{

	Candidat c;
	candidatDivision(can);
	mentorAttribution();

	vector <Candidat> ::iterator iter;
	for(iter = _can.begin();iter!=_can.end();iter++){
		_result[iter->getName()] = 0;
	}
	
	Jury_Team<Jury> J(8,_jur.size(),_jur);
	_juryTeam.push_back(J);

	//cout << J.toString() <<endl;

	s1[0] = "Communication skills"; 
	s1[1] = "Intelligence";
	s1[2] = "Confidence";  
	s1[3] = "Beauty";
	s1[4] = "Talent";
	s1[5] = "Walk"; 

	s2[0] = "Wild"; 
	s2[1] = "Nature";
	s2[2] = "Talent";  
	s2[3] = "Personality";
	s2[4] = "Swimming";
	s2[5] = "Speed";
	
	
}

void ProductionHouse::candidatDivision(std::vector<Candidat> lc)
{
	vector<Candidat> :: iterator iter ; 
	vector<Candidat> l1 ;
	vector<Candidat> l2 ;
	unsigned int length_l1 = 0 ,length_l2  = 0 ;
	unsigned int size = (lc.size()/2);
	
	for (iter = lc.begin() ; iter != lc.end() ; ++iter)
	{
		iter->setSelected(true);

		if ((rand()%2 == 0) && (length_l1 < size))
		{
			   l1.push_back(*iter);
			   length_l1 ++ ;
		}
		else {
			if (length_l2 < size)
			{
				l2.push_back(*iter);
				length_l2 ++ ;
			}
		}
	}  
	
	Victim<Candidat> V1(length_l1,l1);
	Victim<Candidat> V2(length_l2,l2);
		
	_victimTeam.push_back(V1);
	_victimTeam.push_back(V2);

	/*
	for(auto it: _victimTeam)
		cout<<it.toString()<<endl;
	*/
	
}

void ProductionHouse::final(){

	string s = survey();
	countVoteFinal();
	
	map<string, int>::iterator it;
	it = _result.upper_bound(_can[_can.size()-1].getName());

	if(it->first == s)
	{
		if(_can[0].getName() == s)
			_can[1].setWinner(true);
		else
			_can[0].setWinner(true);

	}
}

void ProductionHouse::chooseTask(){

	string abilityTested1 = stringSelection(s1);
	string abilityTested2 = stringSelection(s2);
	int winNumber; 
	int i  = rand()%4;
	//int i  = 0;

	/* Le jeu sera moins long et plus logique si on fait toujours un fight entre victime
	et un combat de killer juste après.
	*/
	cout<<"Victim fight"<<endl;
	winNumber = _task.fashion_show_challenge(_victimTeam[0], _victimTeam[1], abilityTested1);
	cout<<"victim 1 "<< to_string(_victimTeam[1].getTeamNumber()) << endl;
	cout<<"victim 0 "<< to_string(_victimTeam[0].getTeamNumber()) << endl;
	cout << "winNumber : " << winNumber << endl;
	if(winNumber != 0)
		update(winNumber, abilityTested1);
	//if(!gameState()){
		//cout << "loser " << to_string(loser(winNumber)) << endl;
		//countVote(loser(winNumber));
		//eliminationRound(loser(winNumber));
		//reset();
	//}
	/*else
		countVoteFinal();*/
		vector<Candidat> lc;
			vector<Candidat> :: iterator iter ;
	
	switch(i){

		// Candidat a 0 ou pro a -1 = bug pour trouver le gagnant
		case 0:
			cout<<"Victim 1 /Jury fight"<<endl;
			winNumber = _task.surprise_challenge(_juryTeam[0], _victimTeam[1], abilityTested1, abilityTested2);
			cout<<"jury "<< to_string(_juryTeam[0].getTeamNumber()) << endl;
			cout<<"victim "<< to_string(_victimTeam[1].getTeamNumber()) << endl;
			cout << "winNumber : " << winNumber << endl;
			
			cout << "Avant"  << endl;			
			cout<<"victim "<< to_string(_victimTeam[1].getMemberNumber()) << endl;
			//for(iter = lc.begin() ; iter!=lc.end(); iter++)
				//cout<< iter->toString() << endl;
				
			if(winNumber != 0)
				updateFight1(winNumber, 1);
			cout << "Après"  << endl;	
			cout<<"victim "<< to_string(_victimTeam[1].getMemberNumber()) << endl;	
			lc =_victimTeam[1].getTeamMember() ; 
			for(iter = lc.begin() ; iter!=lc.end(); iter++)
			  cout<< iter->toString() << endl;
		break;
		case 1:
			cout<<"Victim 0 /Jury fight"<<endl;
			winNumber = _task.surprise_challenge(_juryTeam[0], _victimTeam[0], abilityTested1, abilityTested2);
			cout << "winNumber : " << winNumber << endl;
			cout<<"jury team "<< to_string(_juryTeam[0].getTeamNumber()) << endl;
			cout<<"victim team "<< to_string(_victimTeam[0].getTeamNumber()) << endl;
			if(winNumber != 0)
				updateFight1(winNumber, 0);
		break;
		case 2:
			cout<<"Victim 0 /Pro fight"<<endl;
			winNumber = _task.surprise_challenge(_productionTeam[0], _victimTeam[0], abilityTested1, abilityTested2);
			cout<<"pro "<< to_string(_productionTeam[0].getTeamNumber()) << endl;
			cout<<"victim "<< to_string(_victimTeam[0].getTeamNumber()) << endl;
			cout << "winNumber : " << winNumber << endl;
			if(winNumber != 0)
				updateFight2(winNumber, 0);
		break;
		case 3:
			cout<<"Victim 1 /Pro fight"<<endl;
			winNumber = _task.surprise_challenge(_productionTeam[0], _victimTeam[1], abilityTested1, abilityTested2);
			cout << "winNumber : " << winNumber << endl;
			if(winNumber != 0)
				updateFight2(winNumber, 1);
		break;
	
	};

}

void ProductionHouse::eliminationRound(int team){

	map<string, int>::iterator it;
	it = _result.upper_bound(_can[_can.size()-1].getName());

	for(auto iter : _can){

		if(iter.getName() == it->first){
			iter.setSelected(false);
		}
	}

	//updateList(team);
}

string ProductionHouse::survey(){

	Candidat c;
	for(auto it : _pub)
	{
		c = it.vote(_can);
		voteCandidat(c, it.getDecision_power());
	}	

	map<string, int>::iterator it;
	it = _result.upper_bound(_can[_can.size()-1].getName());

	return it->first;
}

void ProductionHouse::reset(){

	for(auto it : _result)
	{
		it.second = 0 ;
	}
}

void ProductionHouse::countVoteFinal(){

	Candidat c;

	for(auto it: _jur){
		c = it.vote(_can);
		voteCandidat(c, it.getDecision_power());
	}

	for(auto it : _men){
		c = it.vote(_can);
		voteCandidat(c, it.getDecision_power());
	}	

}

void ProductionHouse::countVote(int team){

	Candidat c;
	for(auto it: _jur){
		c = it.vote(_victimTeam[team]);
		voteCandidat(c);	
	}

	for(auto it : _men){
		c = it.vote(_victimTeam[team]);
		voteCandidat(c);	
	}	

}

void ProductionHouse::voteCandidat(Candidat c){

	for(auto it : _result){

		if(it.first == c.getName())
			it.second++;
	}

}

void ProductionHouse::voteCandidat(Candidat c, int decision_power){

	for(auto it : _result)
	{
		if(it.first == c.getName())
		{
				it.second += decision_power;
		}
	}

}

int ProductionHouse::loser(int winNumber)
{
	if( _victimTeam[0].getTeamNumber() == winNumber)
		return 1;
	return 0;
}
int ProductionHouse::gameState(){

	if(_can.size() == 2)
		return 1;
	
	return 0;
}

string ProductionHouse::stringSelection(string * s)
{
	int i = rand()%7;
	return s[i];
}

void ProductionHouse::mentorAttribution(){

	int teamA = _victimTeam[0].getTeamNumber();
	int teamB = _victimTeam[1].getTeamNumber();

	if(rand()%2 == 0 )
	{
		_men[0].set_team_number(teamA);
		_men[1].set_team_number(teamB);
	} 
	else
	{
		_men[0].set_team_number(teamB);
		_men[1].set_team_number(teamA);
	}

	
}

void ProductionHouse::update(int winNumber, string abilityTested1){

	if( _victimTeam[0].getTeamNumber() == winNumber) 
	{
		if(_men[0].get_team_number() == winNumber)
		{
			_men[0].enhance( _victimTeam[0], abilityTested1);

		}
		else
		{
			_men[1].enhance( _victimTeam[0], abilityTested1);
		}
	}
	else 
	{
		if(_men[0].get_team_number() == winNumber)
		{
			_men[0].enhance( _victimTeam[1], abilityTested1);
		}
		else
		{ 
			_men[1].enhance( _victimTeam[1], abilityTested1);
		}

	}
}


void ProductionHouse::updateFight1(int winNumber, int team){
	
	Candidat c ;
	vector<Candidat> ::iterator it ;
	vector<Candidat> v ; 

	
	if(_juryTeam[0].getTeamNumber() == winNumber)
	{
		_juryTeam[0].lowerSkills(_victimTeam[team]);

		c = _juryTeam[0].candidatKill(_victimTeam[team]);
					
			v = _victimTeam[team].getTeamMember();
		for (it = v.begin() ; it !=v.end(); ++it )
		{	
			if( *it == c)
				it->setSelected(false); 
		}
		_victimTeam[team].setTeamMember(v);
		_victimTeam[team].survivor();

		if(_victimTeam[team].getTask() == true)
			winNumber = _task.surprise_challenge(_juryTeam[0], _victimTeam[team], stringSelection(s1), stringSelection(s2));

			if(_victimTeam[team].getTeamNumber() == winNumber)
			{
				v = _victimTeam[team].getTeamMember();
				for (it = v.begin() ; it !=v.end(); ++it )
				{	
					if( *it == c)
						it->setSelected(true); 
				}
				_victimTeam[team].setTeamMember(v);
			}	
		else 
		{
			for (it = _can.begin() ; it!=_can.end() ; it++ )
				{	
					if( *it == c )
						it->setSelected(false); 
				}
			updateList(team);
		}
	}	


}

 void ProductionHouse::updateFight2(int winNumber, int team){

	
	Candidat c ;
	if(_productionTeam[0].getTeamNumber() == winNumber)
	{
		cout << "Avant" <<endl;
		for(auto it : _victimTeam[team].getTeamMember())
			cout << to_string(it.getPopularity()) << endl;

		_productionTeam[0].lowerPopularity(_victimTeam[team]);

		cout << "Après" <<endl;
		for(auto it : _victimTeam[team].getTeamMember())
			cout << to_string(it.getPopularity()) << endl;

		c = _productionTeam[0].candidatKill(_victimTeam[team]);	
			
		for (auto it : _victimTeam[team].getTeamMember())
			{	
				if( it == c)
					it.setSelected(false); 
			}
			_victimTeam[team].survivor();

			if(_victimTeam[team].getTask() == true)
				winNumber = _task.surprise_challenge(_productionTeam[0], _victimTeam[team], stringSelection(s1), stringSelection(s2));

			if(_victimTeam[team].getTeamNumber() == winNumber)
				{
					for (auto it : _victimTeam[team].getTeamMember())
					{	
						if( it == c)
							it.setSelected(true); 
					}
				}	
			else 
			{
				for (auto it : _can)
					{	
						if( it == c)
							it.setSelected(false); 
					}
				updateList(team);
			}		
		}

 }

 void ProductionHouse::updateList(int team){

 	vector<Candidat> vc = _victimTeam[team].getTeamMember();
 	list<Candidat> :: iterator iter ; 
 	list<Candidat> lc;
cout<<"updatelist"<<endl;
 	copy(begin(vc), end(vc), back_inserter(lc));
 	for(iter = lc.begin() ; iter != lc.end() ; ++iter){
 		if(iter->getSelected() == false)
 		{
 			iter = lc.erase(iter);	
 		}
 	}
 	copy(begin(lc), end(lc), back_inserter(vc));
 	
 	_victimTeam[team].setTeamMember(vc) ; 
 	int val = _victimTeam[team].getMemberNumber() - 1 ;
 	_victimTeam[team].setMemberNumber(val ) ;
 	cout<<"victim_ "<< to_string(_victimTeam[team].getMemberNumber()) << endl;
 	
 	updateCandidat();

 }

void ProductionHouse::updateCandidat(){

	list <Candidat> lc;
 	list<Candidat> :: iterator iter ; 

 	copy(begin(_can), end(_can), back_inserter(lc));
 	for(iter = lc.begin() ; iter != lc.end() ; ++iter){
 		if(iter->getSelected() == false)
 		{
 			iter = lc.erase(iter);	
 		}
 	}
 	copy(begin(lc), end(lc), back_inserter(_can));

}


