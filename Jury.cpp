#include "Jury.hh"
#include "Candidat.hh"
#include <vector>
#include <map>
#include <ctime>

using namespace std;

Candidat Jury::vote(vector<Candidat> lc)const 
{				  
			  
	vector <Candidat> ::const_iterator first = lc.begin() , second = lc.end(); 
	Candidat c1 = *first ;
	Candidat c2 = *second ; 

	map<string,int>::const_iterator it,it_first,it_second ;
	int max = upperBound(abilitie_preference);

	it_first = c1.getAbilities().find(it->first)  ;
	it_second = c2.getAbilities().find(it->first)  ;
				
	if(( it_first->second   >=  max && it_second->second   >=  max)||( it_first->second   <  max &&it_second->second   <  max))					
	{ /*on choisit au hasard le gagnant*/
		if( (rand()% 2) == 0)
			return c1 ;
		else 
			return c2;
	}
	else
	{ 
		if (it_first->second   >=  max) 
			return c1;
		else
			return c2 ;

	}

}

/*Le jury a une vectore de preferences sur laquelle il se base pour voter*/
void Jury::abilityInit()
{
		abilitie_preference["Communication skills"] = rand()%(51-35) + 35; // compétence minimale 
		abilitie_preference["Intelligence"] = rand()%(51-35) + 35; 
		abilitie_preference["Confidence"] = rand()%(51-35) + 35; 
		abilitie_preference["Beauty"] = rand()%(51-35) + 35; 
		abilitie_preference["Talent"] = rand()%(51-35) + 35; 
		abilitie_preference["Walk"] = rand()%(51-35) + 35; 
}


string Jury::toString()const{
	map<string, int>:: const_iterator it;
	string s;

	s += "Nom : " + _name + "\n" ;
	s += "Preferences: \n";
	for(auto it : abilitie_preference)
	{
		s += it.first + " : "; 
		s += to_string(it.second) + " % | ";	
	}
	s += "\n\n";

	return s;
	
}
