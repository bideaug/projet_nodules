#include <iostream>
#include <gnuplotscriptfactory.h>

using namespace std;

int main()
{
    std::string input_folder = "./data_of_patients/";
    std::string output_file = "gnuplot.cmd";
    GnuPlotScriptFactory script_factory;
    script_factory.generate_script_from_files(input_folder, output_file);
    return 0;
}
