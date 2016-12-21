#include "Jury.hh"
#include "Candidat.hh"
#include <ctime>

//Methode vote 
Candidat* Jury::vote(list<Candidat> lc)const 
{
	  srand(time(NULL));
	  
	list <Candidat>::iterator first = lc.begin() , second = lc.end(); 

		if(*first == abilitie_preference && *second == abilitie_preference )		
			{ /*on choisit au hasard le gagnant pour le public*/
				if( (rand()% 2) == 0)
					return *first ;
				else 
					return *second ;
			}
		else {
			if (*first == abilitie_preference) 
				return *first ;
			else
				return *second ;
			}
}

/*Le jury a une liste de preferences (d'exigences) sur laquelle il se base pour voter*/
void Jury::abilityInit()
{
	srand(time(NULL));
	abilitie_preference["Communication skills"] = 0; 
	abilitie_preference["Intelligence"] = 0; 
	abilitie_preference["Confidence"] = 0; 
	abilitie_preference["Beauty"] = 0; 
	abilitie_preference["Talent"] = 0; 
	abilitie_preference["Walk"] = 0; 
	
	if ((rand()%2) == 0){
		abilitie_preference["Communication skills"] = rand()%(51-35) + 35; // compétence minimale 
		abilitie_preference["Intelligence"] = rand()%(51-35) + 35; 
		abilitie_preference["Confidence"] = rand()%(51-35) + 35; 
	}
	else {
		abilitie_preference["Beauty"] = rand()%(51-35) + 35; 
		abilitie_preference["Talent"] = rand()%(51-35) + 35; 
		abilitie_preference["Walk"] = rand()%(51-35) + 35; 
	}

}
