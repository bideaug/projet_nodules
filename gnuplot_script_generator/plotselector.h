#pragma once
#include <string>

class plotselector
{
private:
    std::string defaultchoice = "sizeplot";
public:
    static std::string Userchoice();
public:
    plotselector();
};
