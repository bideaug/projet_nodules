#include <iostream>
#include <gnuplotscriptfactory.h>
#include "plotselector.h"

using namespace std;

int main()
{
    string input_folder = "./data_of_patients/";
    string output_file = "gnuplot.cmd";
    GnuPlotScriptFactory script_factory;
    script_factory.generate_script_from_files(input_folder, output_file);
    return 0;
}
