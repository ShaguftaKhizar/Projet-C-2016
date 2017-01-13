all: teampart

CFLAGS= g++ -Wall -g --std=c++11

teampart : main.o Candidat.o  Publique.o  Jury.o Mentor.o ProductionHouse.o number.o 
	 $(CFLAGS) Candidat.o Publique.o  main.o Jury.o Mentor.o ProductionHouse.o number.o -o teampart 
	
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

ProductionHouse.o : ProductionHouse.cpp ProductionHouse.hh
	$(CFLAGS) -c ProductionHouse.cpp 

number.o : number.cpp number.hh
	$(CFLAGS) -c number.cpp

clean :
	rm -f *.o teampart

test :
	./teampart 
