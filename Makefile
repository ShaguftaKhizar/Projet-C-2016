
all : Prog
CFLAGS = g++ -Wall -g -std=c++11

Prog: Publique.o Candidat.o Jury.o Mentor.o main.o 
	$(CFLAGS) Publique.o  Jury.o Candidat.o Mentor.o main.o  -o Prog

Candidat.o : Candidat.cpp Candidat.hh
	$(CFLAGS) -c Candidat.cpp
		
Publique.o : Publique.hh Publique.cpp
	$(CFLAGS) -c Publique.cpp
	
Jury.o : Jury.hh Jury.cpp
	$(CFLAGS) -c Jury.cpp

Mentor.o : Mentor.hh Mentor.cpp
	$(CFLAGS) -c Mentor.cpp

main.o : main.cc
	$(CFLAGS) -c main.cc

	
clean:
	rm -f *.o Prog
	
