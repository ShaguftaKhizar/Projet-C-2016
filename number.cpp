#include "number.hh"
#include "Candidat.hh"
#include <string>
#include <map>
#include <iostream>

using namespace std;

int val_team(){ 
	
	static int teamNummber = 0 ; 
	teamNummber++; 
	return teamNummber;
}

int upperBound(map<string, int> m){

	map<string, int>::iterator iter;
	int max = 0;
	int val = 0;

	for(iter = m.begin(); iter != m.end(); iter++){

		val = iter->second; 
		if(val > max){
			max = val;
		}
	}

	return max;
}

string upperBounds(map<string, int> m){

	map<string, int>::iterator iter;
	int max = 0, val = 0;
	string s;

	for(iter = m.begin(); iter != m.end(); iter++){

		val = iter->second; 
		if(val > max){
			max = val;
			s = iter->first;
		}
	}

	return s;	

}
/*
void test(){

	Candidat c("test", 30, "decsr");

	for(auto it : c.getAbilities())
		cout << it.first << to_string(it.second) << endl;

	string s = upperBounds(c.getAbilities());
	cout << "string : " << s << endl;
	

}*/