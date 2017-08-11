#pragma once

#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>

class CTScan
{
public:
    CTScan();

    boost::gregorian::date date;
    std::string sdate;
    float DCT;
    float DSOL;
    float DCVD();

    std::string to_string();
    std::string Result_of_scan();
};
