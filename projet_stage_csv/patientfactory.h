#pragma once

#include <vector>
#include <string>

#include <patient.h>

struct CTIndexes
{
    int date, dct, dsol;

    CTIndexes(int date, int dct, int dsol);
};

class PatientFactory
{
public:
    PatientFactory();

    Patient create_from_strings(std::vector<std::string> strings);

    std::vector<CTScan> create_ctscans_from_strings(std::vector<std::string> strings);

private:
    std::vector<CTIndexes> all_ctindexes;
};
