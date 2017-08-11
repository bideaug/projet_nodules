#pragma once

#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>

class Util
{
public:
    static boost::gregorian::date string_to_date(std::string str);

    static double reduce_to_precision(double value, double precision);

    static std::string Convertfloat2string(float number);
private:
    Util();
};
