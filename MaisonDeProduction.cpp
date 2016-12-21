#include "MaisonDeProduction.hh"
#include <typeinfo>
#include <ctime>

using namespace std ;


void MaisonDeProduction::countVote(std::vector<Electeur> vec)
{
    vector<Electeur> :: iterator iter1 ;
    int i ; 
    
    Candidat cand ;
    
// vote et comptabilisation
	for (iter1 = vec.begin(); iter1 != vec.end() ; ++ iter1) {
		cand  = *iter1.vote(lc) ;		// lc est la liste de candidat. comment je la récupère ??	
		switch (typeid(*iter1)){
			
		case  Public : 
			_resultCandidat[cand]++ ; 
			break ; 
		
		case Jury :
			for ( i = 0 ; i < *iter._decision_power ; i++)
				_resultCandidat[cand]++ ;
			break ; 
		
		case Mentor :
			for ( i = 0 ; i < *iter._decision_power ; i++)
				_resultCandidat[cand]++ ;
			break ; 	
			
		}
	}
}

void MaisonDeProduction:: toString_result(){	
	//délibération 
	std::map< Candidat,int > ::iterator iter2  ,iter3; 
	    iter2 = _resultCandidat.begin(); 
		iter3 = _resultCandidat.end() ; 
		
		cout << "Les resultats des votes sont : "<<endl; 
		cout << iter2->first <<" :"<<iter2->second<<"votes"<<endl;
		cout << iter3->first <<" :"<<iter3->second<<"votes"<<endl;
}
 
 
void MaisonDeProduction::survey(std::vector<Electeur> vec ) // savoir qui le public préfère ? ou globalement ?
{
      vector<Electeur> :: iterator iter1 ;
    int i ; 
    
    Candidat cand ;
    
// vote et comptabilisation
	for (iter1 = vec.begin(); iter1 != vec.end() ; ++ iter1) {
		cand  = *iter1.vote(lc) ;		// lc est la liste de candidat. comment je la récupère ??	
		switch (typeid(*iter1)){
			
		case  Public : 
			_resultSurvey [cand]++ ; 
			break ; 
		
		case Jury :
			for ( i = 0 ; i < *iter._decision_power ; i++)
				_resultSurvey[cand]++ ;
			break ; 
		
		case Mentor :
			for ( i = 0 ; i < *iter._decision_power ; i++)
				_resultSurvey[cand]++ ;
			break ; 	
			
		}
		
		/* if ( typeid(*iter1) == Public )
		 * 	resultSurvey [cand]++ ; 
		 */
		
	}
}
  
  
void MaisonDeProduction:: toString_survey(){
//délibération 
	std::map< Candidat,int > ::iterator iter2  ,iter3; 
	    iter2 = _resultSurvey.begin(); 
		iter3 = _resultSurvey.end() ; 
		
		cout << "Les resultats du sondage sont : "<<endl; 
		cout << iter2->first <<" :"<<iter2->second<<"votes"<<endl;
		cout << iter3->first <<" :"<<iter3->second<<"votes"<<endl;
	   
}
    
void MaisonDeProduction::updateTeamList(Team&  victim , Candidat& cand )
{
    /* je supprime le candidat de la liste des candidats et de l'équipe
     *  et je diminue le nb de membre que possède cette équipe 
     */
     victim.Team_member.erase (cand);
     victim.Team_number -- ;
     
     list<Candidat> :: iterator iter = cand.begin();
     
     if (cand == *iter)
		cand.erase(iter);
	else 
		++iter ; 
     
}


/*void MaisonDeProduction::candidatTwist()
{
    
}*/

void MaisonDeProduction::updateCandidatSkill(Team&  victim , std::string competence)
{
    std:: vector<Mentor> :: iterator iter2  = _mentor.begin(), iter3 = _mentor.end();
    /* On cherche qui est le mentor */
    
    if (victim._team_number == *iter2._team_number) 	
		*iter2.enhance(victim , competence);
	else 
		*iter3.enhance(victim , competence);    
}


void MaisonDeProduction::candidatDivision(std::list<Candidat> lc)

{
	list<Candidat> :: iterator iter ; 
	srand(time(NULL));
	for (iter = lc.begin() ; iter != lc.begin ; ++iter)
	{
		if (rand()%2 == 0 && _victimTeamA.member_number < (lc.size()/2))
		{
			_victimTeamA.Team_member[*iter]++;
			_victimTeamA.member_number ++ ;
		}
		else {
			if (_victimTeamB.member_number < (lc.size()/2))
			{
				_victimTeamB.Team_member[*iter]++;
				_victimTeamB.member_number ++ ;
			}
		}
	}
	_victimTeamA.team_number = 0 ;
	_victimTeamB.team_number = 1 ;
    
}


void MaisonDeProduction::affectation()

{
	/* affecte à chaque mentor une équipe victime 
	 * il n'y a que deux mentors ici 
	 * donc  on suppose le premier tire au sort son équipe 
	 * et le second prend celle par défaut
	 */
	 
	srand(time(NULL));
	std:: vector<Mentor> :: iterator iter2  = _mentor.begin(), iter3 = _mentor.end();
	if (rand()%2 == 0 ) 
		*iter2._team_number = 1 ;
		
	*iter3._team_number = 1 ;
    
}


void MaisonDeProduction::chooseTask()
{
	/* choix des equipes qui vont s'affronter */
	
	/* choix de l'epreuve + epreuve */
	
	/*si epreuve oppose 2 equipe victim*/
		updateCandidatSkill(/*equipe gagnante et competence à modifier*/);
	/* si epreuve oppose killer et victim
	 * si gagnant est victim */
	  updateCandidatSkill(/*equipe gagnante et competence à modifier*/);
	  /*si gagant est kill 
	   * On applique les methodes qui leur sont propres 
	   */
	   /*si candidat éliminé alors demande s'il veut suvivre et si oui alors on le garde dans la liste */
	   /*si candidat éliminé et que survie s'est fait plus d'une fois, on met à jour la liste de candidat et des équipes*/
		updateTeamList(/*candidat  à éliminer  et équipe*/); 
    
    
}

/*void MaisonDeProduction::division(void  vecteur<Electeur>){}
 * void MaisonDeProduction::division(void  vecteur<Prod>){
}*/
