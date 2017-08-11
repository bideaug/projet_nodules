#pragma once

#include <vector>
#include <utility>
#include <string>
#include <ctscan.h>

class CTScanAppointment : public CTScan
{
public:
    CTScanAppointment();

    static CTScanAppointment from_ctscan(CTScan ctscan);

    std::string to_string();

    std::string gnuplot_formated_data();
public:
    int days_since_first_scan;
};

class Patient
{
public:
    Patient();

    std::vector<CTScanAppointment> get_appointments();

    std::string to_string();

public:
    int id;
    int age;
    std::string genre;
    std::vector<CTScan> scans;
};
