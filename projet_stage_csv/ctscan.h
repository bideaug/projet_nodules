#pragma once

#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>

class CTScan
{
public:
    //Variable boost venant de la librairie boost
    boost::gregorian::date date;
    //string de la date
    std::string sdate;

    float DCT;              //Diamètre taille total
    float DSOL;             //Diamètre taille composante solide
    float DCVD();           //Diamètre taille composante verre dépoli
    float ct_density;       //Densité de la tout le nodule
    float sol_density;      //Densité de la composante solide

public:
    //Renvoi une chaine de caractère (string) avec les attributs intéressant de CTScan
    std::string to_string();
    //Renvoi une chaine de caractère avec le bon format pour que les données puissent être exploité avec gnuplot
    std::string Result_of_scan();

public:
    //Constructeur vide
    CTScan();
};
