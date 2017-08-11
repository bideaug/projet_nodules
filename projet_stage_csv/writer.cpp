#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "writer.h"
#include "patient.h"

using namespace std;

void Writer::writting(string file_name, vector<CTScanAppointment> data_to_write)
{
    ofstream fichier(file_name, ios::out);
    for (CTScanAppointment element : data_to_write)
    {
        fichier << "" << element.gnuplot_formated_data() << "\n";

    }
    fichier.close();
}

Writer::Writer() {}
