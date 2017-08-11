#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "patient.h"

class Writer
{
public:
    //static void to_file(std::string file_name, std::vector<CTScanAppointment>);
    static void writting(std::string file_name, std::vector<CTScanAppointment> data_to_write);

public:
    Writer();
};
