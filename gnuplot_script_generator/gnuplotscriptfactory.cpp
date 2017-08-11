#include "gnuplotscriptfactory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>

using namespace std;

GnuPlotScriptFactory::GnuPlotScriptFactory() { }

void GnuPlotScriptFactory::generate_script_from_files(string input_folder_path, string output_file_path)
{
    plot_amount = 0;
    ofstream fichier(output_file_path, ios::out);
    fichier << get_head();

    for (auto & p : boost::filesystem::directory_iterator(input_folder_path))
    {
        if(boost::filesystem::is_directory(p.status())) { continue; }
        string file_path = p.path().string();
        if(boost::algorithm::ends_with(file_path, ".dat"))
        {
            fichier << get_plot_from_file(file_path) << endl;
        }
    }

    fichier << get_tail();
}

string GnuPlotScriptFactory::get_plot_from_file(string file_path)
{
    string plot;
    if (plotting_DCT)  { plot += dct_plot(file_path); }
    if (plotting_DCVD) { plot += dcvd_plot(file_path); }
    if (plotting_DSOL) { plot += dsol_plot(file_path); }
    return plot;
}

string GnuPlotScriptFactory::dct_plot(string file_path)
{
    //return generic_plot(file_path) + " 1:2 with lines title \"" + get_plot_title(file_path) + " DCT\"\n";
    return generic_plot(file_path) + " 1:2 with lines notitle\"";// + get_plot_title(file_path) + " DCT\"\n";
}

string GnuPlotScriptFactory::dcvd_plot(string file_path)
{
    return generic_plot(file_path) + " 1:4 with lines title \"" + get_plot_title(file_path) + " DCVD\"\n";
}

string GnuPlotScriptFactory::dsol_plot(string file_path)
{
    return generic_plot(file_path) + " 1:3 with lines title \"" + get_plot_title(file_path) + " DSOL\"\n";
}

string GnuPlotScriptFactory::get_plot_head()
{
    plot_amount++;
    if(plot_amount > 1) { return "replot"; }
    else { return "plot"; }
}

string GnuPlotScriptFactory::generic_plot(string file_path)
{
    string plot;
    plot += get_plot_head();
    plot += " \"" + file_path + "\" using";
    return plot;
}

string GnuPlotScriptFactory::get_plot_title(string file_path)
{
    int slash_pos = file_path.find("/");
    int period_pos = file_path.find(".");
    string patient_number = file_path.substr(slash_pos + 1, period_pos - slash_pos - 1);

    return "patient " + patient_number;
}

string GnuPlotScriptFactory::get_head()
{
    string head;
    head += "set title \"Evolution de la taille des nodules en fonction du temps\"\n";
    head += "set xlabel \"jours\"\n";
    head += "set ylabel \"taille du nodule\"\n";
    head += "set grid\n";
    return head;
}

string GnuPlotScriptFactory::get_tail()
{
    string tail;
    tail += "set terminal png\n";
    tail += "set output \"output.png\"\n";
    tail += "replot\n";
    tail += "set terminal x11\n";
    tail += "pause -1 \"appuyez sur une touche pour continuer\"\n";
    return tail;
}
