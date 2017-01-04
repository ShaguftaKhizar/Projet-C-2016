#include "ProductionHouse.hh"
#include <typeinfo>
#include <ctime>

using namespace std ;


 ProductionHouse :: ProductionHouse(std:: list<Mentor> men,std:: list<Publique> pub, std:: list<Jury> jur,std:: list<Candidat> can) : _men(men), _pub(pub),_jur(jur),_can(can)
{
	
	candidatDivision(can);
	
	Jury_Team<Jury> J(8,_jur.size(),_jur);
	_juryTeam.push_back(J);
	
	
}

void ProductionHouse::candidatDivision(std::list<Candidat> lc)

{
	list<Candidat> :: iterator iter ; 
	list<Candidat> l1 ;
	list<Candidat> l2 ;
	unsigned int length_l1 = 0 ,length_l2  = 0 ;
	
	
	for (iter = lc.begin() ; iter != lc.end() ; ++iter)
	{
		if (rand()%2 == 0 &&  length_l1< (lc.size()/2))
		{
			   l1.push_back(*iter);
			   length_l1 ++ ;
		}
		else {
			if ( length_l2 < (lc.size()/2))
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





