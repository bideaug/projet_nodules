#include "patientfactory.h"

#include <util.h>
#include <iostream>

using namespace std;

CTIndexes::CTIndexes(int date, int dct, int dsol)
{
    this->date = date;
    this->dct = dct;
    this->dsol = dsol;
}

PatientFactory::PatientFactory()
{
    CTIndexes ct1(18, 59, 60),
              ct2(22, 73, 74),
              ct3(26, 87, 88),
              ct4(30, 101, 102),
              ct5(34, 115, 116),
              ct6(38, 129, 130),
              ct7(42, 143, 144),
              ct8(46, 157, 158),
              ct9(50, 171, 172);

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
    if(strings.size() < 173)
    {
        cout << "error : vector is too small" << endl;
        return p;
    }

    p.id = stoi(strings[0]);
    p.age = stoi(strings[2]);
    p.genre = strings[3];
    p.scans = create_ctscans_from_strings(strings);
    return p;
}

std::vector<CTScan> PatientFactory::create_ctscans_from_strings(std::vector<string> strings)
{
    vector<CTScan> ctscans;
    if(strings.size() < 173)
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
        if(date != "" && date != "na" && date != " ")
        {
            scan.date = Util::string_to_date(date);
            scan.sdate = date;
            scan.DCT = stof(dct);
            scan.DSOL = stof(dsol);
            ctscans.push_back(scan);
        }
    }

    return ctscans;
}
