#include <iostream>
#include <string>
#include <vector>

#include "fetchingpatientdata.h"
#include "patient.h"

using namespace std;

void FetchingPatientData::printpatientinfo(int patientid, std::vector<Patient> p)
{
    cout << p[patientid].to_string() << endl;
}

int FetchingPatientData::whichpatient()
{
    cout << "De quel patient voulez vous les informations ? (entre 1 et 63) : \n";
    int patientid;
    cin >> patientid;
    return patientid - 1;
}

void FetchingPatientData::givinginformations(vector<Patient> p)
{
    bool continuer = true;
    while (continuer)
    {
        continuer = wantedinformation();
        if (continuer)
        {
            printpatientinfo(whichpatient(),p);
        }
    }
}

bool FetchingPatientData::wantedinformation()
{
    string answer;
    cout << "Voulez vous des informations sur un patient ? (Y or n) : \n";
    cin >> answer;
    if (answer == "Y" || answer == "y" || answer == "o" || answer == "O" || answer == " ")
    {
        return true;
    }
    else
    {
        return false;
    }
}

FetchingPatientData::FetchingPatientData()
{

}

