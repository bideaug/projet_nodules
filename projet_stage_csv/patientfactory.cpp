#include "patientfactory.h"

#include <util.h>
#include <iostream>

using namespace std;

CTIndexes::CTIndexes(int date, int dct, int dsol, int ct_density, int sol_density)
{
    this->date = date;
    this->dct = dct;
    this->dsol = dsol;
    this->ct_density = ct_density;
    this->sol_density = sol_density;
}

PatientFactory::PatientFactory()
{
    CTIndexes ct1(18, 59, 60, 65, 66),
              ct2(22, 73, 74, 79, 80),
              ct3(26, 87, 88, 93, 94),
              ct4(30, 101, 102, 107, 108),
              ct5(34, 115, 116, 121, 122),
              ct6(38, 129, 130, 135, 136),
              ct7(42, 143, 144, 149, 150),
              ct8(46, 157, 158, 163, 164),
              ct9(50, 171, 172, 177, 178);

    all_ctindexes.push_back(ct1);
    all_ctindexes.push_back(ct2);
    all_ctindexes.push_back(ct3);
    all_ctindexes.push_back(ct4);
    all_ctindexes.push_back(ct5);
    all_ctindexes.push_back(ct6);
    all_ctindexes.push_back(ct7);
    all_ctindexes.push_back(ct8);
    all_ctindexes.push_back(ct9);
}

Patient PatientFactory::create_from_strings(std::vector<std::string> strings)
{
    Patient p;
    if(strings.size() < 196)
    {
        cout << "error : vector is too small" << endl;
        return p;
    }

    p.id = stoi(strings[0]);
    p.age = stoi(strings[2]);
    p.genre = strings[3];
    p.EGFRmutation = strings[193];
    p.KRASmutation = strings[194];
    p.ALKmutation = strings[195];
    p.scans = create_ctscans_from_strings(strings);
    return p;
}

std::vector<CTScan> PatientFactory::create_ctscans_from_strings(std::vector<string> strings)
{
    vector<CTScan> ctscans;
    if(strings.size() < 196)
    {
        cout << "error : vector is too small" << endl;
        return ctscans;
    }

    for(CTIndexes ctindexes : all_ctindexes)
    {
        CTScan scan;
        string date = strings[ctindexes.date];
        string dct = strings[ctindexes.dct];
        string dsol = strings[ctindexes.dsol];
        string ct_density = strings[ctindexes.ct_density];
        string sol_density = strings[ctindexes.sol_density];
        if(date != "" && date != "na" && date != " ")
        {
            scan.date = Util::string_to_date(date);
            scan.sdate = date;
            scan.DCT = stof(dct);
            scan.DSOL = stof(dsol);
            scan.ct_density = stof(Is_valid_density(ct_density));
            scan.sol_density = stof(Is_valid_density(sol_density));
            ctscans.push_back(scan);
        }
    }
    return ctscans;
}

string PatientFactory::Is_valid_density(string density)
{
    if (density != "" && density != "na" && density != " "){return density;}
    else {return "0.";}
}

