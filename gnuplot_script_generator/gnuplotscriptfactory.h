#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class GnuPlotScriptFactory
{
public:
    bool plotting_DCVD = false;
    bool plotting_DCT = true;
    bool plotting_DSOL = false;

public:
    GnuPlotScriptFactory();
    void generate_script_from_files(std::string folder_path, std::string output_file_path);

private:
    std::string get_plot_from_file(std::string file_path);

    std::string dct_plot(std::string file_path);
    std::string dcvd_plot(std::string file_path);
    std::string dsol_plot(std::string file_path);

    std::string get_plot_head();
    std::string generic_plot(std::string file_path);
    std::string get_plot_title(std::string file_path);

    std::string get_head();
    std::string get_tail();

private:
    int plot_amount;
};
