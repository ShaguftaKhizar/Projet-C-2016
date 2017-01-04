all: teampart

CFLAGS= g++ -Wall -g --std=c++11

#Victim.o Jury.o Mentor.o Jury_Team.o ProductionHouseTeam.o  
teampart : main.o Candidat.o  Publique.o  Jury.o Mentor.o Task.o ProductionHouse.o
	 $(CFLAGS) Candidat.o Publique.o  main.o Jury.o Mentor.o Task.o ProductionHouse.o -o teampart 
	
main.o :  main.cc
	$(CFLAGS) -c  main.cc 
	
Candidat.o : Candidat.cpp Candidat.hh
	 $(CFLAGS) -c Candidat.cpp 

Jury.o : Jury.cpp Jury.hh
	$(CFLAGS) -c Jury.cpp 

Mentor.o : Mentor.cpp Mentor.hh
	 $(CFLAGS) -c Mentor.cpp 

Publique.o : Publique.cpp Publique.hh
	$(CFLAGS) -c Publique.cpp 

#Victim.o : Victim.cpp Victim.hh
#	$(CFLAGS) -c Victim.cpp 

#Jury_Team.o : Jury_Team.cpp Jury_Team.hh
#	 $(CFLAGS) -c Jury_Team.cpp 

#ProductionHouseTeam.o : ProductionHouseTeam.cpp ProductionHouseTeam.hh
#	$(CFLAGS) -c ProductionHouseTeam.cpp 

ProductionHouse.o : ProductionHouse.cpp ProductionHouse.hh
	$(CFLAGS) -c ProductionHouse.cpp 

Task.o : Task.cpp Task.hh
	$(CFLAGS) -c Task.cpp 

clean :
	rm -f *.o teampart

test :
	./teampart 
