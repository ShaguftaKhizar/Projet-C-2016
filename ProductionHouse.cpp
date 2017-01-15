#include "ProductionHouse.hh"
#include <iostream>
#include <typeinfo>
#include <ctime>
#include <list>

using namespace std ;


 ProductionHouse::ProductionHouse(vector<Mentor> men, vector<Publique> pub, vector<Jury> jur, vector<Candidat> can, vector<ProductionHouseTeam<ProMember>> pro) : _men(men), _pub(pub),_jur(jur),_can(can), _productionTeam(pro)
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
	
}

void ProductionHouse::chooseTask(){

	string abilityTested1 = stringSelection(s1);
	string abilityTested2 = stringSelection(s2);
	int winNumber; 
	int i  = rand()%4;

	cout<<"*********** EPREUVE D'EQUIPE : ***********"<<endl;
	cout<<"EQUIPE 1 : " << _victimTeam[1].toString() << endl;
	cout<<"EQUIPE 2 : " << _victimTeam[0].toString() << endl;
	winNumber = _task.fashion_show_challenge(_victimTeam[0], _victimTeam[1], abilityTested1);

	if(winNumber != 0){
		cout << "L'EQUIPE GAGNANTE EST : L'EQUIPE " << winNumber << endl;
		update(winNumber, abilityTested1);
	}
	else
		cout << "L'EQUIPE GAGNANTE EST : EGALITE " << endl;
	if(!gameState()){
		switch(loser(winNumber)){
			case 0:
			cout << "L'EQUIPE PASSANT AUX ELIMINATIONS EST : L'EQUIPE " << to_string(_victimTeam[0].getTeamNumber()) << endl;
			break;
			case 1:
			cout << "L'EQUIPE PASSANT AUX ELIMINATIONS EST : L'EQUIPE " << to_string(_victimTeam[1].getTeamNumber()) << endl;
			break;
		}
		countVote(loser(winNumber));
		eliminationRound(loser(winNumber));
		reset();
	}
	else
		countVoteFinal();
	
	switch(i){

		case 0:
			cout<<"*********** EPREUVE DE SURVIE : ***********"<<endl;
			cout<<"L'EQUIPE " << to_string(_victimTeam[1].getTeamNumber()) << " DOIT AFFRONTER ";
			cout<<"L'EQUIPE DE JURY "<< to_string(_juryTeam[0].getTeamNumber()) << endl;
			cout << _juryTeam[0].toString() << endl;

			winNumber = _task.surprise_challenge(_juryTeam[0], _victimTeam[1], abilityTested1, abilityTested2);
			
			if(winNumber != 0){
				cout << "L'EQUIPE GAGNANTE EST : L'EQUIPE " << winNumber << endl;
				updateFight1(winNumber,1);
			}
			else
				cout << "L'EQUIPE GAGNANTE EST : EGALITE " << endl;
		break;
		case 1:
			cout<<"*********** EPREUVE DE SURVIE : ***********"<<endl;
			cout<<"L'EQUIPE " << to_string(_victimTeam[0].getTeamNumber()) << " DOIT AFFRONTER ";
			cout<<"L'EQUIPE DE JURY "<< to_string(_juryTeam[0].getTeamNumber()) << endl;
			cout << _juryTeam[0].toString() << endl;

			winNumber = _task.surprise_challenge(_juryTeam[0], _victimTeam[0], abilityTested1, abilityTested2);
			
			if(winNumber != 0){
				cout << "L'EQUIPE GAGNANTE EST : L'EQUIPE " << winNumber << endl;
				updateFight1(winNumber,0);
			}
			else
				cout << "L'EQUIPE GAGNANTE EST : EGALITE " << endl;
		break;
		case 2:
			cout<<"*********** EPREUVE DE SURVIE : ***********"<<endl;
			cout<<"L'EQUIPE " << to_string(_victimTeam[0].getTeamNumber()) << " DOIT AFFRONTER ";
			cout<<"L'EQUIPE DE PROFESSIONNELS "<< to_string(_productionTeam[0].getTeamNumber()) << endl;
			cout << _productionTeam[0].toString() << endl;

			winNumber = _task.surprise_challenge(_productionTeam[0], _victimTeam[0], abilityTested1, abilityTested2);

			if(winNumber != 0){
				cout << "L'EQUIPE GAGNANTE EST : L'EQUIPE " << winNumber << endl;
				updateFight2(winNumber, 0);
			}
			else
				cout << "L'EQUIPE GAGNANTE EST : EGALITE " << endl;
		break;
		case 3:
			cout<<"*********** EPREUVE DE SURVIE : ***********"<<endl;
			cout<<"L'EQUIPE " << to_string(_victimTeam[1].getTeamNumber()) << " DOIT AFFRONTER ";
			cout<<"L'EQUIPE DE PROFESSIONNELS "<< to_string(_productionTeam[0].getTeamNumber()) << endl;
			cout << _productionTeam[0].toString() << endl;

			winNumber = _task.surprise_challenge(_productionTeam[0], _victimTeam[1], abilityTested1, abilityTested2);

			if(winNumber != 0){
				cout << "L'EQUIPE GAGNANTE EST : L'EQUIPE " << winNumber << endl;
				updateFight2(winNumber, 1);
			}
			else
				cout << "L'EQUIPE GAGNANTE EST : EGALITE " << endl;
		break;
	
	};

}

void ProductionHouse::final(){

	string s = survey();
	countVoteFinal();
	
	string smax;
	smax = upperBounds(_result);

	if(smax == s)
	{
		if(_can[0].getName() == s){
			
			_can[1].setWinner(true);
			cout << "************* ET LE GAGNANT EST : *****************\n" << endl;
			cout << _can[1].toString() << endl;
		}
		else{
			
			_can[0].setWinner(true);
			cout << "************* ET LE GAGNANT EST : *****************\n" << endl;
			cout << _can[0].toString() << endl;

		}
	}
}

void ProductionHouse::eliminationRound(int team){

	string s = upperBounds(_result);
	vector<Candidat>::iterator iter;

	for(iter = _can.begin(); iter != _can.end(); iter++){

		if(iter->getName() == s){
			iter->setSelected(false);
			updateList(team, *iter);
			break;
		}
	}

}

string ProductionHouse::survey(){

	Candidat c;
	for(auto it : _pub)
	{
		c = it.vote(_can);
		voteCandidat(c, it.getDecision_power());
	}	
	string s = upperBounds(_result);

	return s;
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

	cout << "RESULTAT DES VOTES POUR LE VAINQUEUR " << endl;
	for(auto it : _result){
		cout << it.first << " : " << to_string(it.second) << endl; 
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

	cout << "RESULTAT DES VOTES POUR L'ELIMINATION " << endl;
	for(auto it : _result){
		cout << it.first << " : " << to_string(it.second) << endl; 
	}
}

void ProductionHouse::voteCandidat(Candidat c){

	map<string, int>::iterator it;
	for(it = _result.begin(); it!= _result.end(); it++){

		if(it->first == c.getName()){
			it->second++;
		}
	}

}

void ProductionHouse::voteCandidat(Candidat c, int decision_power){

	map<string, int>::iterator it;
	for(it = _result.begin(); it!= _result.end(); it++)
	{
		if(it->first == c.getName())
		{
			it->second += decision_power;
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
			cout << "LE MENTOR DE L'EQUIPE " << to_string(winNumber) << endl;
			cout << _men[0].toString() << endl;
			_men[0].enhance( _victimTeam[0], abilityTested1);
		}
		else
		{
			cout << "LE MENTOR DE L'EQUIPE " << to_string(winNumber) << endl;
			cout << _men[1].toString() << endl;
			_men[1].enhance( _victimTeam[0], abilityTested1);
		}
	}
	else 
	{
		if(_men[0].get_team_number() == winNumber)
		{
			cout << "LE MENTOR DE L'EQUIPE " << to_string(winNumber) << endl;
			cout << _men[0].toString() << endl;
			_men[0].enhance( _victimTeam[1], abilityTested1);
		}
		else
		{ 
			cout << "LE MENTOR DE L'EQUIPE " << to_string(winNumber) << endl;
			cout << _men[1].toString() << endl;
			_men[1].enhance( _victimTeam[1], abilityTested1);
		}

	}
}

void ProductionHouse::swapCandTeam (int position , int team){

		vector<Candidat> v1 = _victimTeam[team].getTeamMember() ; 
		vector<Candidat> :: iterator it ; 
		
		Candidat c ;
		c = v1[position] ;
		v1[position] = v1[v1.size() - 1] ;
		v1[v1.size() - 1] = c ;
		  
		v1.pop_back();
		  
		_victimTeam[team].setTeamMember(v1);

		  /* Autiliser si on veut faire un affichage
		  for(it = v1.begin() ; it!=v1.end(); it++)
			  cout<< it->toString() << endl;*/
		 //Cette instruction fait un abort
		 //cout<<_victimTeam[team].toString()<<endl; 
	
}

void ProductionHouse::updateList(int team , Candidat& c1){
	
	vector<Candidat> :: iterator it ; 
	vector<Candidat> v1 = _victimTeam[team].getTeamMember() ; 
	int i = 0 , index = 0  ;
		
	// On récupère la position du candidat dans la liste
	for ( it = v1.begin() ; it != v1.end() ; it++){	
		if( *it == c1 ) 
			index = i;  	
		i++;
	}
	
	cout << endl << "LE CANDIDAT ELIMINE EST : " << endl;
	cout << c1.toString() << endl << endl; 

	swapCandTeam (index,team);
	updateCandidat(c1);
	
}

void ProductionHouse::swapCandList (int position){
	
	Candidat c ;
 	c = _can[position] ; 
	_can[position] = _can[_can.size() - 1]; 
	_can[_can.size() - 1] = c ;
	_can.pop_back();
		  	
}


void ProductionHouse::updateCandidat(Candidat& c1){
	
	vector<Candidat>::iterator it ; 	
	int i = 0 , index = 0  ;
		
	// On récupère la position du candidat dans la liste
	for ( it = _can.begin() ; it != _can.end() ; it++){	
		if( *it == c1 ) 
			index = i;  	
		i++;
	}
	
	swapCandList(index);
}


void ProductionHouse::updateFight1(int winNumber ,int team){
	
	Candidat c ;
	vector<Candidat>::iterator it ;
	vector<Candidat> v ;
	c.setSelected(true); 
		
	if(_juryTeam[0].getTeamNumber() == winNumber)
	{
		_juryTeam[0].lowerSkills( _victimTeam[team]);
		cout << "LES CANDIDATS VIENNENT DE PERDRE EN COMPETENCE " << endl;
		c = _juryTeam[0].candidatKill(_victimTeam[team]);

		if(c.getName() == "ZERO")
			exit(0);
		
		cout << "CANDIDAT KILL SUITE A LA DEFAITE" << endl;	
		cout<< c.toString() << endl;
					
		updateList(team ,c);

		_victimTeam[team].survivor();

		if(_victimTeam[team].getTask() == true)
			winNumber = _task.surprise_challenge(_juryTeam[0], _victimTeam[team], stringSelection(s1), stringSelection(s2));

			if(_victimTeam[team].getTeamNumber() == winNumber) /*test si le numero du gagnant à changé*/
			{
				cout << "L'EQUIPE A SAUVER SON MEMBRE EN REMPORTANT UNE AUTRE EPREUVE" << endl;
				v = _victimTeam[team].getTeamMember();
				for (it = v.begin() ; it !=v.end(); ++it )
				{	
					if( *it == c ){
						it->setSelected(true); 
						break ; 
					}
				}
				_victimTeam[team].setTeamMember(v);
			}	
		else 
		{
			for (it = _can.begin() ; it!=_can.end() ; it++ )
			{	
				if( *it == c ){
					it->setSelected(false); 
					break ; 
			    }
			}
		}
	}	


}

 void ProductionHouse::updateFight2(int winNumber, int team){

	
	Candidat c ;
	vector<Candidat>::iterator it ;
	vector<Candidat> v;

	if(_productionTeam[0].getTeamNumber() == winNumber)
	{	

		_productionTeam[0].lowerPopularity(_victimTeam[team]);
		cout << "LES CANDIDATS VIENNENT DE PERDRE EN POPULARITE " << endl;
		c = _productionTeam[0].candidatKill(_victimTeam[team]);	

		if(c.getName() == "ZERO")
			exit(0);

		cout << "CANDIDAT KILL SUITE A LA DEFAITE" << endl;	
		cout<< c.toString() << endl;
			
		updateList(team ,c);

		_victimTeam[team].survivor();

		if(_victimTeam[team].getTask() == true)
			winNumber = _task.surprise_challenge(_productionTeam[0], _victimTeam[team], stringSelection(s1), stringSelection(s2));

		if(_victimTeam[team].getTeamNumber() == winNumber)
		{
			cout << "L'EQUIPE A SAUVER SON MEMBRE EN REMPORTANT UNE AUTRE EPREUVE" << endl;
			v = _victimTeam[team].getTeamMember();
			for (it = v.begin(); it!= v.end(); it++)
			{	
				if( *it == c )
					it->setSelected(true); 
			}	
			_victimTeam[team].setTeamMember(v);
		}
		else 
		{
			for ( it = _can.begin(); it != _can.end(); it++)
			{	
				if( *it == c )
					it->setSelected(false); 	
			}
		}		
	}
 
 }

