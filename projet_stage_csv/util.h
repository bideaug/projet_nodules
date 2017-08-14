#pragma once

#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>

//Cette classe contient des éléments utils qui n'ont pas vocation à être instancés mais qui sont pratique

class Util
{
public:
    //Methode qui convertie la date pour pouvoir en extraire facilement l'écart en nombre de jours après
    static boost::gregorian::date string_to_date(std::string str);

    //Methode qui convertie les float en string
    static std::string Convertfloat2string(double number);

private:
    //Constructeur vide
    Util();
};
