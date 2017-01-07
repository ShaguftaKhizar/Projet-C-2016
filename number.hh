#pragma once

int val_team(){ 
	
	static int teamNummber = 0 ; 
	teamNummber++; 
	return teamNummber;
}