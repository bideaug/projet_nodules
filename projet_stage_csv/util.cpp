#include "util.h"
#include <math.h>

#include <sstream>

using namespace std;


using namespace boost::gregorian;

date Util::string_to_date(string str)
{
    vector<int> values;
    std::stringstream ss(str);
    while( ss.good() )
    {
        string substr;
        getline( ss, substr, '/' );
        values.push_back( stoi(substr) );
    }
    return date(values[2], values[0], values[1]);
}

string Util::Convertfloat2string (double number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

Util::Util()
{

}
