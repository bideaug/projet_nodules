#include "ctscan.h"
#include <string>
#include <util.h>

using namespace std;

CTScan::CTScan()
{

}

float CTScan::DCVD()
{
    return DCT - DSOL;
}

string CTScan::to_string()
{
    string str;
    str += "Date du CTscan : ";
    str += std::to_string(date.day()) + "/" + std::to_string(date.month()) + "/" + std::to_string(date.year());
    str += " | DCT:";
    //str += sdate;
    //str += " ";
    //str += Util::reduce_to_precision(DCT, 4);
    str += Util::Convertfloat2string(DCT);
    str += " | Dsol:";
    //str += Util::reduce_to_precision(DSOL, 4);
    str += Util::Convertfloat2string(DSOL);
    str += " | DCVD:";
    //str += Util::reduce_to_precision(DCVD(), 4);
    str += Util::Convertfloat2string(DCVD());
    str += " | DensityCT:";
    str += Util::Convertfloat2string(ct_density);
    str += "| DensitySOL:";
    str += Util::Convertfloat2string(sol_density);
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
    str += " ";
    str += Util::Convertfloat2string(ct_density);
    str += " ";
    str += Util::Convertfloat2string(sol_density);
    return str;
}
