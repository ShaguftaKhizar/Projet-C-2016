#include <list>
#include "Candidat.hh"
#include "Team.hh"
#include "Task.hh"

using namespace std;

Team& Task::fashion_show_challenge(const Team& t1, const Team& t2){

	if((t1 == Killer) || (t2 == Killer))
		cerr << " This is not a survival challenge " << endl;

	if(t1.getTeamMember().getAbilities() >= 50)
	{
		if(t2.getTeamMember().getAbilities() >= 50)
			return NULL;

	}

	if(t1.getTeamMember().getAbilities() <= 50)
	{
		if(t2.getTeamMember().getAbilities() >= 50)
			return t2;

	}

	if(t1.getTeamMember().getAbilities() >= 50)
	{
		if(t2.getTeamMember().getAbilities() <= 50)
			return t1;

	}



}

Team& Task::iq_test_challenge(const Team& t1, const Team& t2){

	if((t1 == Killer) || (t2 == Killer))
		cerr << " This is not a survival challenge " << endl;

}

Team& Task::makeUp_challenge(const Team& t1, const Team& t2){

	if((t1 == Killer) || (t2 == Killer))
		cerr << " This is not a survival challenge " << endl;

}

Team& Task::commercial_challenge(const Team& t1, const Team& t2){

	if((t1 == Killer) || (t2 == Killer))
		cerr << " This is not a survival challenge " << endl;

}

Team& Task::photoshoot_challenge(const Team& t1, const Team& t2){

	if((t1 == Killer) || (t2 == Killer))
		cerr << " This is not a survival challenge " << endl;

}
