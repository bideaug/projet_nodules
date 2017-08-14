#include "gnuplotscriptfactory.h"
#include "plotselector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>

using namespace std;

GnuPlotScriptFactory::GnuPlotScriptFactory() { }

void GnuPlotScriptFactory::setplotparameters()
{
    string plottype = plotselector::Userchoice();
    if (plottype == "sizeplot")
    {
        plotting_DCT = parameterfiller("Voulez vous plotter la taille totale ? ");
        plotting_DCVD = parameterfiller("Voulez vous plotter la composante verre dépoli ? ");
        plotting_DSOL = parameterfiller("Voulez vous plotter la composante solide ? ");
        plotting_density = false;
    }
    else
    {
        plotting_density = true;
        plotting_DCT = false;
        plotting_DCVD = false;
        plotting_DSOL = false;
    }
    display_legend = parameterfiller("Voulez vous afficher les legendes ? ");
}

bool GnuPlotScriptFactory::parameterfiller(string question)
{
    cout << question << " Y or y : \n" << endl;
    string reponse = "";
    cin >> reponse;
    if (reponse == "Y" || reponse == "y" || reponse == "O" || reponse == "o")
    {
        return true;
    }
    else
    {
        return false;
    }
}



void GnuPlotScriptFactory::generate_script_from_files(string input_folder_path, string output_file_path)
{
    plot_amount = 0;
    setplotparameters();
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
    if (plotting_density) {plot += density_ct_plot(file_path);}
    if (plotting_density) {plot += density_sol_plot(file_path);}
    return plot;
}

string GnuPlotScriptFactory::dct_plot(string file_path)
{
    //return generic_plot(file_path) + " 1:2 with lines title \"" + get_plot_title(file_path) + " DCT\"\n";
    //return generic_plot(file_path) + " 1:2 with lines notitle\"";// + get_plot_title(file_path) + " DCT\"\n";
    return generic_plot(file_path) + " 1:2 with lines" + get_legend(file_path, " DCT\"\n");
}

string GnuPlotScriptFactory::dcvd_plot(string file_path)
{
    //return generic_plot(file_path) + " 1:4 with lines title \"" + get_plot_title(file_path) + " DCVD\"\n";
    return generic_plot(file_path) + " 1:4 with lines" + get_legend(file_path, " DCVD\"\n");
}

string GnuPlotScriptFactory::dsol_plot(string file_path)
{
    //return generic_plot(file_path) + " 1:3 with lines title \"" + get_plot_title(file_path) + " DSOL\"\n";
    return generic_plot(file_path) + " 1:3 with lines" + get_legend(file_path, " DSOL\"\n");
}

string GnuPlotScriptFactory::density_ct_plot(string file_path)
{
    return generic_plot(file_path) + " 2:4 with lines" + get_legend(file_path, " density CT / diameter\"\n");
    //return generic_plot(file_path) + " 2:4 with lines title \"" + get_plot_title(file_path) + " density CT / diameter\"\n";
}

string GnuPlotScriptFactory::density_sol_plot(string file_path)
{
    return generic_plot(file_path) + " 3:5 with lines" + get_legend(file_path, " density SOL / diameter\"\n");
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

string GnuPlotScriptFactory::get_legend(string file_path, string ending)
{
    if (display_legend)
    {
        return " title \" " + get_plot_title(file_path) + ending;
    }
    else
    {
        return " notitle \n";
    }
}

string GnuPlotScriptFactory::get_head()
{
    string title = "Evolution de la ";
    string title_ending = "";
    string xlabel = "";
    string ylabel = "";
    if (plotting_density)
    {
        title += "densité";
        title_ending = "diamètre";
        ylabel += "diamètre";
        xlabel += "densité";
    }
    else
    {
        title += "taille";
        title_ending = "temps";
        ylabel += "taille";
        xlabel += "jours";
    }
    string head;
    head += "set title \"" + title + " des nodules en fonction du " + title_ending + "\"\n";
    head += "set xlabel \"" + xlabel + "\"\n";
    head += "set ylabel \"" + ylabel + "\"\n";
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
