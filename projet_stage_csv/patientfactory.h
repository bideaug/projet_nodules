#pragma once

#include <vector>
#include <string>

#include <patient.h>

//Création d'une structure
struct CTIndexes
{
    int date, dct, dsol, ct_density, sol_density;

    CTIndexes(int date, int dct, int dsol, int ct_density, int sol_density);
};

class PatientFactory
{
public:
    //Methode de construction d'un patient
    Patient create_from_strings(std::vector<std::string> strings);

    //Methode de création d'un vecteur de ctscan d'un patient
    std::vector<CTScan> create_ctscans_from_strings(std::vector<std::string> strings);

    //Methode qui renvoi une valeur pour si la densité vaut "na", "" ou " " dans le fichier CSV
    std::string Is_valid_density(std::string density);

private:
    //vecteur de CTIndexes qui contient les clés pour accéder aux bonnes colones dans le fichier CSV
    std::vector<CTIndexes> all_ctindexes;

public:
    //Constructeur vide
    PatientFactory();
};
