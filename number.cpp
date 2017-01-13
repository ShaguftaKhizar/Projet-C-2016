#include "number.hh"

int val_team(){ 
	
	static int teamNummber = 0 ; 
	teamNummber++; 
	return teamNummber;
}