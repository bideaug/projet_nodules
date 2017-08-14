#pragma once

#include <string>
#include <vector>

class CSV
{
public:
    //Renvoi un vector rempli de vector rempli par parse_from_line
    static std::vector<std::vector<std::string>> parse_from_file(std::string file_path);

    //Renvoi un vector ou chaque cas à une entré du fichier CSV
    static std::vector<std::string> parse_from_line(std::string line);

private:
    //Constructeur vide
    CSV();
};
