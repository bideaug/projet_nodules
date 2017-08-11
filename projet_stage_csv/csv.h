#pragma once

#include <string>
#include <vector>

class CSV
{
public:
    static std::vector<std::vector<std::string>> parse_from_file(std::string file_path);

    static std::vector<std::string> parse_from_line(std::string line);

private:
    CSV();
};
