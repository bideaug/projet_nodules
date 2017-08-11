#include "ctscan.h"
#include <string>
#include <util.h>

using namespace std;

//Constructeur de la class CTScan
CTScan::CTScan()
{

}

//Methode de CTScan qui renvoi la différences entre la composante solide et la composante verre dépoli
float CTScan::DCVD()
{
    return DCT - DSOL;
}

//Methode to_string qui renvoi un string avec les attributs de la class CTScan
string CTScan::to_string()
{
    string str;
    str += std::to_string(date.day()) + "/" + std::to_string(date.month()) + "/" + std::to_string(date.year());
    str += " ";
    str += sdate;
    str += " ";
    //str += Util::reduce_to_precision(DCT, 4);
    str += Util::Convertfloat2string(DCT);
    str += " ";
    //str += Util::reduce_to_precision(DSOL, 4);
    str += Util::Convertfloat2string(DSOL);
    str += " ";
    //str += Util::reduce_to_precision(DCVD(), 4);
    str += Util::Convertfloat2string(DCVD());
    str += " ";
    return str;
}

string CTScan::Result_of_scan()
{
    string str;
    str += Util::Convertfloat2string(DCT);
    str += " ";
    str += Util::Convertfloat2string(DSOL);
    str += " ";
    str += Util::Convertfloat2string(DCVD());
    return str;
}
