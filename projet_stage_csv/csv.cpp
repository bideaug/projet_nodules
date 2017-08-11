#include "csv.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<string>> CSV::parse_from_file(std::string file_path)
{
    vector<vector<string>> res;
    ifstream file(file_path);
    string line;
    while (std::getline(file, line))
    {
        res.push_back(parse_from_line(line));
    }
    return res;
}

std::vector<string> CSV::parse_from_line(string line)
{
    vector<string> res;
    std::stringstream ss(line);
    while( ss.good() )
    {
        string substr;
        getline( ss, substr, ',' );
        res.push_back( substr );
    }

    return res;
}

CSV::CSV() { }
