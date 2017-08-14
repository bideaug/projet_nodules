#pragma once

#include <vector>
#include <utility>
#include <string>
#include <ctscan.h>

class CTScanAppointment : public CTScan
{
public:
    //Methode qui récupère les données intéressantes dans le CTScan
    static CTScanAppointment from_ctscan(CTScan ctscan);

    //Methode qui afficher les données d'un CTScan
    std::string to_string();

    //Methode qui formate les données pour gnuplot
    std::string gnuplot_formated_data();

public:
    //Variable qui garde en mémoire le nombre de jours depuis le premier scan
    int days_since_first_scan;

public:
    //Constructeur vide
    CTScanAppointment();
};

class Patient
{
public:
    //Formate les données pour c
    std::vector<CTScanAppointment> get_appointments();

    //Methode qui renvoi une chaine de caractère avec les paramètres intéressants d'un patient
    std::string to_string();

public:
    int id;//id du patient
    int age;//age du patient
    std::string genre;//sexe du patient
    std::string EGFRmutation;//mutation de type EGFR (récupère l'entré du tableau CSV)
    std::string KRASmutation;//mutation de type KRAS (récupère l'entré du tableau CSV)
    std::string ALKmutation;//mutation de type ALK (récupère l'entré du tableau CSV)
    std::vector<CTScan> scans; //vecteur de scans

public:
    //Constructeur vide
    Patient();
};
