
#include "Publique.hh"
#include "Jury.hh"
#include "Candidat.hh"
#include "Mentor.hh"
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <map>
using namespace std;

int main()
{
    srand(time(NULL));

    list< Candidat > lc;

    lc.push_back(Candidat("Vanessa Paradis", 45, "je suis une chanteuse de renomme mondiale"));
    lc.push_back(Candidat("Maite", 60, "je suis ronde et enjoue"));
    lc.push_back(Candidat("Kate Moss", 30, "je suis un mannequin de renomme mondiale"));
    lc.push_back(Candidat("Ashweria Rai", 43, "je suis une ancienne miss monde"));
    lc.push_back(Candidat("Keira Knightley", 33, "je suis une actrice de renomme mondiale"));
    lc.push_back(Candidat("Mimie Maty", 46, "je suis une actrice de petite taille"));
    lc.push_back(Candidat("Taylor Swift", 26, "je suis une chanteuse tres talentueuse"));
    lc.push_back(Candidat("Selena Gomez", 23, "je suis une ancienne actrice Disney"));
    lc.push_back(Candidat("Ailee", 28, "je suis une celebre chanteuse corenne"));
    lc.push_back(Candidat("Magalie Vae", 34, "je suis une chanteuse de star academie"));
    lc.push_back(Candidat("Melania Trump", 38, "je suis la futur first lady des USA"));
    lc.push_back(Candidat("Maria Carrey", 39, "je suis une chanteuse qui s'egare"));
    lc.push_back(Candidat("Pamela anderson", 48, "je suis une actrice age mais pulpeuse"));
    
    Publique p(20);
    Jury j("Benoit");
    Mentor m("nana");

	
}