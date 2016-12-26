all: teampart

CFLAGS= -Wall -g

teampart : main.o Candidat.o Victim.o Jury_Team.o ProductionHouseTeam.o
	g++ $(CFLAGS) Candidat.o Victim.o Jury_Team.o ProductionHouseTeam.o main.o -o teampart --std=c++11
	
 main.o :  main.cc
	g++ $(CFLAGS) -c  main.cc --std=c++11
	
Candidat.o : Candidat.cpp Candidat.hh
	g++ $(CFLAGS) -c Candidat.cpp --std=c++11

Victim.o : Victim.cpp Victim.hh
	g++ $(CFLAGS) -c Victim.cpp --std=c++11

Jury_Team.o : Jury_Team.cpp Jury_Team.hh
	g++ $(CFLAGS) -c Jury_Team.cpp --std=c++11

ProductionHouseTeam.o : ProductionHouseTeam.cpp ProductionHouseTeam.hh
	g++ $(CFLAGS) -c ProductionHouseTeam.cpp --std=c++11

clean :
	rm -f *.o teampart