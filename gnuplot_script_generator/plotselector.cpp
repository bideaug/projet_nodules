#include "plotselector.h"
#include <iostream>
#include <string>

using namespace std;

string plotselector::Userchoice()
{
    int choix = 0;
    cout << "Voulez vous tracer : \n 1) taille en fonction du temps\n 2) densité \n Entrer 1 ou 2 : \n";
    cin >> choix;
    if ( choix == 1 ){ return "sizeplot"; }
    else { return "densityplot"; }
}

plotselector::plotselector()
{

}
