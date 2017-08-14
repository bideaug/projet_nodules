#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "patient.h"

class Writer
{
public:
    //Methode qui ecrit les données formatées dans le fichier de commande gnuplot.cmd
    static void writting(std::string file_name, std::vector<CTScanAppointment> data_to_write);

public:
    Writer();
};
