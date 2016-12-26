#pragma once
#include <list>
#include "Candidat.hh"
#include "Team.hh"

class Task{

public:
	/*	Task between 2 victim teams	*/
	Victim& fashion_show_challenge(const Victim& v1, const Victim& v2);
	Victim& iq_test_challenge(const Victim& v1, const Victim& v2);
	Victim& vakeUp_challenge(const Victim& v1, const Victim& v2);
	Victim& valent_challenge(const Victim& v1, const Victim& v2);
	Victim& vhotoshoot_challenge(const Victim& v1, const Victim& v2);	

	/*	Task between a team and a killer team	*/	
	Team& surprise_challenge(const Team& t1, const Team& t2);
	Team& jungle_challenge(const Team& t1, const Team& t2);	
	Team& sea_challenge(const Team& t1, const Team& t2);	
	Team& roar_challenge(const Team& t1, const Team& t2);	
	Team& speed_challenge(const Team& t1, const Team& t2);	

};