#pragma once
#include "patient.h"

class FetchingPatientData
{

public:
    //Methode qui afficher les informations pertinantes (issues d'un vecteur de patient) sur le patient d'id patientid
    static void printpatientinfo(int patientid, std::vector<Patient> p);
    //Methode qui demande à l'utilisateur s'il veut afficher des données
    static bool wantedinformation();
    //Methode qui demande de quel patient on veut avoir les données
    static int whichpatient();
    //methode qui afficher les informations demandées
    static void givinginformations(std::vector<Patient> p);

public:
    //Constructeur vide
    FetchingPatientData();
};
