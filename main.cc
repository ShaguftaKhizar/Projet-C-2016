#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <map>

#include "Team.hh"
#include "Victim.hh"
#include "Killer.hh"
#include "Jury_Team.hh"
#include "ProductionHouseTeam.hh"
#include "ProMember.hh"
#include "ProductionHouse.hh"

#include "Electeur.hh"
#include "Jury.hh"
#include "Mentor.hh"
#include "Publique.hh"
#include "Candidat.hh"
#include "Task.hh"
#include "number.hh"

using namespace std;

int main()
{
    srand(time(NULL));

    /* Nos candidats : */
    vector<Candidat> vc;

    vc.push_back(Candidat("Vanessa Paradis", 45, "je suis une chanteuse de renomme mondiale"));
    vc.push_back(Candidat("Maite", 60, "je suis ronde et enjoue"));
    vc.push_back(Candidat("Kate Moss", 30, "je suis un mannequin de renomme mondiale"));
    vc.push_back(Candidat("Ashweria Rai", 43, "je suis une ancienne miss monde"));
    vc.push_back(Candidat("Keira Knightley", 33, "je suis une actrice de renomme mondiale"));
    vc.push_back(Candidat("Mimie Maty", 46, "je suis une actrice de petite taille"));
    vc.push_back(Candidat("Taylor Swift", 26, "je suis une chanteuse tres talentueuse"));
    vc.push_back(Candidat("Selena Gomez", 23, "je suis une ancienne actrice Disney"));
    vc.push_back(Candidat("Ailee", 28, "je suis une celebre chanteuse corenne"));
    vc.push_back(Candidat("Magalie Vae", 34, "je suis une chanteuse de star academie"));
    vc.push_back(Candidat("Melania Trump", 38, "je suis la futur first lady des USA"));
    vc.push_back(Candidat("Maria Carrey", 39, "je suis une chanteuse qui s'egare"));
    vc.push_back(Candidat("Pamela anderson", 48, "je suis une actrice age mais pulpeuse"));

    /* Nos Jurys : */
   vector<Jury> vj;

    vj.push_back(Jury("Jean Paul Gautier"));
    vj.push_back(Jury("Yves Saint Laurent"));
    vj.push_back(Jury("Coco channel"));
    vj.push_back(Jury("MPokora"));
    vj.push_back(Jury("Tal"));
    vj.push_back(Jury("Nelson Mandela"));

    /* Nos Mentors : */
    vector<Mentor> vm;

    vm.push_back(Mentor("Tran Mai"));
    vm.push_back(Mentor("Aminata Dialo"));

    /* Notre publiques : */
    vector<Publique> vpub;
    vpub.push_back(Publique(80));
    vpub.push_back(Publique(50));
    vpub.push_back(Publique(10));

    /* Nos professionnels : */
    vector<ProMember> vp;

    vp.push_back(ProMember("Riberry", "Footballeur"));
    vp.push_back(ProMember("Freddy", "Ingénieur"));
    vp.push_back(ProMember("Shym", "Chanteuse"));
    vp.push_back(ProMember("Enjoyphoenix", "Youtubeuse"));
    vp.push_back(ProMember("Hanouna", "Presentateur"));
    vp.push_back(ProMember("Poutine", "President"));

    /* Notre maison de production : */
    ProductionHouseTeam<ProMember> pro(30, vp.size(), vp);
    vector<ProductionHouseTeam<ProMember>> pr;
    pr.push_back(pro);
    ProductionHouse p(vm, vpub, vj, vc, pr);

    string s ;

    s += "****************************************************\n";
    s += "**** BIENVENUE AU CONCOURS DE MISS EISE 2017 *******\n";
    s += "****************************************************\n";

    cout << s << endl;

    cout << "**** PLACE AU JEU ! ******\n" << endl;

    while(p.gameState() == 0)
    {
        p.chooseTask();
    }

    cout << "**** ET LE MOMENT TANT ATTENDU : LA FINALE ! ******\n" << endl;
    p.final();

}
